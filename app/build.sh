SHELL_FOLDER=$(cd "$(dirname "$0")";pwd)
CROSS_COMPILE_DIR=/opt
CROSS_PREFIX=/opt/gcc-riscv64-unknown-linux-gnu/bin/riscv64-unknown-linux-gnu
CROSS_COMPILE_DIR=/opt/gcc-riscv64-unknown-linux-gnu
CONFIGURE=./configure



build_all()
{
	echo "----------build all-----------------"
	build_bash
	build_make
	build_ncurses
	build_sudo
	build_screenFetch
        build_tree
	build_libevent
	build_cu
        build_screen
	#build_qt
	build_libmnl
	build_ethtool
	build_openssl
	build_iperf
	build_zlib
	build_openssh
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
	cd $SHELL_FOLDER/ncurses-6.2
	$CONFIGURE --host=riscv64-linux-gnu --with-shared --without-normal --without-debug CXX=$CROSS_PREFIX-g++ CC=$CROSS_PREFIX-gcc 
	make -j16
	make  install.libs DESTDIR=$SHELL_FOLDER/output
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

build_tree()
{
    # 编译tree
    cd $SHELL_FOLDER/tree-1.8.0
    make prefix=$SHELL_FOLDER/output CC=$CROSS_PREFIX-gcc -j16
    make prefix=$SHELL_FOLDER/output CC=$CROSS_PREFIX-gcc install
}

build_libevent()
{
    # 编译libevent
    cd $SHELL_FOLDER/libevent-2.1.12-stable
    $CONFIGURE --host=riscv64-linux-gnu --disable-openssl --disable-static --prefix=$SHELL_FOLDER/output CXX=$CROSS_PREFIX-g++ CC=$CROSS_PREFIX-gcc 
    make -j16
    make install
}

build_screen()
{
    # 编译screen
    cd $SHELL_FOLDER/screen-4.8.0
    $CONFIGURE --host=riscv64 CCFLAGS=-I$SHELL_FOLDER/output/usr/include LDFLAGS=-L$SHELL_FOLDER/output/usr/lib CXX=$CROSS_PREFIX-g++ CC=$CROSS_PREFIX-gcc
    make -j16
    #make install
}

build_cu()
{
    # 编译cu
    cd $SHELL_FOLDER/cu
    make prefix=$SHELL_FOLDER/output LIBEVENTDIR=$SHELL_FOLDER/output CC=$CROSS_PREFIX-gcc -j16
    make prefix=$SHELL_FOLDER/output LIBEVENTDIR=$SHELL_FOLDER/output CC=$CROSS_PREFIX-gcc install
}

build_qt()
{
    # 编译qt
    echo "------------------------------- 编译qt -------------------------------"
    cd $SHELL_FOLDER/qt-everywhere-src-5.12.11
    TEMP_PATH=$PATH
	export PATH=$PATH:$CROSS_COMPILE_DIR/bin
	./configure \
        -opensource \
        -confirm-license \
        -release \
        -optimize-size \
        -strip \
        -ltcg \
        -silent \
        -qpa linuxfb \
        -no-opengl \
        -skip webengine \
        -nomake tools \
        -nomake tests \
        -nomake examples \
        -xplatform linux-riscv64-gnu-g++ \
        -prefix /opt/Qt-5.12.11 \
        -extprefix $SHELL_FOLDER/host_output
	make -j16
	make install
	export PATH=$TEMP_PATH
    if [ ! -d "$SHELL_FOLDER/output/opt" ]; then
        mkdir $SHELL_FOLDER/output/opt
    fi
    if [ ! -d "$SHELL_FOLDER/output/opt/Qt-5.12.11" ]; then
        mkdir $SHELL_FOLDER/output/opt/Qt-5.12.11
    fi
    cp -a $SHELL_FOLDER/host_output/lib $SHELL_FOLDER/output/opt/Qt-5.12.11/
    cp -a $SHELL_FOLDER/host_output/plugins $SHELL_FOLDER/output/opt/Qt-5.12.11/
    cp -a $SHELL_FOLDER/host_output/translations $SHELL_FOLDER/output/opt/Qt-5.12.11/
    rm -rf $SHELL_FOLDER/output/opt/Qt-5.12.11/lib/cmake
    rm -rf $SHELL_FOLDER/output/opt/Qt-5.12.11/lib/pkgconfig
    rm -rf $SHELL_FOLDER/output/opt/Qt-5.12.11/lib/*.prl
    rm -rf $SHELL_FOLDER/output/opt/Qt-5.12.11/lib/*.a
    rm -rf $SHELL_FOLDER/output/opt/Qt-5.12.11/lib/*.la
}

build_libmnl()
{
    echo "------------------------------- 编译libmnl -------------------------------"
    cd $SHELL_FOLDER/libmnl-1.0.4
    ./configure --host=riscv64-linux-gnu --prefix=$SHELL_FOLDER/output CXX=$CROSS_PREFIX-g++ CC=$CROSS_PREFIX-gcc 
    make -j16
    make install
}

build_ethtool()
{
    echo "------------------------------- 编译ethtool -------------------------------"
    cd $SHELL_FOLDER/ethtool-5.13
    ./configure --host=riscv64-linux-gnu --prefix=$SHELL_FOLDER/output MNL_CFLAGS=-I$SHELL_FOLDER/output/include MNL_LIBS="-L$SHELL_FOLDER/output/lib -lmnl" CXX=$CROSS_PREFIX-g++ CC=$CROSS_PREFIX-gcc
    make -j16
    make install

}

build_openssl()
{
    echo "------------------------------- 编译openssl -------------------------------"
    cd $SHELL_FOLDER/openssl-1.1.1j
    ./Configure linux-generic64 no-asm --prefix=$SHELL_FOLDER/output --cross-compile-prefix=$CROSS_PREFIX-
    make -j16
    make install_sw
}

build_iperf()
{
    echo "------------------------------- 编译iperf -------------------------------"
    cd $SHELL_FOLDER/iperf-3.10.1
    ./configure --host=riscv64-linux-gnu --prefix=$SHELL_FOLDER/output --with-openssl=$SHELL_FOLDER/output CXX=$CROSS_PREFIX-g++ CC=$CROSS_PREFIX-gcc 
    make -j16
    make install
}

build_zlib()
{
    echo "------------------------------- 编译zlib -------------------------------"
    cd $SHELL_FOLDER/zlib-1.2.11
    export CC=$CROSS_PREFIX-gcc 
    ./configure --prefix=$SHELL_FOLDER/output
    make -j16
    make install
}

build_openssh()
{
    echo "------------------------------- 编译openssh -------------------------------"
    cd $SHELL_FOLDER/openssh-8.6p1
    ./configure --host=riscv64-linux-gnu --with-openssl=$SHELL_FOLDER/output --with-zlib=$SHELL_FOLDER/output --with-privsep-path=$SHELL_FOLDER/output --disable-strip CXX=$CROSS_PREFIX-g++ CC=$CROSS_PREFIX-gcc
    #./configure --host=riscv64-linux-gnu --with-openssl=$SHELL_FOLDER/output --with-zlib=$SHELL_FOLDER/output --with-privsep-path=$SHELL_FOLDER/output --prefix=$SHELL_FOLDER/output  --disable-strip CXX=$CROSS_PREFIX-g++ CC=$CROSS_PREFIX-gcc 
    make -j16
    #make install

    cp scp sftp ssh ssh-add ssh-agent ssh-keygen ssh-keyscan ../install/usr/local/bin/

    cp moduli ssh_config sshd_config ../install/usr/local/etc/

    cp sftp-server ssh-keysign ../install/usr/local/libexec/

    cp sshd ../install/usr/local/sbin/
}

clean_all()
{
	echo "clean all" 
}

case "$1" in
skip)
    CONFIGURE=echo
    exit 0
    ;;
bash)
	build_bash
	exit 0
	;;
make)
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
tree)
	build_tree
        exit 0
        ;;
libevent)
    	build_libevent
	exit 0
    	;;
screen)
    	build_screen
    	exit 0
    	;;
cu)
    	build_cu
    	exit 0
	;;
qt)
	build_qt
	exit 0
	;;
libmnl)
	build_libmnl
	exit 0
	;;
ethtool)
	build_ethtool
	exit 0
	;;
openssl)
	build_openssl
	exit 0
	;;
iperf)
	build_iperf
	exit 0
	;;
zlib)
	build_zlib
	exit 0
	;;
openssh)
	build_openssh
	exit 0
	;;
all)
	build_all
	exit 0
	;;
clean)
	clean_all
	exit 0
	;;
*)
    echo "no software, please input correct software name !"
	;;
esac
