# 指定交叉编译工具链的路径
CROSS_COMPILE := /opt/gcc-riscv64-unknown-linux-gnu/bin/riscv64-unknown-linux-gnu-



# 指定要编译的模块文件名（例如：my_module.ko）
obj-m := edu.o
KERNELDIR ?= /code/sdb/sanyusdk/linux-5.10.42
PWD       := $(shell pwd)
all:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) ARCH=riscv CROSS_COMPILE=$(CROSS_COMPILE) modules
	${CROSS_COMPILE}gcc user_test.c -o user_test
clean:
	rm -rf *.o *~ core .depend .*.cmd *.ko *.mod.c .tmp_versions *.order *.symvers *.mod 	
	# rm -rf edu
