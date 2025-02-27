# This is a -*-perl-*- script
#
# Set variables that were defined by configure, in case we need them
# during the tests.

%CONFIG_FLAGS = (
    AM_LDFLAGS      => '-Wl,--export-dynamic',
    AR              => 'ar',
    CC              => '/opt/gcc-riscv64-unknown-linux-gnu/bin/riscv64-unknown-linux-gnu-gcc',
    CFLAGS          => '-g -O2',
    CPP             => '/opt/gcc-riscv64-unknown-linux-gnu/bin/riscv64-unknown-linux-gnu-gcc -E',
    CPPFLAGS        => '',
    GUILE_CFLAGS    => '',
    GUILE_LIBS      => '',
    LDFLAGS         => '',
    LIBS            => '-ldl ',
    USE_SYSTEM_GLOB => 'yes'
);

1;
