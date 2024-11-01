#
# SPDX-License-Identifier: ISC
#
# Copyright (c) 2020-2023 Todd C. Miller <Todd.Miller@sudo.ws>
#
# Permission to use, copy, modify, and distribute this software for any
# purpose with or without fee is hereby granted, provided that the above
# copyright notice and this permission notice appear in all copies.
#
# THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
# WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
# MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
# ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
# WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
# ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
# OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
#
# plugins/sample_approval/Makefile.  Generated from Makefile.in by configure.
#

#### Start of system configuration section. ####

srcdir = .
devdir = $(srcdir)
top_builddir = ../..
abs_top_builddir = /code/sdb/sanyusdk/app/sudo-1.9.15p5
top_srcdir = ../..
scriptdir = $(top_srcdir)/scripts
incdir = $(top_srcdir)/include
cross_compiling = yes

# Compiler & tools to use
CC = /opt/gcc-riscv64-unknown-linux-gnu/bin/riscv64-unknown-linux-gnu-gcc
LIBTOOL = $(SHELL) $(top_builddir)/libtool
SED = /usr/bin/sed
AWK = gawk

# Our install program supports extra flags...
INSTALL = $(SHELL) $(scriptdir)/install-sh -c
INSTALL_OWNER = -o $(install_uid) -g $(install_gid)
INSTALL_BACKUP = 

# Libraries
LT_LIBS = $(top_builddir)/lib/util/libsudo_util.la
LIBS = $(LT_LIBS)

# C preprocessor flags
CPPFLAGS = -I$(incdir) -I$(top_builddir) -DZLIB_CONST -D_FORTIFY_SOURCE=2

# Usually -O and/or -g
CFLAGS = -g -O2 -fvisibility=hidden

# Flags to pass to the link stage
LDFLAGS = -Wl,--no-undefined -Wl,--enable-new-dtags
LT_LDFLAGS = -static -Wl,--version-script,$(shlib_map)

# Flags to pass to libtool
LTFLAGS = --tag=disable-static

# Address sanitizer flags
ASAN_CFLAGS = 
ASAN_LDFLAGS = -Wl,--allow-multiple-definition

# PIE flags
PIE_CFLAGS = 
PIE_LDFLAGS = 

# Stack smashing protection flags
HARDENING_CFLAGS = -fstack-protector-strong -fstack-clash-protection
HARDENING_LDFLAGS = -Wc,-fstack-protector-strong -Wc,-fstack-clash-protection -Wl,-z,relro -Wl,-z,now -Wl,-z,noexecstack

# cppcheck options, usually set in the top-level Makefile
CPPCHECK_OPTS = -q --enable=warning,performance,portability --suppress=constStatement --suppress=compareBoolExpressionWithInt --error-exitcode=1 --inline-suppr -Dva_copy=va_copy -U__cplusplus -UQUAD_MAX -UQUAD_MIN -UUQUAD_MAX -U_POSIX_HOST_NAME_MAX -U_POSIX_PATH_MAX -U__NBBY -DNSIG=64

# splint options, usually set in the top-level Makefile
SPLINT_OPTS = -D__restrict= -checks

# PVS-studio options
PVS_CFG = $(top_srcdir)/PVS-Studio.cfg
PVS_IGNORE = 'V707,V011,V002,V536'
PVS_LOG_OPTS = -a 'GA:1,2' -e -t errorfile -d $(PVS_IGNORE)

# Where to install things...
prefix = /code/sdb/sanyusdk/app/output
exec_prefix = $(prefix)
bindir = $(exec_prefix)/bin
sbindir = $(exec_prefix)/sbin
sysconfdir = /etc
adminconfdir = $(prefix)/etc
libexecdir = $(exec_prefix)/libexec
datarootdir = $(prefix)/share
localstatedir = $(prefix)/var
plugindir = /code/sdb/sanyusdk/app/output/libexec/sudo

# File mode and map file to use for shared libraries/objects
shlib_enable = no
shlib_mode = 0644
shlib_exp = $(srcdir)/sample_approval.exp
shlib_map = sample_approval.map
shlib_opt = sample_approval.opt

# User and group ids the installed files should be "owned" by
install_uid = 0
install_gid = 0

#### End of system configuration section. ####

SHELL = /bin/bash

OBJS =	sample_approval.lo

IOBJS = $(OBJS:.lo=.i)

POBJS = $(IOBJS:.i=.plog)

LIBOBJDIR = $(top_builddir)/@ac_config_libobj_dir@/

VERSION = 1.9.15p5

all: sample_approval.la

depend:
	$(scriptdir)/mkdep.pl --srcdir=$(top_srcdir) \
	    --builddir=$(abs_top_builddir) plugins/sample_approval/Makefile.in
	cd $(top_builddir) && ./config.status --file plugins/sample_approval/Makefile

Makefile: $(srcdir)/Makefile.in
	cd $(top_builddir) && ./config.status --file plugins/sample_approval/Makefile

.SUFFIXES: .c .h .i .lo .plog

.c.lo:
	$(LIBTOOL) $(LTFLAGS) --mode=compile $(CC) -c $(CPPFLAGS) $(CFLAGS) $(ASAN_CFLAGS) $(PIE_CFLAGS) $(HARDENING_CFLAGS) $<

.c.i:
	$(CC) -E -o $@ $(CPPFLAGS) $<

.i.plog:
	ifile=$<; rm -f $@; pvs-studio --cfg $(PVS_CFG) --sourcetree-root $(top_srcdir) --skip-cl-exe yes --source-file $${ifile%i}c --i-file $< --output-file $@

$(shlib_map): $(shlib_exp)
	@$(AWK) 'BEGIN { print "{\n\tglobal:" } { print "\t\t"$$0";" } END { print "\tlocal:\n\t\t*;\n};" }' $(shlib_exp) > $@

$(shlib_opt): $(shlib_exp)
	@$(SED) 's/^/+e /' $(shlib_exp) > $@

sample_approval.la: $(OBJS) $(LT_LIBS) $(shlib_map)
	$(LIBTOOL) $(LTFLAGS) --mode=link $(CC) $(LDFLAGS) $(ASAN_LDFLAGS) $(HARDENING_LDFLAGS) $(LT_LDFLAGS) -o $@ $(OBJS) $(LIBS) -module -avoid-version -rpath $(plugindir) -shrext .so

pre-install:

install: install-plugin

install-dirs:
	$(SHELL) $(scriptdir)/mkinstalldirs $(DESTDIR)$(plugindir)

install-binaries:

install-includes:

install-doc:

install-plugin: install-dirs sample_approval.la
	if [ X"$(shlib_enable)" = X"yes" ]; then \
	    INSTALL_BACKUP='$(INSTALL_BACKUP)' $(LIBTOOL) $(LTFLAGS) --mode=install $(INSTALL) $(INSTALL_OWNER) -m $(shlib_mode) sample_approval.la $(DESTDIR)$(plugindir); \
	fi

install-fuzzer:

uninstall:
	-$(LIBTOOL) $(LTFLAGS) --mode=uninstall rm -f $(DESTDIR)$(plugindir)/sample_approval.la
	-test -z "$(INSTALL_BACKUP)" || \
	    rm -f $(DESTDIR)$(plugindir)/sample_approval.so$(INSTALL_BACKUP)

splint:
	splint $(SPLINT_OPTS) -I$(incdir) -I$(top_builddir) $(srcdir)/*.c

cppcheck:
	cppcheck $(CPPCHECK_OPTS) -I$(incdir) -I$(top_builddir) $(srcdir)/*.c

pvs-log-files: $(POBJS)

pvs-studio: $(POBJS)
	plog-converter $(PVS_LOG_OPTS) $(POBJS)

fuzz:

check-fuzzer:

check: check-fuzzer

check-verbose: check

clean:
	-$(LIBTOOL) $(LTFLAGS) --mode=clean rm -f *.lo *.o *.la *.a
	-rm -f *.i *.plog stamp-* core *.core core.*

mostlyclean: clean

distclean: clean
	-rm -rf Makefile .libs $(shlib_map) $(shlib_opt)

clobber: distclean

realclean: distclean
	rm -f TAGS tags

cleandir: realclean

.PHONY: clean mostlyclean distclean cleandir clobber realclean

# Autogenerated dependencies, do not modify
getgrent.lo: $(srcdir)/getgrent.c $(incdir)/compat/stdbool.h \
             $(incdir)/sudo_compat.h $(incdir)/sudo_util.h \
             $(top_builddir)/config.h
	$(LIBTOOL) $(LTFLAGS) --mode=compile $(CC) -c $(CPPFLAGS) $(CFLAGS) $(ASAN_CFLAGS) $(PIE_CFLAGS) $(HARDENING_CFLAGS) $(srcdir)/getgrent.c
getgrent.i: $(srcdir)/getgrent.c $(incdir)/compat/stdbool.h \
             $(incdir)/sudo_compat.h $(incdir)/sudo_util.h \
             $(top_builddir)/config.h
	$(CC) -E -o $@ $(CPPFLAGS) $<
getgrent.plog: getgrent.i
	rm -f $@; pvs-studio --cfg $(PVS_CFG) --sourcetree-root $(top_srcdir) --skip-cl-exe yes --source-file $(srcdir)/getgrent.c --i-file $< --output-file $@
sample_approval.lo: $(srcdir)/sample_approval.c $(incdir)/compat/stdbool.h \
               $(incdir)/sudo_compat.h $(incdir)/sudo_plugin.h \
               $(top_builddir)/config.h
	$(LIBTOOL) $(LTFLAGS) --mode=compile $(CC) -c $(CPPFLAGS) $(CFLAGS) $(ASAN_CFLAGS) $(PIE_CFLAGS) $(HARDENING_CFLAGS) $(srcdir)/sample_approval.c
sample_approval.i: $(srcdir)/sample_approval.c $(incdir)/compat/stdbool.h \
               $(incdir)/sudo_compat.h $(incdir)/sudo_plugin.h \
               $(top_builddir)/config.h
	$(CC) -E -o $@ $(CPPFLAGS) $<
sample_approval.plog: sample_approval.i
	rm -f $@; pvs-studio --cfg $(PVS_CFG) --sourcetree-root $(top_srcdir) --skip-cl-exe yes --source-file $(srcdir)/sample_approval.c --i-file $< --output-file $@
