#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/pci.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/signal.h>
#include <linux/uaccess.h>
#include <linux/wait.h>
#include <linux/delay.h>

#define EDU_PRINTK(level, format, arg...) printk(level "[Kernel: %s - %d] " format, __FUNCTION__, __LINE__, ##arg)
#define EDU_ERR(format, arg...)           EDU_PRINTK(KERN_ERR, format, ##arg)
#define EDU_INFO(format, arg...)          EDU_PRINTK(KERN_INFO, format, ##arg)
#define DRIVER_NAME "qemu_edu"
/* 定义 PCI 设备 ID */
#define MY_PCI_VENDOR_ID 0x1234 /* Vendor ID */
#define MY_PCI_DEVICE_ID 0x11e8 /* Device ID */
#define MY_PCI_REVISION_ID 0X10


#define EDU_ID 0x00
#define EDU_LIVE_CHECK 0x04
#define EDU_FACT_CALC 0x08
#define EDU_STATUS 0x20
#define EDU_IRQ_STATUS 0x24
#define EDU_IRQ_RAISE 0x60
#define EDU_IRQ_ACK 0x64
#define EDU_DMA_SRC_ADDR 0x80
#define EDU_DMA_DST_ADDR 0x88
#define EDU_DMA_COUNT 0x90
#define EDU_DMA_CMD 0x98
#define EDU_BUFFER_ADDRESS 0x40000


// Custom Parameters
#define EDU_DMA_GET 0x1234

#define STATUS_COMPUTING 0x01
#define STATUS_IRQFACT 0x80

#define DMA_START 0x01
#define DMA_RAM2EDU 0x0
#define DMA_EDU2RAM 0x02
#define DMA_IRQ 0x04
#define DMA_IRQ_VALUE 0x10

#define BAR 0
#define BASEMINOR 0
#define DEVICE_COUNTS 1

struct edu_device {
    dev_t dev_num;
    struct pci_dev *pdev;
    void __iomem *mmio_base;

    struct cdev cdev;
    bool complete;
    wait_queue_head_t wait_queue;

    uint64_t dma_src_address;
    uint64_t dma_dst_address;
    uint64_t dma_count;
    void *dma_buffer;
    uint32_t dma_direction;
    dma_addr_t dma_addr;

    struct pid *user_pid;
    struct work_struct free_dma_work;
};

static struct my_pci_info{
    struct pci_dev *dev;
    void __iomem *address_io;
}pci_info;
// 定义 PCI 设备表
static const struct pci_device_id ids[] = {
    {PCI_DEVICE(MY_PCI_VENDOR_ID, MY_PCI_DEVICE_ID)},
    {0},
};
MODULE_DEVICE_TABLE(pci,ids);


static irqreturn_t my_pci_irq_handler(int irq,void *dev_id)
{
    struct my_pci_info *_pci_info=dev_id;
    iowrite32(0x1, _pci_info->address_io+ EDU_IRQ_ACK);
	
	EDU_INFO("[%s]:receive irq: %d \n",DRIVER_NAME,irq);
	
	return IRQ_HANDLED;
}
// 定义 PCI 设备的 probe 函数
int bar=0;
static int edu_probe(struct pci_dev *dev, const struct pci_device_id *id)
{

    
    int ret = 0;
    void __iomem *mmio_base;
    resource_size_t len;
	EDU_INFO("edu probe done!\n");
	
    
   // Enable the PCI device
   ret = pci_enable_device(dev);
   if(ret<0)
   {
     printk(KERN_ERR "[%s] pci_enable_device failed. \n", DRIVER_NAME);
     goto disable_device;
   }
    
     // Request MMIO/IOP resources
     if ((ret = pci_request_region(dev, bar, DRIVER_NAME)) < 0) {
        printk(KERN_ERR "[%s] pci_request_region failed. \n", DRIVER_NAME);
        goto disable_device;
    }
    
    // Set the DMA mask size
    // EDU device supports only 28 bits by default
    if ((ret = dma_set_mask_and_coherent(&(dev->dev), DMA_BIT_MASK(32)) < 0)) {
        dev_warn(&dev->dev, "[%s] No suitable DMA available\n", DRIVER_NAME);
        goto release_regions;
    }
   EDU_INFO("edu probe Map the BAR register\n");
   
   // Map the BAR register
   mmio_base = pci_iomap(dev,bar,pci_resource_len(dev,bar));
   if (!mmio_base) {
        printk(KERN_ERR "[%s] Cannot iomap BAR\n", DRIVER_NAME);
        ret = -ENOMEM;
        goto release_regions;
    }
    pci_info.address_io  = mmio_base;
    pci_info.dev=dev;
    
   // Allow device to initiate DMA operations
   pci_set_master(dev);
   
   //interrupt irq
   EDU_INFO("edu probe irq!\n");
   ret = request_irq(dev->irq,my_pci_irq_handler,IRQF_SHARED,DRIVER_NAME,&pci_info);
   EDU_INFO("edu probe interupt done! irq = %d \n",dev->irq);
   if(ret){
	EDU_INFO("request IRQ failed %d \n",dev->irq);
	goto unmap_bar;
   }
   
    // Device initialize
    // Raise interrupt after finishing factorial computation
    //iowrite32(1, pci_info.address_io + DMA_IRQ_VALUE);
   iowrite32(0x01, pci_info.address_io+ DMA_IRQ_VALUE);
   printk(KERN_INFO "[%s] probe sucessfully. \n", DRIVER_NAME);
   /*注册字符设备*/
   
   uint32_t value32_s=7;
   iowrite32(value32_s, pci_info.address_io + EDU_FACT_CALC);
   msleep(500);
    
            // Read data
            value32_s = ioread32(pci_info.address_io + EDU_FACT_CALC);
   printk(KERN_INFO "[%s] probe sucessfully. 5 value32=%d\n", DRIVER_NAME,value32_s);
  
   return 0;
  unmap_bar:
    pci_iounmap(dev, mmio_base);
release_regions:
    pci_release_regions(dev);
disable_device:
    pci_disable_device(dev);
    return ret;
}


// 定义 PCI 设备的 remove 函数
static void edu_remove(struct pci_dev *pdev)
{
     struct edu_device *edu_dev = pci_get_drvdata(pdev);

    // Free IRQ
    free_irq(pdev->irq, edu_dev);

    // Unmap BAR memory
    pci_iounmap(pdev, edu_dev->mmio_base);

    // Release PCI I/O resources
    pci_release_region(pdev, bar);
/*
    // Destroy device node /dev/edu
    device_destroy(edu_class, edu_dev->dev_num);

    // Destroy class
    class_destroy(edu_class);

    // Delete cdev
    cdev_del(&edu_dev->cdev);

    // Unregister char device region
    unregister_chrdev_region(edu_dev->dev_num, DEVICE_COUNTS);
*/
    // Disable PCI device
    pci_disable_device(pdev);

    // Free allocated device structure
    kfree(edu_dev);

    printk(KERN_INFO "[%s] removed.\n", DRIVER_NAME);
}

static struct pci_driver pci_drivers = {
		.name = DRIVER_NAME,
		.id_table = ids,
		.probe = edu_probe,
		.remove = edu_remove,
};

// 驱动的初始化函数与卸载函数
static int __init edu_init(void)
{
	EDU_INFO("edu ko init done!\n");
    int ret;
    if ((ret = pci_register_driver(&pci_drivers)) < 0) {
        printk(KERN_ERR "[%s] Init failed. \n", DRIVER_NAME);
        return ret;
    }

    printk(KERN_INFO "[%s] Init sucessfully. \n", DRIVER_NAME);
    return ret;
}

static void __exit edu_exit(void)
{
    

    /* pci注销 */
    pci_unregister_driver(&pci_drivers);

    EDU_INFO("edu ko exit done!\n");
}

// 注册驱动的初始化函数与卸载函数
module_init(edu_init);
module_exit(edu_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("sanyu");
MODULE_DESCRIPTION("edu driver");
MODULE_VERSION("1.0.0");
