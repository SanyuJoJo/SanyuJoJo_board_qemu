SHELL_FOLDER=$(cd "$(dirname "$0")";pwd)
CROSS_COMPILE_DIR=/opt
CROSS_PREFIX=/opt/gcc-riscv64-unknown-linux-gnu/bin/riscv64-unknown-linux-gnu
CONFIGURE=./configure



build_all()
{
	echo "----------build all-----------------"
	build_bash
	build_make
	build_ncurses
	build_sudo
	build_screenFetch
}
build_bash()
{
	echo "----------build bash-----------------"
	# 编译bash
	cd $SHELL_FOLDER/bash-5.2
	$CONFIGURE --host=riscv64 --prefix=$SHELL_FOLDER/output CXX=$CROSS_PREFIX-g++ CC=$CROSS_PREFIX-gcc 
	make -j16
	make install
}
build_make()
{
	echo "----------build make-----------------"
	# 编译make
	cd $SHELL_FOLDER/make-4.4.1
	$CONFIGURE --host=riscv64 --prefix=$SHELL_FOLDER/output CXX=$CROSS_PREFIX-g++ CC=$CROSS_PREFIX-gcc 
	make -j16
	make install
}

build_ncurses()
{
	echo "----------build ncurses-----------------"
	# 编译ncurses
	cd $SHELL_FOLDER/ncurses-6.4
	$CONFIGURE --host=riscv64 --disable-stripping CXX=$CROSS_PREFIX-g++ CC=$CROSS_PREFIX-gcc 
	make -j16
	#make install.progs
	#make install.data
}

build_sudo()
{
	# 编译sudo
	echo "----------build sudo-----------------"
	cd $SHELL_FOLDER/sudo-1.9.15p5
	$CONFIGURE --host=riscv CXX=$CROSS_PREFIX-g++ CC=$CROSS_PREFIX-gcc  --prefix=$SHELL_FOLDER/output
	make -j16
	make install-binaries
}

build_screenFetch()
{
	# 安装screenFetch
	echo "----------build screenFetch-----------------"
	cd $SHELL_FOLDER/screenFetch-3.9.1
	if [ ! -d "$SHELL_FOLDER/output/usr" ]; then  
	mkdir $SHELL_FOLDER/output/usr
	mkdir $SHELL_FOLDER/output/usr/bin
	fi  

	if [ ! -d "$SHELL_FOLDER/output/usr/bin" ]; then  
	mkdir $SHELL_FOLDER/output/usr/bin
	fi 
	cp screenfetch-dev $SHELL_FOLDER/output/usr/bin/screenfetch
}


case "$1" in
skip)
    CONFIGURE=echo
    exit 0
    ;;
bash1)
	build_bash
	exit 0
	;;
make1)
	build_make
	exit 0
	;;
ncurses)
	build_ncurses
	exit 0
	;;
sudo)
	build_sudo
	exit 0
	;;
screenFetch)
	build_screenFetch
	exit 0
	;;
*)
    build_all
	;;
esac
