#!/bin/bash
set -e

BUILD_TARGET=$1
BUILD_ROOTFS_OPT=$2

SHELL_FOLDER=$(cd "$(dirname "$0")";pwd)

CROSS_COMPILE_DIR=/opt
CROSS_PREFIX=/opt/gcc-riscv64-unknown-linux-gnu/bin/riscv64-unknown-linux-gnu
OUTPATH=$SHELL_FOLDER/output
SRCPATH=$SHELL_FOLDER

# 编译qemu
build_qemu()
{
    echo "------------------------------ 编译qemu ------------------------------"
    cd $SRCPATH/qemu-6.0.0
	if [ ! -d "$OUTPATH/qemu" ]; then  
		./configure --prefix=$OUTPATH/qemu  --target-list=riscv64-softmmu --enable-gtk  --enable-virtfs --disable-gio
		#./configure --prefix=$OUTPATH/qemu --target-list=riscv64-softmmu --enable-gtk  --enable-virtfs --disable-gio --enable-plugins --audio-drv-list=pa,alsa,sdl,oss
        #./configure --prefix=$OUTPATH/qemu --target-list=aarch64v-softmmu --enable-gtk  --enable-virtfs --disable-gio --enable-plugins --audio-drv-list=pa,alsa,sdl,oss
fi    
    make -j$PROCESSORS
    make install
    cd -
}


build_lowlevelboot()
{
    echo "-------------------------- 编译lowlevelboot --------------------------"
    if [ ! -d "$OUTPATH/lowlevelboot" ]; then  
		mkdir $OUTPATH/lowlevelboot
    fi  
    cd $SRCPATH/lowlevelboot
    # 编译汇编文件startup.s到obj文件
	$CROSS_PREFIX-gcc -x assembler-with-cpp -c startup.s -o $OUTPATH/lowlevelboot/startup.o
	# 使用链接脚本链接obj文件生成elf可执行文件
	$CROSS_PREFIX-gcc -nostartfiles -T./boot.lds -Wl,-Map=$OUTPATH/lowlevelboot/lowlevel_fw.map -Wl,--gc-sections $OUTPATH/lowlevelboot/startup.o -o $OUTPATH/lowlevelboot/lowlevel_fw.elf
	# 使用gnu工具生成原始的程序bin文件
	$CROSS_PREFIX-objcopy -O binary -S $OUTPATH/lowlevelboot/lowlevel_fw.elf $OUTPATH/lowlevelboot/lowlevel_fw.bin
	# 使用gnu工具生成反汇编文件，方便调试分析（当然我们这个代码太简单，不是很需要）
	$CROSS_PREFIX-objdump --source --demangle --disassemble --reloc --wide $OUTPATH/lowlevelboot/lowlevel_fw.elf > $OUTPATH/lowlevelboot/lowlevel_fw.lst
    cd -
}

# 编译opensbi
build_opensbi()
{
    echo "---------------------------- 编译opensbi -----------------------------"
    if [ ! -d "$OUTPATH/opensbi" ]; then  
    mkdir $OUTPATH/opensbi
    fi  
    cd $SRCPATH/opensbi-0.9
    make CROSS_COMPILE=$CROSS_PREFIX- PLATFORM=sanyujojo
	cp -r $SRCPATH/opensbi-0.9/build/platform/sanyujojo/firmware/fw_jump.bin $OUTPATH/opensbi/fw_jump.bin
	cp -r $SRCPATH/opensbi-0.9/build/platform/sanyujojo/firmware/fw_jump.elf $OUTPATH/opensbi/fw_jump.elf
	$CROSS_PREFIX-objdump --source --demangle --disassemble --reloc --wide $OUTPATH/opensbi/fw_jump.elf > $OUTPATH/opensbi/fw_jump.lst
}


build_sbi_dtb()
{
    echo "---------------------------- 生成sbi.dtb -----------------------------"
    cd $SRCPATH/dts
    #dtc -I dts -O dtb -o $OUTPATH/opensbi/sanyujojo_sbi.dtb sanyujojo_sbi.dts
    cpp -nostdinc -I include -undef -x assembler-with-cpp sanyujojo_sbi.dts > sanyujojo_sbi.dtb.dts.tmp
    dtc -i $SRCPATH/dts -I dts -O dtb -o $SHELL_FOLDER/output/opensbi/sanyujojo_sbi.dtb sanyujojo_sbi.dtb.dts.tmp 
    cd -
}

# 编译trusted_domain
build_trusted_domain()
{
    echo "------------------------- 编译trusted_domain -------------------------"
    if [ ! -d "$OUTPATH/trusted_domain" ]; then  
    mkdir $OUTPATH/trusted_domain
    fi  
    cd $SRCPATH/trusted_domain
    $CROSS_PREFIX-gcc -x assembler-with-cpp -c startup.s -o $OUTPATH/trusted_domain/startup.o
	$CROSS_PREFIX-gcc -nostartfiles -T./link.lds -Wl,-Map=$OUTPATH/trusted_domain/trusted_fw.map -Wl,--gc-sections $OUTPATH/trusted_domain/startup.o -o 	$OUTPATH/trusted_domain/trusted_fw.elf
	$CROSS_PREFIX-objcopy -O binary -S $OUTPATH/trusted_domain/trusted_fw.elf $OUTPATH/trusted_domain/trusted_fw.bin
	$CROSS_PREFIX-objdump --source --demangle --disassemble --reloc --wide $OUTPATH/trusted_domain/trusted_fw.elf > $OUTPATH/trusted_domain/trusted_fw.lst
	cd -
}

# 生成uboot.dtb
build_uboot_dtb()
{
    echo "--------------------------- 生成uboot.dtb ----------------------------"
    if [ ! -d "$SHELL_FOLDER/output/uboot" ]; then  
    mkdir $OUTPATH/uboot
    fi  
    cd $SRCPATH/dts
    cpp -nostdinc -I include -undef -x assembler-with-cpp sanyujojo_uboot.dts > sanyujojo_uboot.dtb.dts.tmp
	dtc -I dts -O dtb -o $OUTPATH/uboot/sanyujojo_uboot.dtb sanyujojo_uboot.dtb.dts.tmp 
}



# 编译uboot
build_uboot()
{
    echo "----------------------------- 编译uboot ------------------------------"
    if [ ! -d "$OUTPATH/uboot" ]; then  
    mkdir $OUTPATH/uboot
    fi  
    cd $SRCPATH/u-boot-2021.07
    make CROSS_COMPILE=/opt/gcc-riscv64-unknown-linux-gnu/bin/riscv64-unknown-linux-gnu- qemu-sanyujojo_defconfig
	#make CROSS_COMPILE=/opt/gcc-riscv64-unknown-linux-gnu/bin/riscv64-unknown-linux-gnu- -j$PROCESSORS DEVICE_TREE=../../../../output/test/uboot/sanyujojo_uboot
	make CROSS_COMPILE=/opt/gcc-riscv64-unknown-linux-gnu/bin/riscv64-unknown-linux-gnu- -j$PROCESSORS
	cp $SRCPATH/u-boot-2021.07/u-boot $OUTPATH/uboot/u-boot.elf
	cp $SRCPATH/u-boot-2021.07/u-boot.map $OUTPATH/uboot/u-boot.map
	cp $SRCPATH/u-boot-2021.07/u-boot.bin $OUTPATH/uboot/u-boot.bin
	$CROSS_PREFIX-objdump --source --demangle --disassemble --reloc --wide $OUTPATH/uboot/u-boot.elf > $OUTPATH/uboot/u-boot.lst
}


# 合成firmware固件
build_firmware()
{
    echo "--------------------------- 合成firmware固件 ---------------------------"
    if [ ! -f "$OUTPATH/lowlevelboot/lowlevel_fw.bin" ]; then  
        echo "not found lowlevelboot.bin, please ./build.sh lowlevelboot"
        exit 255
    fi
    if [ ! -f "$OUTPATH/opensbi/sanyujojo_sbi.dtb" ]; then  
        echo "not found quard_star_sbi.dtb, please ./build.sh sbi_dtb"
        exit 255
    fi
    if [ ! -f "$OUTPATH/uboot/sanyujojo_uboot.dtb" ]; then  
        echo "not found quard_star_uboot.dtb, please ./build.sh uboot_dtb"
        exit 255
    fi
    if [ ! -f "$OUTPATH/opensbi/fw_jump.bin" ]; then  
        echo "not found fw_jump.bin, please ./build.sh opensbi"
        exit 255
    fi
    if [ ! -f "$OUTPATH/trusted_domain/trusted_fw.bin" ]; then  
        echo "not found trusted_fw.bin, please ./build.sh trusted_domain"
        exit 255
    fi
    if [ ! -f "$OUTPATH/uboot/u-boot.bin" ]; then  
        echo "not found u-boot.bin, please ./build.sh uboot"
        exit 255
    fi
    if [ ! -d "$OUTPATH/fw" ]; then  
    mkdir $OUTPATH/fw
    fi  
    cd $OUTPATH/fw
    rm -rf fw.bin
    dd of=fw.bin bs=1k  count=32k if=/dev/zero
    dd of=fw.bin bs=1k conv=notrunc seek=0 if=$OUTPATH/lowlevelboot/lowlevel_fw.bin
    dd of=fw.bin bs=1k conv=notrunc seek=512 if=$OUTPATH/opensbi/sanyujojo_sbi.dtb
    dd of=fw.bin bs=1k conv=notrunc seek=1K if=$OUTPATH/uboot/sanyujojo_uboot.dtb
    dd of=fw.bin bs=1k conv=notrunc seek=2K if=$OUTPATH/opensbi/fw_jump.bin
    dd of=fw.bin bs=1k conv=notrunc seek=4K if=$OUTPATH/trusted_domain/trusted_fw.bin
    dd of=fw.bin bs=1k conv=notrunc seek=8K if=$OUTPATH/uboot/u-boot.bin
}


build_kernel()
{
    echo "-------------------------- 编译linux kernel --------------------------"
    if [ ! -d "$OUTPATH/linux_kernel" ]; then  
    mkdir $OUTPATH/linux_kernel
    fi  
    cd $SRCPATH/linux-5.10.42
    make ARCH=riscv CROSS_COMPILE=$CROSS_PREFIX- sanyujojo_defconfig
    make ARCH=riscv CROSS_COMPILE=$CROSS_PREFIX- -j16
    #make ARCH=riscv CROSS_COMPILE=$GLIB_ELF_CROSS_PREFIX- tools/perf -j$PROCESSORS
    cp $SRCPATH/linux-5.10.42/arch/riscv/boot/Image $OUTPATH/linux_kernel/Image
}

build_image()
{
	MAKE_ROOTFS_DIR=$OUTPATH/rootfs
	TARGET_ROOTFS_DIR=$MAKE_ROOTFS_DIR/rootfs
	TARGET_BOOTFS_DIR=$MAKE_ROOTFS_DIR/bootfs
	if [ ! -d "$MAKE_ROOTFS_DIR" ]; then
	mkdir $MAKE_ROOTFS_DIR
	fi
	if [ ! -d "$TARGET_ROOTFS_DIR" ]; then
	mkdir $TARGET_ROOTFS_DIR
	fi
	if [ ! -d "$TARGET_BOOTFS_DIR" ]; then
	mkdir $TARGET_BOOTFS_DIR
	fi

	cd $MAKE_ROOTFS_DIR
	
	
	if [ ! -f "$MAKE_ROOTFS_DIR/rootfs.img" ]; then
	dd if=/dev/zero of=rootfs.img bs=1M count=1024
	pkexec $SRCPATH/build_rootfs/generate_rootfs.sh $MAKE_ROOTFS_DIR/rootfs.img 
	fi
	cp $OUTPATH/linux_kernel/Image $TARGET_BOOTFS_DIR/Image
	cp $OUTPATH/uboot/sanyujojo_uboot.dtb $TARGET_BOOTFS_DIR/sanyujojo.dtb
	$SRCPATH/u-boot-2021.07/tools/mkimage -A riscv -O linux -T script -C none -a 0 -e 0 -n "Distro Boot Script" -d $SRCPATH/dts/sanyujojo_uboot.cmd $TARGET_BOOTFS_DIR/boot.scr
	
	cp -r $OUTPATH/busybox/* $TARGET_ROOTFS_DIR
	cp -r $SRCPATH/target_root_script/* $TARGET_ROOTFS_DIR
	
	# app 
	cp -r -p $SRCPATH/app/output/* $TARGET_ROOTFS_DIR
	
	if [ ! -d "$TARGET_ROOTFS_DIR/proc" ]; then  
	mkdir $TARGET_ROOTFS_DIR/proc
	fi
	if [ ! -d "$TARGET_ROOTFS_DIR/sys" ]; then  
	mkdir $TARGET_ROOTFS_DIR/sys
	fi
	if [ ! -d "$TARGET_ROOTFS_DIR/dev" ]; then  
	mkdir $TARGET_ROOTFS_DIR/dev
	fi
	if [ ! -d "$TARGET_ROOTFS_DIR/tmp" ]; then  
	mkdir $TARGET_ROOTFS_DIR/tmp
	fi
	
	if [ ! -d "$TARGET_ROOTFS_DIR/mnt" ]; then  
    mkdir $TARGET_ROOTFS_DIR/mnt
    fi
	
	if [ ! -d "$TARGET_ROOTFS_DIR/lib" ]; then  
	mkdir $TARGET_ROOTFS_DIR/lib
	cd $TARGET_ROOTFS_DIR
	ln -s ./lib ./lib64
	cd $MAKE_ROOTFS_DIR
	fi
	cp -r $CROSS_COMPILE_DIR/gcc-riscv64-unknown-linux-gnu/sysroot/lib/* $TARGET_ROOTFS_DIR/lib/
	cp -r $CROSS_COMPILE_DIR/gcc-riscv64-unknown-linux-gnu/sysroot/usr/bin/* $TARGET_ROOTFS_DIR/usr/bin/
	
	
	pkexec $SRCPATH/build_rootfs/build.sh $MAKE_ROOTFS_DIR


}

build_busybox()
{
    echo "---------------------------- 编译busybox -----------------------------"
    if [ ! -d "$OUTPATH/busybox" ]; then  
    mkdir $OUTPATH/busybox
    fi  
    cd $SRCPATH/busybox-1.33.1
    make ARCH=riscv CROSS_COMPILE=$CROSS_PREFIX- sanyujojo_defconfig
    make ARCH=riscv CROSS_COMPILE=$CROSS_PREFIX- -j$PROCESSORS
    make ARCH=riscv CROSS_COMPILE=$CROSS_PREFIX- install
}

build_app()
{
	sh $SRCPATH/app/build.sh $1
}

build_all()
{
	build_qemu
    build_lowlevelboot
    build_opensbi
    build_sbi_dtb
    build_trusted_domain
    build_uboot_dtb
    build_uboot
    build_firmware
    build_kernel
    build_busybox
    #build_app
    build_image
}

echo_usage()
{
    TARGET="qemu|mask_rom|lowlevelboot|opensbi|sbi_dtb|trusted_domain|uboot|uboot_dtb|firmware|kernel|busybox|rootfs|all"
    ROOTFS_OPT="all|bootfs"
    USAGE="usage $0 [$TARGET] [$ROOTFS_OPT]"
	echo $USAGE
}

case "$BUILD_TARGET" in
--help)
    echo_usage
	exit 0
	;;
qemu)
    build_qemu
    ;;
qemu_w64)
    build_qemu_w64
    ;;
qemu_macos)
    build_qemu_macos
    ;;
mask_rom)
    build_mask_rom
    ;;
lowlevelboot)
    build_lowlevelboot
    ;;
opensbi)
    build_opensbi
    ;;
sbi_dtb)
    build_sbi_dtb
    ;;
trusted_domain)
    build_trusted_domain
    ;;
uboot)
    build_uboot
    ;;
uboot_dtb)
    build_uboot_dtb
    ;;
firmware)
    build_firmware
    ;;
kernel)
    build_kernel
    ;;
busybox)
    build_busybox
    ;;
rootfs)
    build_rootfs
    ;;
image)
    build_image
    ;; 
app)
	build_app $2
	;;
all)
    build_all
    ;;
*)
    echo_usage
	exit 255
	;;
esac

echo "----------------------------------- 完成 -----------------------------------"
