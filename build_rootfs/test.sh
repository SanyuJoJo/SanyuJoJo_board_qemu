SHELL_FOLDER=$(cd ../.. "$(dirname "$0")";pwd)
CROSS_PREFIX=/opt/gcc-riscv64-unknown-linux-gnu/bin/riscv64-unknown-linux-gnu

if [ ! -d "$SHELL_FOLDER/output/test/rootfs" ]; then
mkdir $SHELL_FOLDER/output/test/rootfs
fi
if [ ! -d "$SHELL_FOLDER/output/test/rootfs/rootfs" ]; then
mkdir $SHELL_FOLDER/output/test/rootfs/rootfs
fi
if [ ! -d "$SHELL_FOLDER/output/test/rootfs/bootfs" ]; then
mkdir $SHELL_FOLDER/output/test/rootfs/bootfs
fi




# 编译busybox-1.33.1
if [ ! -d "$SHELL_FOLDER/output/test/busybox" ]; then  
mkdir -p $SHELL_FOLDER/output/test/busybox
fi  
cd $SHELL_FOLDER/busybox-1.33.2
make ARCH=riscv CROSS_COMPILE=$CROSS_PREFIX- sanyujojo_defconfig
make ARCH=riscv CROSS_COMPILE=$CROSS_PREFIX- -j16
make ARCH=riscv CROSS_COMPILE=$CROSS_PREFIX- install


cp -r $SHELL_FOLDER/output/busybox/* $SHELL_FOLDER/output/test/rootfs/rootfs/
mkdir $SHELL_FOLDER/output/test/rootfs/rootfs/proc
mkdir $SHELL_FOLDER/output/test/rootfs/rootfs/sys
mkdir $SHELL_FOLDER/output/test/rootfs/rootfs/dev
mkdir $SHELL_FOLDER/output/test/rootfs/rootfs/tmp

cd $SHELL_FOLDER/output/test/rootfs
if [ ! -f "$SHELL_FOLDER/output/test/rootfs/rootfs.img" ]; then
dd if=/dev/zero of=rootfs.img bs=1M count=1024
pkexec $SHELL_FOLDER/test/build_rootfs/generate_rootfs.sh $SHELL_FOLDER/output/test/rootfs/rootfs.img 
fi

cp $SHELL_FOLDER/../quard_star_tutorial-ch11/output/linux_kernel/Image $SHELL_FOLDER/output/test/rootfs/bootfs/Image
#cp $SHELL_FOLDER/output/linux_kernel/Image $SHELL_FOLDER/output/test/rootfs/bootfs/Image
cp $SHELL_FOLDER/output/test/uboot/sanyujojo_uboot.dtb $SHELL_FOLDER/output/test/rootfs/bootfs/sanyujojo.dtb
$SHELL_FOLDER/u-boot-2023.04/tools/mkimage -A riscv -O linux -T script -C none -a 0 -e 0 -n "Distro Boot Script" -d $SHELL_FOLDER/test/dts/sanyujojo_uboot.cmd $SHELL_FOLDER/output/test/rootfs/bootfs/boot.scr
pkexec $SHELL_FOLDER/test/build_rootfs/build.sh $SHELL_FOLDER/output/test/rootfs

