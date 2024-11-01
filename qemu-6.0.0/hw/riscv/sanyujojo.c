/*
 * QEMU RISC-V Quard Star Board
 *
 * Copyright (c) 2021 qiao qiming
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2 or later, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without ev
 * en the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#include "qemu/osdep.h"
#include "qemu/units.h"
#include "qemu/log.h"
#include "qemu/error-report.h"
#include "qapi/error.h"
#include "hw/boards.h"
#include "hw/loader.h"
#include "hw/sysbus.h"
#include "hw/qdev-properties.h"
#include "hw/char/serial.h"
#include "target/riscv/cpu.h"
#include "hw/riscv/riscv_hart.h"
#include "hw/riscv/sanyujojo.h"
#include "hw/riscv/boot.h"
#include "hw/riscv/numa.h"
#include "hw/intc/sifive_clint.h"
#include "hw/intc/sifive_plic.h"
#include "hw/misc/sifive_test.h"
#include "chardev/char.h"
#include "sysemu/arch_init.h"
#include "sysemu/device_tree.h"
#include "sysemu/sysemu.h"

#include "hw/pci/pci.h"
#include "hw/pci-host/gpex.h"


static const MemMapEntry virt_memmap[] = {
    [QUARD_STAR_MROM]   = { 0x00000000,        0x8000 },
    [QUARD_STAR_SRAM]   = { 0x00008000,        0x8000 },
    [SANYUJOJO_TEST]   =  { 0x00100000,        0x1000 },
    [QUARD_STAR_CLINT]  = { 0x02000000,       0x10000 },
    [SANYU_PCIE_PIO] =    { 0x03000000,       0x10000 },
    [QUARD_STAR_PLIC]   = { 0x0c000000,     0x4000000 },
    [QUARD_STAR_UART0]  = { 0x10000000,        0x1000 },
    [QUARD_STAR_UART1]  = { 0x10001000,        0x1000 },
    [QUARD_STAR_UART2]  = { 0x10002000,        0x1000 },
    [SANYUJOJO_RTC]		= { 0X10003000,		   0X1000 },
    [SANYUJOJO_I2C0]  =   { 0x10004000,        0x1000 },
    [SANYUJOJO_I2C1]  =   { 0x10005000,        0x1000 },
    [SANYUJOJO_I2C2]  =   { 0x10006000,        0x1000 },

    [SANYUJOJO_VIRTIO0] = { 0x10100000,        0x1000 }, //Eight consecutive groups
    [SANYUJOJO_VIRTIO1] = { 0x10101000,        0x1000 }, //Eight consecutive groups
    [SANYUJOJO_VIRTIO2] = { 0x10102000,        0x1000 }, //Eight consecutive groups
    [SANYUJOJO_VIRTIO3] = { 0x10103000,        0x1000 }, //Eight consecutive groups
    [SANYUJOJO_VIRTIO4] = { 0x10104000,        0x1000 }, //Eight consecutive groups
    [SANYUJOJO_VIRTIO5] = { 0x10105000,        0x1000 }, //Eight consecutive groups
    [SANYUJOJO_VIRTIO6] = { 0x10106000,        0x1000 }, //Eight consecutive groups
    [SANYUJOJO_VIRTIO7] = { 0x10107000,        0x1000 }, //Eight consecutive groups
    [QUARD_STAR_FW_CFG] = { 0x10108000,          0x18 },
    [QUARD_STAR_FLASH]  = { 0x20000000,     0x2000000 },
    /*pci*/
    [SANYU_PCIE_ECAM]   = { 0X30000000,	   0x10000000 },
    [SANYU_PCIE_MMIO]   = { 0X40000000,	   0x40000000 },
    [QUARD_STAR_DRAM]   = { 0x80000000,           0x0 },
};


/* PCIe high mmio is fixed for RV32 */
#define SANYU32_HIGH_PCIE_MMIO_BASE	0x300000000ULL
#define SANYU32_HIGH_PCIE_MMIO_SIZE	(4* GiB)


/* PCIe high mmio for RV64, size is fixed but base depends on top of RAM */
#define SANYU64_HIGH_PCIE_MMIO_SIZE  (512 * GiB)

static MemMapEntry sanyu_high_pcie_memmap;


static void quard_star_setup_rom_reset_vec(MachineState *machine, RISCVHartArrayState *harts,
                               hwaddr start_addr,
                               hwaddr rom_base, hwaddr rom_size,
                               uint64_t kernel_entry,
                               uint32_t fdt_load_addr)
{
    int i;
    uint32_t start_addr_hi32 = 0x00000000;

    if (!riscv_is_32bit(harts)) {
        start_addr_hi32 = start_addr >> 32;
    }
    /* reset vector */
    uint32_t reset_vec[10] = {
        0x00000297,                  /* 1:  auipc  t0, %pcrel_hi(fw_dyn) */
        0x02828613,                  /*     addi   a2, t0, %pcrel_lo(1b) */
        0xf1402573,                  /*     csrr   a0, mhartid  */
        0,
        0,
        0x00028067,                  /*     jr     t0 */
        start_addr,                  /* start: .dword */
        start_addr_hi32,
        fdt_load_addr,               /* fdt_laddr: .dword */
        0x00000000,
                                     /* fw_dyn: */
    };
    if (riscv_is_32bit(harts)) {
        reset_vec[3] = 0x0202a583;   /*     lw     a1, 32(t0) */
        reset_vec[4] = 0x0182a283;   /*     lw     t0, 24(t0) */
    } else {
        reset_vec[3] = 0x0202b583;   /*     ld     a1, 32(t0) */
        reset_vec[4] = 0x0182b283;   /*     ld     t0, 24(t0) */
    }

    /* copy in the reset vector in little_endian byte order */
    for (i = 0; i < ARRAY_SIZE(reset_vec); i++) {
        reset_vec[i] = cpu_to_le32(reset_vec[i]);
    }

    rom_add_blob_fixed_as("mrom.reset", reset_vec, sizeof(reset_vec),
                          rom_base, &address_space_memory);
}


static void sanyujojo_cpu_create(MachineState *machine)
{
    RISVSanyuJoJoStates *s = RISCV_VIRT_MACHINE(machine);
    RISCVHartArrayState *cpus;
    int base_hartid, hart_count;
    char  *cpus_name;


    object_initialize_child(OBJECT(machine),"r-cluster",&s->r_cluster,TYPE_CPU_CLUSTER);
    qdev_prop_set_uint32(DEVICE(&s->r_cluster),"cluster-id",0);

    object_initialize_child(OBJECT(machine),"c-cluster",&s->c_cluster,TYPE_CPU_CLUSTER);
    qdev_prop_set_uint32(DEVICE(&s->c_cluster),"cluster-id",1);

    for(int i=0;i<2;i++)
    {
        if(i < SANYUJOJO_MANAGEMENT_CPU_COUNT){
            base_hartid = 0;
            hart_count = SANYUJOJO_MANAGEMENT_CPU_COUNT;
            cpus_name=g_strdup_printf("r_cpus%d",i);
            cpus = &s->r_cpus[i];
            object_initialize_child(OBJECT(&s->r_cluster),cpus_name,cpus,TYPE_RISCV_HART_ARRAY);
        }
        else
        {
            base_hartid = SANYUJOJO_MANAGEMENT_CPU_COUNT;
            hart_count = machine->smp.cpus-SANYUJOJO_MANAGEMENT_CPU_COUNT;
            cpus_name = g_strdup_printf("c_cpus%d",i-SANYUJOJO_MANAGEMENT_CPU_COUNT);
            cpus = &s->c_cpus[i-SANYUJOJO_MANAGEMENT_CPU_COUNT];
            object_initialize_child(OBJECT(&s->c_cluster),cpus_name,cpus,TYPE_RISCV_HART_ARRAY);
        }
        g_free(cpus_name);
        object_property_set_str(OBJECT(cpus),"cpu-type",machine->cpu_type,&error_abort);
        object_property_set_int(OBJECT(cpus), "hartid-base",
                                base_hartid, &error_abort);
        object_property_set_int(OBJECT(cpus), "num-harts",
                                hart_count, &error_abort);
        object_property_set_int(OBJECT(cpus), "resetvec", 
                                virt_memmap[QUARD_STAR_MROM].base, &error_abort);
        sysbus_realize(SYS_BUS_DEVICE(cpus), &error_abort);
    }

    qdev_realize(DEVICE(&s->r_cluster), NULL, &error_abort);
    qdev_realize(DEVICE(&s->c_cluster), NULL, &error_abort);

}

static void sanyujojo_interrupt_controller_create(MachineState *machine)
{
    RISVSanyuJoJoStates *s = RISCV_VIRT_MACHINE(machine);
    size_t plic_hart_config_len;
    char *plic_hart_config;

   sifive_clint_create(
        virt_memmap[QUARD_STAR_CLINT].base,
        virt_memmap[QUARD_STAR_CLINT].size, 0, machine->smp.cpus,
        SIFIVE_SIP_BASE, SIFIVE_TIMECMP_BASE, SIFIVE_TIME_BASE,
        SIFIVE_CLINT_TIMEBASE_FREQ, true);

    plic_hart_config_len =
        (strlen(QUARD_STAR_PLIC_HART_CONFIG) + 1) * machine->smp.cpus;

    plic_hart_config = g_malloc0(plic_hart_config_len);

    for (int j = 0; j < machine->smp.cpus; j++) {
        if (j != 0) {
            strncat(plic_hart_config, ",", plic_hart_config_len);
        }
        strncat(plic_hart_config, QUARD_STAR_PLIC_HART_CONFIG,
            plic_hart_config_len);
        plic_hart_config_len -= (strlen(QUARD_STAR_PLIC_HART_CONFIG) + 1);
    }

     s->plic = sifive_plic_create(
        virt_memmap[QUARD_STAR_PLIC].base,
        plic_hart_config, 0,
        QUARD_STAR_PLIC_NUM_SOURCES,
        QUARD_STAR_PLIC_NUM_PRIORITIES,
        QUARD_STAR_PLIC_PRIORITY_BASE,
        QUARD_STAR_PLIC_PENDING_BASE,
        QUARD_STAR_PLIC_ENABLE_BASE,
        QUARD_STAR_PLIC_ENABLE_STRIDE,
        QUARD_STAR_PLIC_CONTEXT_BASE,
        QUARD_STAR_PLIC_CONTEXT_STRIDE,
        virt_memmap[QUARD_STAR_PLIC].size);
    g_free(plic_hart_config);
}

static void sanyujojo_memory_create(MachineState *machine)
{
    RISVSanyuJoJoStates *s = RISCV_VIRT_MACHINE(machine);
    MemoryRegion *system_memory = get_system_memory();
    MemoryRegion *main_mem = g_new(MemoryRegion, 1);
    MemoryRegion *sram_mem = g_new(MemoryRegion, 1);
    MemoryRegion *mask_rom = g_new(MemoryRegion, 1);

     memory_region_init_ram(main_mem, NULL, "riscv_quard_star_board.dram",
                           machine->ram_size, &error_fatal);
    memory_region_add_subregion(system_memory, virt_memmap[QUARD_STAR_DRAM].base,
        main_mem);

    memory_region_init_ram(sram_mem, NULL, "riscv_quard_star_board.sram",
                           virt_memmap[QUARD_STAR_SRAM].size, &error_fatal);
    memory_region_add_subregion(system_memory, virt_memmap[QUARD_STAR_SRAM].base,
        sram_mem);

    memory_region_init_rom(mask_rom, NULL, "riscv_quard_star_board.mrom",
                           virt_memmap[QUARD_STAR_MROM].size, &error_fatal);
    memory_region_add_subregion(system_memory, virt_memmap[QUARD_STAR_MROM].base,
                                mask_rom);

    quard_star_setup_rom_reset_vec(machine, &s->r_cpus[0], virt_memmap[QUARD_STAR_FLASH].base,
                              virt_memmap[QUARD_STAR_MROM].base,
                              virt_memmap[QUARD_STAR_MROM].size,
                              0x0, 0x0);

}
static void sanyujojo_flash_create(MachineState *machine)
{
    RISVSanyuJoJoStates *s = RISCV_VIRT_MACHINE(machine);
    MemoryRegion *system_memory = get_system_memory();
    uint64_t flash_sector_size = 256 *KiB;
    DeviceState *dev = qdev_new(TYPE_PFLASH_CFI01);

    qdev_prop_set_uint64(dev, "sector-length", flash_sector_size);
    qdev_prop_set_uint8(dev, "width", 4);
    qdev_prop_set_uint8(dev, "device-width", 2);
    qdev_prop_set_bit(dev, "big-endian", false);
    qdev_prop_set_uint16(dev, "id0", 0x89);
    qdev_prop_set_uint16(dev, "id1", 0x18);
    qdev_prop_set_uint16(dev, "id2", 0x00);
    qdev_prop_set_uint16(dev, "id3", 0x00);
    qdev_prop_set_string(dev, "name", "quard-star.flash0");

    object_property_add_child(OBJECT(s), "quard-star.flash0", OBJECT(dev));
    object_property_add_alias(OBJECT(s), "pflash0",
                              OBJECT(dev), "drive");
    
    s->flash = PFLASH_CFI01(dev);
    pflash_cfi01_legacy_drive(s->flash, drive_get(IF_PFLASH, 0, 0));
    assert(QEMU_IS_ALIGNED(virt_memmap[QUARD_STAR_FLASH].size,flash_sector_size));

    assert(virt_memmap[QUARD_STAR_FLASH].size/flash_sector_size <= UINT32_MAX);
    qdev_prop_set_uint32(dev, "num-blocks", virt_memmap[QUARD_STAR_FLASH].size / flash_sector_size);
    sysbus_realize_and_unref(SYS_BUS_DEVICE(dev), &error_fatal);

    memory_region_add_subregion(system_memory, 
                                virt_memmap[QUARD_STAR_FLASH].base,
                                sysbus_mmio_get_region(SYS_BUS_DEVICE(dev),
                                                       0));

}

static void sanyujojo_syscon_create(MachineState *machine)
{
     sifive_test_create(virt_memmap[SANYUJOJO_TEST].base);
}

static void sanyujojo_rtc_create(MachineState *machine)
{
    RISVSanyuJoJoStates *s = RISCV_VIRT_MACHINE(machine);
    //增加RTC时钟
    sysbus_create_simple("goldfish_rtc",virt_memmap[SANYUJOJO_RTC].base,
        qdev_get_gpio_in(DEVICE(s->plic),SANYUJOJO_RTC_IRQ));
	
}

static void sanyujojo_serial_create(MachineState *machine)
{
    RISVSanyuJoJoStates *s = RISCV_VIRT_MACHINE(machine);
    MemoryRegion *system_memory = get_system_memory();

    serial_mm_init(system_memory, virt_memmap[QUARD_STAR_UART0].base,
        0, qdev_get_gpio_in(DEVICE(s->plic), QUARD_STAR_UART0_IRQ), 399193,
        serial_hd(0), DEVICE_LITTLE_ENDIAN);
    serial_mm_init(system_memory, virt_memmap[QUARD_STAR_UART1].base,
        0, qdev_get_gpio_in(DEVICE(s->plic), QUARD_STAR_UART1_IRQ), 399193,
        serial_hd(1), DEVICE_LITTLE_ENDIAN);
    serial_mm_init(system_memory, virt_memmap[QUARD_STAR_UART2].base,
        0, qdev_get_gpio_in(DEVICE(s->plic), QUARD_STAR_UART2_IRQ), 399193,
        serial_hd(2), DEVICE_LITTLE_ENDIAN);
}

static void sanyujojo_i2c_create(MachineState *machine)
{
    RISVSanyuJoJoStates *s = RISCV_VIRT_MACHINE(machine);

    object_initialize_child(OBJECT(machine), "i2c0", &s->i2c[0], TYPE_IMX_I2C);
    sysbus_realize(SYS_BUS_DEVICE(&s->i2c[0]), &error_abort);
    sysbus_mmio_map(SYS_BUS_DEVICE(&s->i2c[0]), 0, 
                        virt_memmap[SANYUJOJO_I2C0].base);
    sysbus_connect_irq(SYS_BUS_DEVICE(&s->i2c[0]), 0,
                    qdev_get_gpio_in(DEVICE(s->plic), SANYUJOJO_I2C0_IRQ));

    object_initialize_child(OBJECT(machine), "i2c1", &s->i2c[1], TYPE_IMX_I2C);
    sysbus_realize(SYS_BUS_DEVICE(&s->i2c[1]), &error_abort);
    sysbus_mmio_map(SYS_BUS_DEVICE(&s->i2c[1]), 0, 
                        virt_memmap[SANYUJOJO_I2C1].base);
    sysbus_connect_irq(SYS_BUS_DEVICE(&s->i2c[1]), 0,
                    qdev_get_gpio_in(DEVICE(s->plic), SANYUJOJO_I2C1_IRQ));

    object_initialize_child(OBJECT(machine), "i2c2", &s->i2c[2], TYPE_IMX_I2C);
    sysbus_realize(SYS_BUS_DEVICE(&s->i2c[2]), &error_abort);
    sysbus_mmio_map(SYS_BUS_DEVICE(&s->i2c[2]), 0, 
                        virt_memmap[SANYUJOJO_I2C2].base);
    sysbus_connect_irq(SYS_BUS_DEVICE(&s->i2c[2]), 0,
                    qdev_get_gpio_in(DEVICE(s->plic), SANYUJOJO_I2C2_IRQ));

    s->at24c_dev = i2c_slave_new("at24c-eeprom", 0x50);
    DeviceState *dev = DEVICE(s->at24c_dev);
    qdev_prop_set_uint32(dev, "rom-size", 8*1024);
    i2c_slave_realize_and_unref(s->at24c_dev, s->i2c[0].bus, &error_abort);

    //s->wm8750_dev = i2c_slave_new(TYPE_WM8750, 0x1a);
    //i2c_slave_realize_and_unref(s->wm8750_dev, s->i2c[1].bus, &error_abort);
}

static void sanyujojo_virtio_mmio_create(MachineState *machine)
{
    RISVSanyuJoJoStates *s = RISCV_VIRT_MACHINE(machine);
    sysbus_create_simple("virtio-mmio",
            virt_memmap[SANYUJOJO_VIRTIO0].base,
            qdev_get_gpio_in(DEVICE(s->plic), SANYUJOJO_VIRTIO0_IRQ));
    sysbus_create_simple("virtio-mmio",
            virt_memmap[SANYUJOJO_VIRTIO1].base,
            qdev_get_gpio_in(DEVICE(s->plic), SANYUJOJO_VIRTIO1_IRQ));
    sysbus_create_simple("virtio-mmio",
            virt_memmap[SANYUJOJO_VIRTIO2].base,
            qdev_get_gpio_in(DEVICE(s->plic), SANYUJOJO_VIRTIO2_IRQ));
    sysbus_create_simple("virtio-mmio",
            virt_memmap[SANYUJOJO_VIRTIO3].base,
            qdev_get_gpio_in(DEVICE(s->plic), SANYUJOJO_VIRTIO3_IRQ));
    sysbus_create_simple("virtio-mmio",
            virt_memmap[SANYUJOJO_VIRTIO4].base,
            qdev_get_gpio_in(DEVICE(s->plic), SANYUJOJO_VIRTIO4_IRQ));
    sysbus_create_simple("virtio-mmio",
            virt_memmap[SANYUJOJO_VIRTIO5].base,
            qdev_get_gpio_in(DEVICE(s->plic), SANYUJOJO_VIRTIO5_IRQ));
    sysbus_create_simple("virtio-mmio",
            virt_memmap[SANYUJOJO_VIRTIO6].base,
            qdev_get_gpio_in(DEVICE(s->plic), SANYUJOJO_VIRTIO6_IRQ));
    sysbus_create_simple("virtio-mmio",
            virt_memmap[SANYUJOJO_VIRTIO7].base,
            qdev_get_gpio_in(DEVICE(s->plic), SANYUJOJO_VIRTIO7_IRQ));
}

static void sanyujojo_fw_cfg_create(MachineState *machine)
{
    RISVSanyuJoJoStates *s = RISCV_VIRT_MACHINE(machine);
    s->fw_cfg = fw_cfg_init_mem_wide(virt_memmap[QUARD_STAR_FW_CFG].base + 8, 
                                     virt_memmap[QUARD_STAR_FW_CFG].base,  8, 
                                     virt_memmap[QUARD_STAR_FW_CFG].base + 16,
                                     &address_space_memory);
    fw_cfg_add_i16(s->fw_cfg, FW_CFG_NB_CPUS, (uint16_t)machine->smp.cpus);
    rom_set_fw(s->fw_cfg);
}

static void sanyujojo_pci_create(MachineState *machine)
{

    RISVSanyuJoJoStates *s = RISCV_VIRT_MACHINE(machine);
    MemoryRegion *system_memory = get_system_memory();
    DeviceState *dev;
    MemoryRegion *ecam_alias, *ecam_reg;
    MemoryRegion *mmio_alias, *high_mmio_alias, *mmio_reg;
    qemu_irq irq;
    int i;

    if (riscv_is_32bit(&s->r_cpus[0])) {
#if HOST_LONG_BITS == 64
        // limit RAM size in a 32-bit system 
        if (machine->ram_size > 10 * GiB) {
            machine->ram_size = 10 * GiB;
            error_report("Limiting RAM size to 10 GiB");
        }
#endif
        sanyu_high_pcie_memmap.base = SANYU32_HIGH_PCIE_MMIO_BASE;
        sanyu_high_pcie_memmap.size = SANYU32_HIGH_PCIE_MMIO_SIZE;
    } else {
        sanyu_high_pcie_memmap.size = SANYU64_HIGH_PCIE_MMIO_SIZE;
        sanyu_high_pcie_memmap.base = virt_memmap[QUARD_STAR_DRAM].base + machine->ram_size;
        sanyu_high_pcie_memmap.base =
            ROUND_UP(sanyu_high_pcie_memmap.base, sanyu_high_pcie_memmap.size);

    }


                                          
    dev = qdev_new(TYPE_GPEX_HOST);

    sysbus_realize_and_unref(SYS_BUS_DEVICE(dev), &error_fatal);

    ecam_alias = g_new0(MemoryRegion, 1);
    ecam_reg = sysbus_mmio_get_region(SYS_BUS_DEVICE(dev), 0);
    memory_region_init_alias(ecam_alias, OBJECT(dev), "pcie-ecam",
                             ecam_reg, 0, virt_memmap[SANYU_PCIE_ECAM].size);
    memory_region_add_subregion(system_memory, virt_memmap[SANYU_PCIE_ECAM].base, ecam_alias);

    mmio_alias = g_new0(MemoryRegion, 1);
    mmio_reg = sysbus_mmio_get_region(SYS_BUS_DEVICE(dev), 1);
    memory_region_init_alias(mmio_alias, OBJECT(dev), "pcie-mmio",
                             mmio_reg, virt_memmap[SANYU_PCIE_MMIO].base, virt_memmap[SANYU_PCIE_MMIO].size);
    memory_region_add_subregion(system_memory, virt_memmap[SANYU_PCIE_MMIO].base, mmio_alias);

    /* Map high MMIO space */
    high_mmio_alias = g_new0(MemoryRegion, 1);
    memory_region_init_alias(high_mmio_alias, OBJECT(dev), "pcie-mmio-high",
                             mmio_reg, sanyu_high_pcie_memmap.base, sanyu_high_pcie_memmap.size);
    memory_region_add_subregion(system_memory, sanyu_high_pcie_memmap.base,
                                high_mmio_alias);

    sysbus_mmio_map(SYS_BUS_DEVICE(dev), 2, virt_memmap[SANYU_PCIE_PIO].base);

    for (i = 0; i < GPEX_NUM_IRQS; i++) {
        irq = qdev_get_gpio_in(s->plic, SANYU_PCIE_IRQ + i);

        sysbus_connect_irq(SYS_BUS_DEVICE(dev), i, irq);
        gpex_set_irq_num(GPEX_HOST(dev), i, SANYU_PCIE_IRQ + i);
    }
}

static void sanyu_machine_init(MachineState *machine)
{
    sanyujojo_cpu_create(machine);
    sanyujojo_interrupt_controller_create(machine);
    sanyujojo_memory_create(machine);
    sanyujojo_flash_create(machine);
    sanyujojo_syscon_create(machine);
    sanyujojo_rtc_create(machine);
    sanyujojo_serial_create(machine);
    sanyujojo_i2c_create(machine);
    //sanyujojo_pci_create(machine);

    sanyujojo_virtio_mmio_create(machine);
    sanyujojo_fw_cfg_create(machine);

}

static void sanyujojo_machine_instance_init(Object *obj)
{
}

static void sanyu_star_machine_class_init(ObjectClass *oc, void *data)
{
    MachineClass *mc = MACHINE_CLASS(oc);
    mc->desc = "RISC-V SANYUJOJO board";
    mc->init = sanyu_machine_init;
    mc->max_cpus = SANYUJOJO_MANAGEMENT_CPU_COUNT+SANYUJOJO_COMPUTE_CPU_COUNT;
    mc->min_cpus = SANYUJOJO_MANAGEMENT_CPU_COUNT+1;
    mc->default_cpus = mc->min_cpus;
    mc->default_cpu_type = TYPE_RISCV_CPU_BASE;
    mc->pci_allow_0_address = true;
    mc->possible_cpu_arch_ids = riscv_numa_possible_cpu_arch_ids;
    mc->cpu_index_to_instance_props = riscv_numa_cpu_index_to_props;
    mc->get_default_cpu_node_id = riscv_numa_get_default_cpu_node_id;
    mc->numa_mem_supported = true;
}

static const TypeInfo sanyujojo_machine_typeinfo = {
    .name       = MACHINE_TYPE_NAME("sanyujojo"),
    .parent     = TYPE_MACHINE,
    .class_init = sanyu_star_machine_class_init,
    .instance_init = sanyujojo_machine_instance_init,
    .instance_size = sizeof(RISVSanyuJoJoStates),
};

static void sanyujojo_machine_init_register_types(void)
{
    type_register_static(&sanyujojo_machine_typeinfo);
}

type_init(sanyujojo_machine_init_register_types)
