# 编译工具链
## 源码

github源码

```
https://github.com/riscv/riscv-gnu-toolchain tag:2021.08.07
```

gitee源码
```
https://gitee.com/mirrors/riscv-gnu-toolchain 
```

## 编译配置
```
# 用于裸机带newlib的gcc
./configure --prefix=/opt/gcc-riscv64-unknown-elf --with-cmodel=medany
make -j16
# 用于linux带glibc的gcc
./configure --prefix=/opt/gcc-riscv64-unknown-linux-gnu
make linux -j16
```