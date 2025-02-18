# uncomment if you run a non bourne compatible shell. Ie. csh
#SHELL = /usr/bin/sh

AUTORECONF=autoreconf

prefix=/usr/local
exec_prefix=${prefix}
bindir=${exec_prefix}/bin
sbindir=${exec_prefix}/sbin
libexecdir=${exec_prefix}/libexec
datadir=${datarootdir}
datarootdir=${prefix}/share
mandir=${datarootdir}/man
mansubdir=man
sysconfdir=${prefix}/etc
piddir=/var/run
srcdir=.
top_srcdir=.
abs_top_srcdir=/code/sdb/sanyusdk/app/openssh-8.6p1

DESTDIR=

SSH_PROGRAM=${exec_prefix}/bin/ssh
ASKPASS_PROGRAM=$(libexecdir)/ssh-askpass
SFTP_SERVER=$(libexecdir)/sftp-server
SSH_KEYSIGN=$(libexecdir)/ssh-keysign
SSH_PKCS11_HELPER=$(libexecdir)/ssh-pkcs11-helper
SSH_SK_HELPER=$(libexecdir)/ssh-sk-helper
PRIVSEP_PATH=/code/sdb/sanyusdk/app/output
SSH_PRIVSEP_USER=sshd
STRIP_OPT=
TEST_SHELL=sh

PATHS= -DSSHDIR=\"$(sysconfdir)\" \
	-D_PATH_SSH_PROGRAM=\"$(SSH_PROGRAM)\" \
	-D_PATH_SSH_ASKPASS_DEFAULT=\"$(ASKPASS_PROGRAM)\" \
	-D_PATH_SFTP_SERVER=\"$(SFTP_SERVER)\" \
	-D_PATH_SSH_KEY_SIGN=\"$(SSH_KEYSIGN)\" \
	-D_PATH_SSH_PKCS11_HELPER=\"$(SSH_PKCS11_HELPER)\" \
	-D_PATH_SSH_SK_HELPER=\"$(SSH_SK_HELPER)\" \
	-D_PATH_SSH_PIDDIR=\"$(piddir)\" \
	-D_PATH_PRIVSEP_CHROOT_DIR=\"$(PRIVSEP_PATH)\"

CC=/opt/gcc-riscv64-unknown-linux-gnu/bin/riscv64-unknown-linux-gnu-gcc
LD=/opt/gcc-riscv64-unknown-linux-gnu/bin/riscv64-unknown-linux-gnu-gcc
CFLAGS=-g -O2 -pipe -Wno-error=format-truncation -Wall -Wextra -Wpointer-arith -Wuninitialized -Wsign-compare -Wformat-security -Wsizeof-pointer-memaccess -Wno-pointer-sign -Wno-unused-parameter -Wno-unused-result -Wimplicit-fallthrough -fno-strict-aliasing -D_FORTIFY_SOURCE=2 -ftrapv -fno-builtin-memset -fstack-protector-strong -fPIE  
CFLAGS_NOPIE=-g -O2 -pipe -Wno-error=format-truncation -Wall -Wextra -Wpointer-arith -Wuninitialized -Wsign-compare -Wformat-security -Wsizeof-pointer-memaccess -Wno-pointer-sign -Wno-unused-parameter -Wno-unused-result -Wimplicit-fallthrough -fno-strict-aliasing -D_FORTIFY_SOURCE=2 -ftrapv -fno-builtin-memset -fstack-protector-strong  
CPPFLAGS=-I. -I$(srcdir) -I/code/sdb/sanyusdk/app/output/include  -D_XOPEN_SOURCE=600 -D_BSD_SOURCE -D_DEFAULT_SOURCE $(PATHS) -DHAVE_CONFIG_H
PICFLAG=-fPIC
LIBS=-lcrypto -ldl -lutil -lz  -lcrypt -lresolv
K5LIBS=
GSSLIBS=
SSHDLIBS=
LIBEDIT=
LIBFIDO2=
AR=ar
AWK=gawk
RANLIB=ranlib
INSTALL=/usr/bin/install -c
SED=/usr/bin/sed
XAUTH_PATH=/usr/bin/xauth
LDFLAGS=-L. -Lopenbsd-compat/ -L/code/sdb/sanyusdk/app/output/lib  -Wl,-z,relro -Wl,-z,now -Wl,-z,noexecstack -fstack-protector-strong -pie 
LDFLAGS_NOPIE=-L. -Lopenbsd-compat/ -L/code/sdb/sanyusdk/app/output/lib  -Wl,-z,relro -Wl,-z,now -Wl,-z,noexecstack -fstack-protector-strong 
EXEEXT=
MANFMT=/usr/bin/nroff -mandoc
MKDIR_P=/usr/bin/mkdir -p

.SUFFIXES: .lo

TARGETS=ssh$(EXEEXT) sshd$(EXEEXT) ssh-add$(EXEEXT) ssh-keygen$(EXEEXT) ssh-keyscan${EXEEXT} ssh-keysign${EXEEXT} ssh-pkcs11-helper$(EXEEXT) ssh-agent$(EXEEXT) scp$(EXEEXT) sftp-server$(EXEEXT) sftp$(EXEEXT) ssh-sk-helper$(EXEEXT)

XMSS_OBJS=\
	ssh-xmss.o \
	sshkey-xmss.o \
	xmss_commons.o \
	xmss_fast.o \
	xmss_hash.o \
	xmss_hash_address.o \
	xmss_wots.o

LIBOPENSSH_OBJS=\
	ssh_api.o \
	ssherr.o \
	sshbuf.o \
	sshkey.o \
	sshbuf-getput-basic.o \
	sshbuf-misc.o \
	sshbuf-getput-crypto.o \
	krl.o \
	bitmap.o \
	${XMSS_OBJS}

LIBSSH_OBJS=${LIBOPENSSH_OBJS} \
	authfd.o authfile.o \
	canohost.o channels.o cipher.o cipher-aes.o cipher-aesctr.o \
	cipher-ctr.o cleanup.o \
	compat.o fatal.o hostfile.o \
	log.o match.o moduli.o nchan.o packet.o \
	readpass.o ttymodes.o xmalloc.o addr.o addrmatch.o \
	atomicio.o dispatch.o mac.o misc.o utf8.o \
	monitor_fdpass.o rijndael.o ssh-dss.o ssh-ecdsa.o ssh-ecdsa-sk.o \
	ssh-ed25519-sk.o ssh-rsa.o dh.o \
	msg.o progressmeter.o dns.o entropy.o gss-genr.o umac.o umac128.o \
	ssh-pkcs11.o smult_curve25519_ref.o \
	poly1305.o chacha.o cipher-chachapoly.o cipher-chachapoly-libcrypto.o \
	ssh-ed25519.o digest-openssl.o digest-libc.o \
	hmac.o sc25519.o ge25519.o fe25519.o ed25519.o verify.o hash.o \
	kex.o kexdh.o kexgex.o kexecdh.o kexc25519.o \
	kexgexc.o kexgexs.o \
	kexsntrup761x25519.o sntrup761.o kexgen.o \
	sftp-realpath.o platform-pledge.o platform-tracing.o platform-misc.o \
	sshbuf-io.o

SKOBJS=	ssh-sk-client.o

SSHOBJS= ssh.o readconf.o clientloop.o sshtty.o \
	sshconnect.o sshconnect2.o mux.o $(SKOBJS)

SSHDOBJS=sshd.o auth-rhosts.o auth-passwd.o \
	audit.o audit-bsm.o audit-linux.o platform.o \
	sshpty.o sshlogin.o servconf.o serverloop.o \
	auth.o auth2.o auth-options.o session.o \
	auth2-chall.o groupaccess.o \
	auth-bsdauth.o auth2-hostbased.o auth2-kbdint.o \
	auth2-none.o auth2-passwd.o auth2-pubkey.o \
	monitor.o monitor_wrap.o auth-krb5.o \
	auth2-gss.o gss-serv.o gss-serv-krb5.o \
	loginrec.o auth-pam.o auth-shadow.o auth-sia.o md5crypt.o \
	srclimit.o sftp-server.o sftp-common.o \
	sandbox-null.o sandbox-rlimit.o sandbox-systrace.o sandbox-darwin.o \
	sandbox-seccomp-filter.o sandbox-capsicum.o sandbox-pledge.o \
	sandbox-solaris.o uidswap.o $(SKOBJS)

SCP_OBJS=	scp.o progressmeter.o

SSHADD_OBJS=	ssh-add.o $(SKOBJS)

SSHAGENT_OBJS=	ssh-agent.o ssh-pkcs11-client.o $(SKOBJS)

SSHKEYGEN_OBJS=	ssh-keygen.o sshsig.o $(SKOBJS)

SSHKEYSIGN_OBJS=ssh-keysign.o readconf.o uidswap.o $(SKOBJS)

P11HELPER_OBJS=	ssh-pkcs11-helper.o ssh-pkcs11.o $(SKOBJS)

SKHELPER_OBJS=	ssh-sk-helper.o ssh-sk.o sk-usbhid.o

SSHKEYSCAN_OBJS=ssh-keyscan.o $(SKOBJS)

SFTPSERVER_OBJS=sftp-common.o sftp-server.o sftp-server-main.o

SFTP_OBJS=	sftp.o sftp-client.o sftp-common.o sftp-glob.o progressmeter.o

MANPAGES	= moduli.5.out scp.1.out ssh-add.1.out ssh-agent.1.out ssh-keygen.1.out ssh-keyscan.1.out ssh.1.out sshd.8.out sftp-server.8.out sftp.1.out ssh-keysign.8.out ssh-pkcs11-helper.8.out ssh-sk-helper.8.out sshd_config.5.out ssh_config.5.out
MANPAGES_IN	= moduli.5 scp.1 ssh-add.1 ssh-agent.1 ssh-keygen.1 ssh-keyscan.1 ssh.1 sshd.8 sftp-server.8 sftp.1 ssh-keysign.8 ssh-pkcs11-helper.8 ssh-sk-helper.8 sshd_config.5 ssh_config.5
MANTYPE		= doc

CONFIGFILES=sshd_config.out ssh_config.out moduli.out
CONFIGFILES_IN=sshd_config ssh_config moduli

PATHSUBS	= \
	-e 's|/etc/ssh/ssh_config|$(sysconfdir)/ssh_config|g' \
	-e 's|/etc/ssh/ssh_known_hosts|$(sysconfdir)/ssh_known_hosts|g' \
	-e 's|/etc/ssh/sshd_config|$(sysconfdir)/sshd_config|g' \
	-e 's|/usr/libexec|$(libexecdir)|g' \
	-e 's|/etc/shosts.equiv|$(sysconfdir)/shosts.equiv|g' \
	-e 's|/etc/ssh/ssh_host_key|$(sysconfdir)/ssh_host_key|g' \
	-e 's|/etc/ssh/ssh_host_ecdsa_key|$(sysconfdir)/ssh_host_ecdsa_key|g' \
	-e 's|/etc/ssh/ssh_host_dsa_key|$(sysconfdir)/ssh_host_dsa_key|g' \
	-e 's|/etc/ssh/ssh_host_rsa_key|$(sysconfdir)/ssh_host_rsa_key|g' \
	-e 's|/etc/ssh/ssh_host_ed25519_key|$(sysconfdir)/ssh_host_ed25519_key|g' \
	-e 's|/var/run/sshd.pid|$(piddir)/sshd.pid|g' \
	-e 's|/etc/moduli|$(sysconfdir)/moduli|g' \
	-e 's|/etc/ssh/moduli|$(sysconfdir)/moduli|g' \
	-e 's|/etc/ssh/sshrc|$(sysconfdir)/sshrc|g' \
	-e 's|/usr/X11R6/bin/xauth|$(XAUTH_PATH)|g' \
	-e 's|/var/empty|$(PRIVSEP_PATH)|g' \
	-e 's|/usr/bin:/bin:/usr/sbin:/sbin|/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/bin|g'

FIXPATHSCMD	= $(SED) $(PATHSUBS)
FIXALGORITHMSCMD= $(SHELL) $(srcdir)/fixalgorithms $(SED) \
		     

all: configure-check $(CONFIGFILES) $(MANPAGES) $(TARGETS)

$(LIBSSH_OBJS): Makefile.in config.h
$(SSHOBJS): Makefile.in config.h
$(SSHDOBJS): Makefile.in config.h
configure-check: $(srcdir)/configure

$(srcdir)/configure: configure.ac $(srcdir)/m4/*.m4
	@echo "ERROR: configure is out of date; please run ${AUTORECONF} (and configure)" 1>&2
	@exit 1

.c.o:
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

LIBCOMPAT=openbsd-compat/libopenbsd-compat.a
$(LIBCOMPAT): always
	(cd openbsd-compat && $(MAKE))
always:

libssh.a: $(LIBSSH_OBJS)
	$(AR) rv $@ $(LIBSSH_OBJS)
	$(RANLIB) $@

ssh$(EXEEXT): $(LIBCOMPAT) libssh.a $(SSHOBJS)
	$(LD) -o $@ $(SSHOBJS) $(LDFLAGS) -lssh -lopenbsd-compat $(LIBS) $(GSSLIBS)

sshd$(EXEEXT): libssh.a	$(LIBCOMPAT) $(SSHDOBJS)
	$(LD) -o $@ $(SSHDOBJS) $(LDFLAGS) -lssh -lopenbsd-compat $(SSHDLIBS) $(LIBS) $(GSSLIBS) $(K5LIBS)

scp$(EXEEXT): $(LIBCOMPAT) libssh.a $(SCP_OBJS)
	$(LD) -o $@ $(SCP_OBJS) $(LDFLAGS) -lssh -lopenbsd-compat $(LIBS)

ssh-add$(EXEEXT): $(LIBCOMPAT) libssh.a $(SSHADD_OBJS)
	$(LD) -o $@ $(SSHADD_OBJS) $(LDFLAGS) -lssh -lopenbsd-compat $(LIBS)

ssh-agent$(EXEEXT): $(LIBCOMPAT) libssh.a $(SSHAGENT_OBJS)
	$(LD) -o $@ $(SSHAGENT_OBJS) $(LDFLAGS) -lssh -lopenbsd-compat $(LIBS)

ssh-keygen$(EXEEXT): $(LIBCOMPAT) libssh.a $(SSHKEYGEN_OBJS)
	$(LD) -o $@ $(SSHKEYGEN_OBJS) $(LDFLAGS) -lssh -lopenbsd-compat $(LIBS)

ssh-keysign$(EXEEXT): $(LIBCOMPAT) libssh.a $(SSHKEYSIGN_OBJS)
	$(LD) -o $@ $(SSHKEYSIGN_OBJS) $(LDFLAGS) -lssh -lopenbsd-compat $(LIBS)

ssh-pkcs11-helper$(EXEEXT): $(LIBCOMPAT) libssh.a $(P11HELPER_OBJS)
	$(LD) -o $@ $(P11HELPER_OBJS) $(LDFLAGS) -lssh -lopenbsd-compat -lssh -lopenbsd-compat $(LIBS)

ssh-sk-helper$(EXEEXT): $(LIBCOMPAT) libssh.a $(SKHELPER_OBJS)
	$(LD) -o $@ $(SKHELPER_OBJS) $(LDFLAGS) -lssh -lopenbsd-compat -lssh -lopenbsd-compat $(LIBS) $(LIBFIDO2)

ssh-keyscan$(EXEEXT): $(LIBCOMPAT) libssh.a $(SSHKEYSCAN_OBJS)
	$(LD) -o $@ $(SSHKEYSCAN_OBJS) $(LDFLAGS) -lssh -lopenbsd-compat -lssh $(LIBS)

sftp-server$(EXEEXT): $(LIBCOMPAT) libssh.a $(SFTPSERVER_OBJS)
	$(LD) -o $@ $(SFTPSERVER_OBJS) $(LDFLAGS) -lssh -lopenbsd-compat $(LIBS)

sftp$(EXEEXT): $(LIBCOMPAT) libssh.a $(SFTP_OBJS)
	$(LD) -o $@ $(SFTP_OBJS) $(LDFLAGS) -lssh -lopenbsd-compat $(LIBS) $(LIBEDIT)

# test driver for the loginrec code - not built by default
logintest: logintest.o $(LIBCOMPAT) libssh.a loginrec.o
	$(LD) -o $@ logintest.o $(LDFLAGS) loginrec.o -lopenbsd-compat -lssh $(LIBS)

$(MANPAGES): $(MANPAGES_IN)
	if test "$(MANTYPE)" = "cat"; then \
		manpage=$(srcdir)/`echo $@ | sed 's/\.[1-9]\.out$$/\.0/'`; \
	else \
		manpage=$(srcdir)/`echo $@ | sed 's/\.out$$//'`; \
	fi; \
	if test "$(MANTYPE)" = "man"; then \
		$(FIXPATHSCMD) $${manpage} | $(FIXALGORITHMSCMD) | \
		    $(AWK) -f $(srcdir)/mdoc2man.awk > $@; \
	else \
		$(FIXPATHSCMD) $${manpage} | $(FIXALGORITHMSCMD) > $@; \
	fi

$(CONFIGFILES): $(CONFIGFILES_IN)
	conffile=`echo $@ | sed 's/.out$$//'`; \
	$(FIXPATHSCMD) $(srcdir)/$${conffile} > $@

# fake rule to stop make trying to compile moduli.o into a binary "moduli.o"
moduli:
	echo

clean:	regressclean
	rm -f *.o *.lo *.a $(TARGETS) logintest config.cache config.log
	rm -f *.out core survey
	rm -f regress/check-perm$(EXEEXT)
	rm -f regress/mkdtemp$(EXEEXT)
	rm -f regress/unittests/test_helper/*.a
	rm -f regress/unittests/test_helper/*.o
	rm -f regress/unittests/authopt/*.o
	rm -f regress/unittests/authopt/test_authopt$(EXEEXT)
	rm -f regress/unittests/bitmap/*.o
	rm -f regress/unittests/bitmap/test_bitmap$(EXEEXT)
	rm -f regress/unittests/conversion/*.o
	rm -f regress/unittests/conversion/test_conversion$(EXEEXT)
	rm -f regress/unittests/hostkeys/*.o
	rm -f regress/unittests/hostkeys/test_hostkeys$(EXEEXT)
	rm -f regress/unittests/kex/*.o
	rm -f regress/unittests/kex/test_kex$(EXEEXT)
	rm -f regress/unittests/match/*.o
	rm -f regress/unittests/match/test_match$(EXEEXT)
	rm -f regress/unittests/misc/*.o
	rm -f regress/unittests/misc/test_misc$(EXEEXT)
	rm -f regress/unittests/sshbuf/*.o
	rm -f regress/unittests/sshbuf/test_sshbuf$(EXEEXT)
	rm -f regress/unittests/sshkey/*.o
	rm -f regress/unittests/sshkey/test_sshkey$(EXEEXT)
	rm -f regress/unittests/sshsig/*.o
	rm -f regress/unittests/sshsig/test_sshsig$(EXEEXT)
	rm -f regress/unittests/utf8/*.o
	rm -f regress/unittests/utf8/test_utf8$(EXEEXT)
	rm -f regress/misc/sk-dummy/*.o
	rm -f regress/misc/sk-dummy/*.lo
	rm -f regress/misc/sk-dummy/sk-dummy.so
	(cd openbsd-compat && $(MAKE) clean)

distclean:	regressclean
	rm -f *.o *.a $(TARGETS) logintest config.cache config.log
	rm -f *.out core opensshd.init openssh.xml
	rm -f Makefile buildpkg.sh config.h config.status
	rm -f survey.sh openbsd-compat/regress/Makefile *~ 
	rm -rf autom4te.cache
	rm -f regress/check-perm
	rm -f regress/mkdtemp
	rm -f regress/unittests/test_helper/*.a
	rm -f regress/unittests/test_helper/*.o
	rm -f regress/unittests/authopt/*.o
	rm -f regress/unittests/authopt/test_authopt
	rm -f regress/unittests/bitmap/*.o
	rm -f regress/unittests/bitmap/test_bitmap
	rm -f regress/unittests/conversion/*.o
	rm -f regress/unittests/conversion/test_conversion
	rm -f regress/unittests/hostkeys/*.o
	rm -f regress/unittests/hostkeys/test_hostkeys
	rm -f regress/unittests/kex/*.o
	rm -f regress/unittests/kex/test_kex
	rm -f regress/unittests/match/*.o
	rm -f regress/unittests/match/test_match
	rm -f regress/unittests/misc/*.o
	rm -f regress/unittests/misc/test_misc
	rm -f regress/unittests/sshbuf/*.o
	rm -f regress/unittests/sshbuf/test_sshbuf
	rm -f regress/unittests/sshkey/*.o
	rm -f regress/unittests/sshkey/test_sshkey
	rm -f regress/unittests/sshsig/*.o
	rm -f regress/unittests/sshsig/test_sshsig
	rm -f regress/unittests/utf8/*.o
	rm -f regress/unittests/utf8/test_utf8
	(cd openbsd-compat && $(MAKE) distclean)
	if test -d pkg ; then \
		rm -fr pkg ; \
	fi

veryclean: distclean
	rm -f configure config.h.in *.0

cleandir: veryclean

mrproper: veryclean

realclean: veryclean

catman-do:
	@for f in $(MANPAGES_IN) ; do \
		base=`echo $$f | sed 's/\..*$$//'` ; \
		echo "$$f -> $$base.0" ; \
		$(MANFMT) $$f | cat -v | sed -e 's/.\^H//g' \
			>$$base.0 ; \
	done

depend: depend-rebuild
	rm -f .depend.bak

depend-rebuild:
	mv .depend .depend.old
	rm -f config.h .depend
	touch config.h .depend
	makedepend -w1000 -Y. -f .depend *.c 2>/dev/null
	(echo '# Automatically generated by makedepend.'; \
	 echo '# Run "make depend" to rebuild.'; sort .depend ) >.depend.tmp
	mv .depend.tmp .depend
	rm -f .depend.bak
	mv .depend.old .depend.bak
	rm -f config.h

depend-check: depend-rebuild
	cmp .depend .depend.bak || (echo .depend stale && exit 1)

distprep: catman-do depend-check
	$(AUTORECONF)
	-rm -rf autom4te.cache .depend.bak

install: $(CONFIGFILES) $(MANPAGES) $(TARGETS) install-files install-sysconf host-key check-config
install-nokeys: $(CONFIGFILES) $(MANPAGES) $(TARGETS) install-files install-sysconf
install-nosysconf: $(CONFIGFILES) $(MANPAGES) $(TARGETS) install-files

check-config:
	-$(DESTDIR)$(sbindir)/sshd -t -f $(DESTDIR)$(sysconfdir)/sshd_config

install-files:
	$(MKDIR_P) $(DESTDIR)$(bindir)
	$(MKDIR_P) $(DESTDIR)$(sbindir)
	$(MKDIR_P) $(DESTDIR)$(mandir)/$(mansubdir)1
	$(MKDIR_P) $(DESTDIR)$(mandir)/$(mansubdir)5
	$(MKDIR_P) $(DESTDIR)$(mandir)/$(mansubdir)8
	$(MKDIR_P) $(DESTDIR)$(libexecdir)
	$(MKDIR_P) -m 0755 $(DESTDIR)$(PRIVSEP_PATH)
	$(INSTALL) -m 0755 $(STRIP_OPT) ssh$(EXEEXT) $(DESTDIR)$(bindir)/ssh$(EXEEXT)
	$(INSTALL) -m 0755 $(STRIP_OPT) scp$(EXEEXT) $(DESTDIR)$(bindir)/scp$(EXEEXT)
	$(INSTALL) -m 0755 $(STRIP_OPT) ssh-add$(EXEEXT) $(DESTDIR)$(bindir)/ssh-add$(EXEEXT)
	$(INSTALL) -m 0755 $(STRIP_OPT) ssh-agent$(EXEEXT) $(DESTDIR)$(bindir)/ssh-agent$(EXEEXT)
	$(INSTALL) -m 0755 $(STRIP_OPT) ssh-keygen$(EXEEXT) $(DESTDIR)$(bindir)/ssh-keygen$(EXEEXT)
	$(INSTALL) -m 0755 $(STRIP_OPT) ssh-keyscan$(EXEEXT) $(DESTDIR)$(bindir)/ssh-keyscan$(EXEEXT)
	$(INSTALL) -m 0755 $(STRIP_OPT) sshd$(EXEEXT) $(DESTDIR)$(sbindir)/sshd$(EXEEXT)
	$(INSTALL) -m 4711 $(STRIP_OPT) ssh-keysign$(EXEEXT) $(DESTDIR)$(SSH_KEYSIGN)$(EXEEXT)
	$(INSTALL) -m 0755 $(STRIP_OPT) ssh-pkcs11-helper$(EXEEXT) $(DESTDIR)$(SSH_PKCS11_HELPER)$(EXEEXT)
	$(INSTALL) -m 0755 $(STRIP_OPT) ssh-sk-helper$(EXEEXT) $(DESTDIR)$(SSH_SK_HELPER)$(EXEEXT)
	$(INSTALL) -m 0755 $(STRIP_OPT) sftp$(EXEEXT) $(DESTDIR)$(bindir)/sftp$(EXEEXT)
	$(INSTALL) -m 0755 $(STRIP_OPT) sftp-server$(EXEEXT) $(DESTDIR)$(SFTP_SERVER)$(EXEEXT)
	$(INSTALL) -m 644 ssh.1.out $(DESTDIR)$(mandir)/$(mansubdir)1/ssh.1
	$(INSTALL) -m 644 scp.1.out $(DESTDIR)$(mandir)/$(mansubdir)1/scp.1
	$(INSTALL) -m 644 ssh-add.1.out $(DESTDIR)$(mandir)/$(mansubdir)1/ssh-add.1
	$(INSTALL) -m 644 ssh-agent.1.out $(DESTDIR)$(mandir)/$(mansubdir)1/ssh-agent.1
	$(INSTALL) -m 644 ssh-keygen.1.out $(DESTDIR)$(mandir)/$(mansubdir)1/ssh-keygen.1
	$(INSTALL) -m 644 ssh-keyscan.1.out $(DESTDIR)$(mandir)/$(mansubdir)1/ssh-keyscan.1
	$(INSTALL) -m 644 moduli.5.out $(DESTDIR)$(mandir)/$(mansubdir)5/moduli.5
	$(INSTALL) -m 644 sshd_config.5.out $(DESTDIR)$(mandir)/$(mansubdir)5/sshd_config.5
	$(INSTALL) -m 644 ssh_config.5.out $(DESTDIR)$(mandir)/$(mansubdir)5/ssh_config.5
	$(INSTALL) -m 644 sshd.8.out $(DESTDIR)$(mandir)/$(mansubdir)8/sshd.8
	$(INSTALL) -m 644 sftp.1.out $(DESTDIR)$(mandir)/$(mansubdir)1/sftp.1
	$(INSTALL) -m 644 sftp-server.8.out $(DESTDIR)$(mandir)/$(mansubdir)8/sftp-server.8
	$(INSTALL) -m 644 ssh-keysign.8.out $(DESTDIR)$(mandir)/$(mansubdir)8/ssh-keysign.8
	$(INSTALL) -m 644 ssh-pkcs11-helper.8.out $(DESTDIR)$(mandir)/$(mansubdir)8/ssh-pkcs11-helper.8
	$(INSTALL) -m 644 ssh-sk-helper.8.out $(DESTDIR)$(mandir)/$(mansubdir)8/ssh-sk-helper.8

install-sysconf:
	$(MKDIR_P) $(DESTDIR)$(sysconfdir)
	@if [ ! -f $(DESTDIR)$(sysconfdir)/ssh_config ]; then \
		$(INSTALL) -m 644 ssh_config.out $(DESTDIR)$(sysconfdir)/ssh_config; \
	else \
		echo "$(DESTDIR)$(sysconfdir)/ssh_config already exists, install will not overwrite"; \
	fi
	@if [ ! -f $(DESTDIR)$(sysconfdir)/sshd_config ]; then \
		$(INSTALL) -m 644 sshd_config.out $(DESTDIR)$(sysconfdir)/sshd_config; \
	else \
		echo "$(DESTDIR)$(sysconfdir)/sshd_config already exists, install will not overwrite"; \
	fi
	@if [ ! -f $(DESTDIR)$(sysconfdir)/moduli ]; then \
		if [ -f $(DESTDIR)$(sysconfdir)/primes ]; then \
			echo "moving $(DESTDIR)$(sysconfdir)/primes to $(DESTDIR)$(sysconfdir)/moduli"; \
			mv "$(DESTDIR)$(sysconfdir)/primes" "$(DESTDIR)$(sysconfdir)/moduli"; \
		else \
			$(INSTALL) -m 644 moduli.out $(DESTDIR)$(sysconfdir)/moduli; \
		fi ; \
	else \
		echo "$(DESTDIR)$(sysconfdir)/moduli already exists, install will not overwrite"; \
	fi

host-key: ssh-keygen$(EXEEXT)
	@if [ -z "$(DESTDIR)" ] ; then \
		./ssh-keygen -A; \
	fi

host-key-force: ssh-keygen$(EXEEXT) ssh$(EXEEXT)
	./ssh-keygen -t dsa -f $(DESTDIR)$(sysconfdir)/ssh_host_dsa_key -N ""
	./ssh-keygen -t rsa -f $(DESTDIR)$(sysconfdir)/ssh_host_rsa_key -N ""
	./ssh-keygen -t ed25519 -f $(DESTDIR)$(sysconfdir)/ssh_host_ed25519_key -N ""
	if ./ssh -Q key | grep ecdsa >/dev/null ; then \
		./ssh-keygen -t ecdsa -f $(DESTDIR)$(sysconfdir)/ssh_host_ecdsa_key -N ""; \
	fi

uninstallall:	uninstall
	-rm -f $(DESTDIR)$(sysconfdir)/ssh_config
	-rm -f $(DESTDIR)$(sysconfdir)/sshd_config
	-rmdir $(DESTDIR)$(sysconfdir)
	-rmdir $(DESTDIR)$(bindir)
	-rmdir $(DESTDIR)$(sbindir)
	-rmdir $(DESTDIR)$(mandir)/$(mansubdir)1
	-rmdir $(DESTDIR)$(mandir)/$(mansubdir)8
	-rmdir $(DESTDIR)$(mandir)
	-rmdir $(DESTDIR)$(libexecdir)

uninstall:
	-rm -f $(DESTDIR)$(bindir)/ssh$(EXEEXT)
	-rm -f $(DESTDIR)$(bindir)/scp$(EXEEXT)
	-rm -f $(DESTDIR)$(bindir)/ssh-add$(EXEEXT)
	-rm -f $(DESTDIR)$(bindir)/ssh-agent$(EXEEXT)
	-rm -f $(DESTDIR)$(bindir)/ssh-keygen$(EXEEXT)
	-rm -f $(DESTDIR)$(bindir)/ssh-keyscan$(EXEEXT)
	-rm -f $(DESTDIR)$(bindir)/sftp$(EXEEXT)
	-rm -f $(DESTDIR)$(sbindir)/sshd$(EXEEXT)
	-rm -r $(DESTDIR)$(SFTP_SERVER)$(EXEEXT)
	-rm -f $(DESTDIR)$(SSH_KEYSIGN)$(EXEEXT)
	-rm -f $(DESTDIR)$(SSH_PKCS11_HELPER)$(EXEEXT)
	-rm -f $(DESTDIR)$(SSH_SK_HELPER)$(EXEEXT)
	-rm -f $(DESTDIR)$(mandir)/$(mansubdir)1/ssh.1
	-rm -f $(DESTDIR)$(mandir)/$(mansubdir)1/scp.1
	-rm -f $(DESTDIR)$(mandir)/$(mansubdir)1/ssh-add.1
	-rm -f $(DESTDIR)$(mandir)/$(mansubdir)1/ssh-agent.1
	-rm -f $(DESTDIR)$(mandir)/$(mansubdir)1/ssh-keygen.1
	-rm -f $(DESTDIR)$(mandir)/$(mansubdir)1/sftp.1
	-rm -f $(DESTDIR)$(mandir)/$(mansubdir)1/ssh-keyscan.1
	-rm -f $(DESTDIR)$(mandir)/$(mansubdir)8/sshd.8
	-rm -f $(DESTDIR)$(mandir)/$(mansubdir)8/sftp-server.8
	-rm -f $(DESTDIR)$(mandir)/$(mansubdir)8/ssh-keysign.8
	-rm -f $(DESTDIR)$(mandir)/$(mansubdir)8/ssh-pkcs11-helper.8
	-rm -f $(DESTDIR)$(mandir)/$(mansubdir)8/ssh-sk-helper.8

regress-prep:
	$(MKDIR_P) `pwd`/regress/unittests/test_helper
	$(MKDIR_P) `pwd`/regress/unittests/authopt
	$(MKDIR_P) `pwd`/regress/unittests/bitmap
	$(MKDIR_P) `pwd`/regress/unittests/conversion
	$(MKDIR_P) `pwd`/regress/unittests/hostkeys
	$(MKDIR_P) `pwd`/regress/unittests/kex
	$(MKDIR_P) `pwd`/regress/unittests/match
	$(MKDIR_P) `pwd`/regress/unittests/misc
	$(MKDIR_P) `pwd`/regress/unittests/sshbuf
	$(MKDIR_P) `pwd`/regress/unittests/sshkey
	$(MKDIR_P) `pwd`/regress/unittests/sshsig
	$(MKDIR_P) `pwd`/regress/unittests/utf8
	$(MKDIR_P) `pwd`/regress/misc/sk-dummy
	[ -f `pwd`/regress/Makefile ] || \
	    ln -s `cd $(srcdir) && pwd`/regress/Makefile `pwd`/regress/Makefile

REGRESSLIBS=libssh.a $(LIBCOMPAT)

regress/modpipe$(EXEEXT): $(srcdir)/regress/modpipe.c $(REGRESSLIBS)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $(srcdir)/regress/modpipe.c \
	$(LDFLAGS) -lssh -lopenbsd-compat -lssh -lopenbsd-compat $(LIBS)

regress/setuid-allowed$(EXEEXT): $(srcdir)/regress/setuid-allowed.c $(REGRESSLIBS)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $(srcdir)/regress/setuid-allowed.c \
	$(LDFLAGS) -lssh -lopenbsd-compat -lssh -lopenbsd-compat $(LIBS)

regress/netcat$(EXEEXT): $(srcdir)/regress/netcat.c $(REGRESSLIBS)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $(srcdir)/regress/netcat.c \
	$(LDFLAGS) -lssh -lopenbsd-compat -lssh -lopenbsd-compat $(LIBS)

regress/check-perm$(EXEEXT): $(srcdir)/regress/check-perm.c $(REGRESSLIBS)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $(srcdir)/regress/check-perm.c \
	$(LDFLAGS) -lssh -lopenbsd-compat -lssh -lopenbsd-compat $(LIBS)

regress/mkdtemp$(EXEEXT): $(srcdir)/regress/mkdtemp.c $(REGRESSLIBS)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $(srcdir)/regress/mkdtemp.c \
	$(LDFLAGS) -lssh -lopenbsd-compat -lssh -lopenbsd-compat $(LIBS)

UNITTESTS_TEST_HELPER_OBJS=\
	regress/unittests/test_helper/test_helper.o \
	regress/unittests/test_helper/fuzz.o

regress/unittests/test_helper/libtest_helper.a: ${UNITTESTS_TEST_HELPER_OBJS}
	$(AR) rv $@ $(UNITTESTS_TEST_HELPER_OBJS)
	$(RANLIB) $@

UNITTESTS_TEST_SSHBUF_OBJS=\
	regress/unittests/sshbuf/tests.o \
	regress/unittests/sshbuf/test_sshbuf.o \
	regress/unittests/sshbuf/test_sshbuf_getput_basic.o \
	regress/unittests/sshbuf/test_sshbuf_getput_crypto.o \
	regress/unittests/sshbuf/test_sshbuf_misc.o \
	regress/unittests/sshbuf/test_sshbuf_fuzz.o \
	regress/unittests/sshbuf/test_sshbuf_getput_fuzz.o \
	regress/unittests/sshbuf/test_sshbuf_fixed.o

regress/unittests/sshbuf/test_sshbuf$(EXEEXT): ${UNITTESTS_TEST_SSHBUF_OBJS} \
    regress/unittests/test_helper/libtest_helper.a libssh.a
	$(LD) -o $@ $(LDFLAGS) $(UNITTESTS_TEST_SSHBUF_OBJS) \
	    regress/unittests/test_helper/libtest_helper.a \
	    -lssh -lopenbsd-compat -lssh -lopenbsd-compat $(LIBS)

UNITTESTS_TEST_SSHKEY_OBJS=\
	regress/unittests/sshkey/test_fuzz.o \
	regress/unittests/sshkey/tests.o \
	regress/unittests/sshkey/common.o \
	regress/unittests/sshkey/test_file.o \
	regress/unittests/sshkey/test_sshkey.o \
	$(SKOBJS)

regress/unittests/sshkey/test_sshkey$(EXEEXT): ${UNITTESTS_TEST_SSHKEY_OBJS} \
    regress/unittests/test_helper/libtest_helper.a libssh.a
	$(LD) -o $@ $(LDFLAGS) $(UNITTESTS_TEST_SSHKEY_OBJS) \
	    regress/unittests/test_helper/libtest_helper.a \
	    -lssh -lopenbsd-compat -lssh -lopenbsd-compat $(LIBS)

UNITTESTS_TEST_SSHSIG_OBJS=\
	sshsig.o \
	regress/unittests/sshsig/tests.o \
	$(SKOBJS)

regress/unittests/sshsig/test_sshsig$(EXEEXT): ${UNITTESTS_TEST_SSHSIG_OBJS} \
    regress/unittests/test_helper/libtest_helper.a libssh.a
	$(LD) -o $@ $(LDFLAGS) $(UNITTESTS_TEST_SSHSIG_OBJS) \
	    regress/unittests/test_helper/libtest_helper.a \
	    -lssh -lopenbsd-compat -lssh -lopenbsd-compat $(LIBS)

UNITTESTS_TEST_BITMAP_OBJS=\
	regress/unittests/bitmap/tests.o

regress/unittests/bitmap/test_bitmap$(EXEEXT): ${UNITTESTS_TEST_BITMAP_OBJS} \
    regress/unittests/test_helper/libtest_helper.a libssh.a
	$(LD) -o $@ $(LDFLAGS) $(UNITTESTS_TEST_BITMAP_OBJS) \
	    regress/unittests/test_helper/libtest_helper.a \
	    -lssh -lopenbsd-compat -lssh -lopenbsd-compat $(LIBS)

UNITTESTS_TEST_AUTHOPT_OBJS=\
	regress/unittests/authopt/tests.o \
	auth-options.o \
	$(SKOBJS)

regress/unittests/authopt/test_authopt$(EXEEXT): \
    ${UNITTESTS_TEST_AUTHOPT_OBJS} \
    regress/unittests/test_helper/libtest_helper.a libssh.a
	$(LD) -o $@ $(LDFLAGS) $(UNITTESTS_TEST_AUTHOPT_OBJS) \
	    regress/unittests/test_helper/libtest_helper.a \
	    -lssh -lopenbsd-compat -lssh -lopenbsd-compat $(LIBS)

UNITTESTS_TEST_CONVERSION_OBJS=\
	regress/unittests/conversion/tests.o

regress/unittests/conversion/test_conversion$(EXEEXT): \
    ${UNITTESTS_TEST_CONVERSION_OBJS} \
    regress/unittests/test_helper/libtest_helper.a libssh.a
	$(LD) -o $@ $(LDFLAGS) $(UNITTESTS_TEST_CONVERSION_OBJS) \
	    regress/unittests/test_helper/libtest_helper.a \
	    -lssh -lopenbsd-compat -lssh -lopenbsd-compat $(LIBS)

UNITTESTS_TEST_KEX_OBJS=\
	regress/unittests/kex/tests.o \
	regress/unittests/kex/test_kex.o \
	$(SKOBJS)

regress/unittests/kex/test_kex$(EXEEXT): ${UNITTESTS_TEST_KEX_OBJS} \
    regress/unittests/test_helper/libtest_helper.a libssh.a
	$(LD) -o $@ $(LDFLAGS) $(UNITTESTS_TEST_KEX_OBJS) \
	    regress/unittests/test_helper/libtest_helper.a \
	    -lssh -lopenbsd-compat -lssh -lopenbsd-compat $(LIBS)

UNITTESTS_TEST_HOSTKEYS_OBJS=\
	regress/unittests/hostkeys/tests.o \
	regress/unittests/hostkeys/test_iterate.o \
	$(SKOBJS)

regress/unittests/hostkeys/test_hostkeys$(EXEEXT): \
    ${UNITTESTS_TEST_HOSTKEYS_OBJS} \
    regress/unittests/test_helper/libtest_helper.a libssh.a
	$(LD) -o $@ $(LDFLAGS) $(UNITTESTS_TEST_HOSTKEYS_OBJS) \
	    regress/unittests/test_helper/libtest_helper.a \
	    -lssh -lopenbsd-compat -lssh -lopenbsd-compat $(LIBS)

UNITTESTS_TEST_MATCH_OBJS=\
	regress/unittests/match/tests.o

regress/unittests/match/test_match$(EXEEXT): \
    ${UNITTESTS_TEST_MATCH_OBJS} \
    regress/unittests/test_helper/libtest_helper.a libssh.a
	$(LD) -o $@ $(LDFLAGS) $(UNITTESTS_TEST_MATCH_OBJS) \
	    regress/unittests/test_helper/libtest_helper.a \
	    -lssh -lopenbsd-compat -lssh -lopenbsd-compat $(LIBS)

UNITTESTS_TEST_MISC_OBJS=\
	regress/unittests/misc/tests.o \
	regress/unittests/misc/test_parse.o \
	regress/unittests/misc/test_expand.o \
	regress/unittests/misc/test_convtime.o \
	regress/unittests/misc/test_argv.o

regress/unittests/misc/test_misc$(EXEEXT): \
    ${UNITTESTS_TEST_MISC_OBJS} \
    regress/unittests/test_helper/libtest_helper.a libssh.a
	$(LD) -o $@ $(LDFLAGS) $(UNITTESTS_TEST_MISC_OBJS) \
	    regress/unittests/test_helper/libtest_helper.a \
	    -lssh -lopenbsd-compat -lssh -lopenbsd-compat $(LIBS)

UNITTESTS_TEST_UTF8_OBJS=\
	regress/unittests/utf8/tests.o

regress/unittests/utf8/test_utf8$(EXEEXT): \
    ${UNITTESTS_TEST_UTF8_OBJS} \
    regress/unittests/test_helper/libtest_helper.a libssh.a
	$(LD) -o $@ $(LDFLAGS) $(UNITTESTS_TEST_UTF8_OBJS) \
	    regress/unittests/test_helper/libtest_helper.a \
	    -lssh -lopenbsd-compat -lssh -lopenbsd-compat $(LIBS)

# These all need to be compiled -fPIC, so they are treated differently.
SK_DUMMY_OBJS=\
	regress/misc/sk-dummy/sk-dummy.lo \
	regress/misc/sk-dummy/fatal.lo \
	ed25519.lo hash.lo ge25519.lo fe25519.lo sc25519.lo verify.lo

SK_DUMMY_LIBRARY=regress/misc/sk-dummy/sk-dummy.so

.c.lo: Makefile.in config.h
	$(CC) $(CFLAGS_NOPIE) $(PICFLAG) $(CPPFLAGS) -c $< -o $@

regress/misc/sk-dummy/sk-dummy.so: $(SK_DUMMY_OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) -fPIC -shared -o $@ $(SK_DUMMY_OBJS) \
	    -L. -Lopenbsd-compat -lopenbsd-compat $(LDFLAGS_NOPIE) $(LIBS)

regress-binaries: regress-prep $(LIBCOMPAT) \
	regress/modpipe$(EXEEXT) \
	regress/setuid-allowed$(EXEEXT) \
	regress/netcat$(EXEEXT) \
	regress/check-perm$(EXEEXT) \
	regress/mkdtemp$(EXEEXT) \
	$(SK_DUMMY_LIBRARY)

regress-unit-binaries: regress-prep $(REGRESSLIBS) \
	regress/unittests/authopt/test_authopt$(EXEEXT) \
	regress/unittests/bitmap/test_bitmap$(EXEEXT) \
	regress/unittests/conversion/test_conversion$(EXEEXT) \
	regress/unittests/hostkeys/test_hostkeys$(EXEEXT) \
	regress/unittests/kex/test_kex$(EXEEXT) \
	regress/unittests/match/test_match$(EXEEXT) \
	regress/unittests/misc/test_misc$(EXEEXT) \
	regress/unittests/sshbuf/test_sshbuf$(EXEEXT) \
	regress/unittests/sshkey/test_sshkey$(EXEEXT) \
	regress/unittests/sshsig/test_sshsig$(EXEEXT) \
	regress/unittests/utf8/test_utf8$(EXEEXT) \

tests:	file-tests t-exec interop-tests unit
	echo all tests passed

unit: regress-unit-binaries
	BUILDDIR=`pwd`; \
	cd $(srcdir)/regress || exit $$?; \
	$(MAKE) \
		.OBJDIR="$${BUILDDIR}/regress" \
		.CURDIR="`pwd`" \
		OBJ="$${BUILDDIR}/regress" \
		$@ && echo $@ tests passed

interop-tests t-exec file-tests: regress-prep regress-binaries $(TARGETS)
	BUILDDIR=`pwd`; \
	cd $(srcdir)/regress || exit $$?; \
	EGREP='/usr/bin/grep -E' \
	$(MAKE) \
		.OBJDIR="$${BUILDDIR}/regress" \
		.CURDIR="`pwd`" \
		BUILDDIR="$${BUILDDIR}" \
		OBJ="$${BUILDDIR}/regress/" \
		PATH="$${BUILDDIR}:$${PATH}" \
		TEST_ENV=MALLOC_OPTIONS="" \
		TEST_MALLOC_OPTIONS="" \
		TEST_SSH_SCP="$${BUILDDIR}/scp" \
		TEST_SSH_SSH="$${BUILDDIR}/ssh" \
		TEST_SSH_SSHD="$${BUILDDIR}/sshd" \
		TEST_SSH_SSHAGENT="$${BUILDDIR}/ssh-agent" \
		TEST_SSH_SSHADD="$${BUILDDIR}/ssh-add" \
		TEST_SSH_SSHKEYGEN="$${BUILDDIR}/ssh-keygen" \
		TEST_SSH_SSHPKCS11HELPER="$${BUILDDIR}/ssh-pkcs11-helper" \
		TEST_SSH_SSHKEYSCAN="$${BUILDDIR}/ssh-keyscan" \
		TEST_SSH_SFTP="$${BUILDDIR}/sftp" \
		TEST_SSH_PKCS11_HELPER="$${BUILDDIR}/ssh-pkcs11-helper" \
		TEST_SSH_SK_HELPER="$${BUILDDIR}/ssh-sk-helper" \
		TEST_SSH_SFTPSERVER="$${BUILDDIR}/sftp-server" \
		TEST_SSH_MODULI_FILE="$(abs_top_srcdir)/moduli" \
		TEST_SSH_PLINK="plink" \
		TEST_SSH_PUTTYGEN="puttygen" \
		TEST_SSH_CONCH="conch" \
		TEST_SSH_IPV6="yes" \
		TEST_SSH_UTF8="yes" \
		TEST_SSH_ECC="yes" \
		TEST_SHELL="${TEST_SHELL}" \
		EXEEXT="$(EXEEXT)" \
		$@ && echo all $@ passed

compat-tests: $(LIBCOMPAT)
	(cd openbsd-compat/regress && $(MAKE))

regressclean:
	if [ -f regress/Makefile ] && [ -r regress/Makefile ]; then \
		(cd regress && $(MAKE) clean) \
	fi

survey: survey.sh ssh
	@$(SHELL) ./survey.sh > survey
	@echo 'The survey results have been placed in the file "survey" in the'
	@echo 'current directory.  Please review the file then send with'
	@echo '"make send-survey".'

send-survey:	survey
	mail portable-survey@mindrot.org <survey

package: $(CONFIGFILES) $(MANPAGES) $(TARGETS)
	if [ "no" = yes ]; then \
		sh buildpkg.sh; \
	fi

# # Automatically generated by makedepend.
# Run "make depend" to rebuild.

# DO NOT DELETE
addr.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h addr.h
addrmatch.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h addr.h match.h log.h ssherr.h
atomicio.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h atomicio.h
audit-bsm.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h
audit-linux.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h
audit.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h
auth-bsdauth.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h
auth-krb5.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h xmalloc.h ssh.h packet.h openbsd-compat/sys-queue.h dispatch.h log.h ssherr.h sshbuf.h sshkey.h misc.h servconf.h uidswap.h hostfile.h auth.h auth-pam.h audit.h loginrec.h
auth-options.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h openbsd-compat/sys-queue.h xmalloc.h ssherr.h log.h sshbuf.h misc.h sshkey.h match.h ssh2.h auth-options.h
auth-pam.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h
auth-passwd.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h packet.h openbsd-compat/sys-queue.h dispatch.h sshbuf.h ssherr.h log.h misc.h servconf.h sshkey.h hostfile.h auth.h auth-pam.h audit.h loginrec.h auth-options.h
auth-rhosts.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h packet.h openbsd-compat/sys-queue.h dispatch.h uidswap.h pathnames.h log.h ssherr.h misc.h sshbuf.h sshkey.h servconf.h canohost.h hostfile.h auth.h auth-pam.h audit.h loginrec.h
auth-shadow.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h
auth-sia.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h
auth.o: authfile.h monitor_wrap.h compat.h channels.h
auth.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h xmalloc.h match.h groupaccess.h log.h ssherr.h sshbuf.h misc.h servconf.h openbsd-compat/sys-queue.h sshkey.h hostfile.h auth.h auth-pam.h audit.h loginrec.h auth-options.h canohost.h uidswap.h packet.h dispatch.h
auth2-chall.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h xmalloc.h ssh2.h sshkey.h hostfile.h auth.h auth-pam.h audit.h loginrec.h sshbuf.h packet.h openbsd-compat/sys-queue.h dispatch.h ssherr.h log.h misc.h servconf.h
auth2-gss.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h
auth2-hostbased.o: canohost.h monitor_wrap.h pathnames.h match.h
auth2-hostbased.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h xmalloc.h ssh2.h packet.h openbsd-compat/sys-queue.h dispatch.h kex.h mac.h crypto_api.h sshbuf.h log.h ssherr.h misc.h servconf.h compat.h sshkey.h hostfile.h auth.h auth-pam.h audit.h loginrec.h
auth2-kbdint.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h xmalloc.h packet.h openbsd-compat/sys-queue.h dispatch.h hostfile.h auth.h auth-pam.h audit.h loginrec.h log.h ssherr.h misc.h servconf.h
auth2-none.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h atomicio.h xmalloc.h sshkey.h hostfile.h auth.h auth-pam.h audit.h loginrec.h packet.h openbsd-compat/sys-queue.h dispatch.h log.h ssherr.h misc.h servconf.h compat.h ssh2.h monitor_wrap.h
auth2-passwd.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h packet.h openbsd-compat/sys-queue.h dispatch.h ssherr.h log.h sshkey.h hostfile.h auth.h auth-pam.h audit.h loginrec.h monitor_wrap.h misc.h servconf.h
auth2-pubkey.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h xmalloc.h ssh.h ssh2.h packet.h openbsd-compat/sys-queue.h dispatch.h kex.h mac.h crypto_api.h sshbuf.h log.h ssherr.h misc.h servconf.h compat.h sshkey.h hostfile.h auth.h auth-pam.h audit.h loginrec.h
auth2-pubkey.o: pathnames.h uidswap.h auth-options.h canohost.h monitor_wrap.h authfile.h match.h channels.h session.h sk-api.h
auth2.o: digest.h
auth2.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h atomicio.h xmalloc.h ssh2.h packet.h openbsd-compat/sys-queue.h dispatch.h log.h ssherr.h sshbuf.h misc.h servconf.h compat.h sshkey.h hostfile.h auth.h auth-pam.h audit.h loginrec.h pathnames.h monitor_wrap.h
authfd.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h xmalloc.h ssh.h sshbuf.h sshkey.h authfd.h cipher.h cipher-chachapoly.h chacha.h poly1305.h cipher-aesctr.h rijndael.h compat.h log.h ssherr.h atomicio.h misc.h
authfile.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h cipher.h cipher-chachapoly.h chacha.h poly1305.h cipher-aesctr.h rijndael.h ssh.h log.h ssherr.h authfile.h misc.h atomicio.h sshkey.h sshbuf.h krl.h
bitmap.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h bitmap.h
canohost.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h xmalloc.h packet.h openbsd-compat/sys-queue.h dispatch.h log.h ssherr.h canohost.h misc.h
chacha.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h chacha.h
channels.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h openbsd-compat/sys-queue.h xmalloc.h ssh.h ssh2.h ssherr.h sshbuf.h packet.h dispatch.h log.h misc.h channels.h compat.h canohost.h sshkey.h authfd.h pathnames.h match.h
cipher-aes.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h openbsd-compat/openssl-compat.h
cipher-aesctr.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h cipher-aesctr.h rijndael.h
cipher-chachapoly-libcrypto.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h
cipher-chachapoly.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h log.h ssherr.h sshbuf.h cipher-chachapoly.h chacha.h poly1305.h
cipher-ctr.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h
cipher.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h cipher.h cipher-chachapoly.h chacha.h poly1305.h cipher-aesctr.h rijndael.h misc.h sshbuf.h ssherr.h digest.h openbsd-compat/openssl-compat.h
cleanup.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h log.h ssherr.h
clientloop.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h openbsd-compat/sys-queue.h xmalloc.h ssh.h ssh2.h packet.h dispatch.h sshbuf.h compat.h channels.h sshkey.h cipher.h cipher-chachapoly.h chacha.h poly1305.h cipher-aesctr.h rijndael.h kex.h mac.h crypto_api.h
clientloop.o: myproposal.h log.h ssherr.h misc.h readconf.h clientloop.h sshconnect.h authfd.h atomicio.h sshpty.h match.h msg.h hostfile.h
compat.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h xmalloc.h packet.h openbsd-compat/sys-queue.h dispatch.h compat.h log.h ssherr.h match.h kex.h mac.h crypto_api.h
dh.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h
digest-libc.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h ssherr.h sshbuf.h digest.h
digest-openssl.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h
dispatch.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h ssh2.h log.h ssherr.h dispatch.h packet.h openbsd-compat/sys-queue.h compat.h
dns.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h xmalloc.h sshkey.h ssherr.h dns.h log.h digest.h
ed25519.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h crypto_api.h ge25519.h fe25519.h sc25519.h
entropy.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h
fatal.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h log.h ssherr.h
fe25519.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h fe25519.h crypto_api.h
ge25519.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h fe25519.h crypto_api.h sc25519.h ge25519.h ge25519_base.data
groupaccess.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h xmalloc.h groupaccess.h match.h log.h ssherr.h
gss-genr.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h
gss-serv-krb5.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h
gss-serv.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h
hash.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h crypto_api.h
hmac.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h sshbuf.h digest.h hmac.h
hostfile.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h xmalloc.h match.h sshkey.h hostfile.h log.h ssherr.h misc.h pathnames.h digest.h hmac.h sshbuf.h
kex.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h ssh.h ssh2.h atomicio.h version.h packet.h openbsd-compat/sys-queue.h dispatch.h compat.h cipher.h cipher-chachapoly.h chacha.h poly1305.h cipher-aesctr.h rijndael.h sshkey.h kex.h mac.h crypto_api.h log.h ssherr.h
kex.o: match.h misc.h monitor.h sshbuf.h digest.h
kexc25519.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h sshkey.h kex.h mac.h crypto_api.h sshbuf.h digest.h ssherr.h ssh2.h
kexdh.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h
kexecdh.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h ssherr.h
kexgen.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h sshkey.h kex.h mac.h crypto_api.h log.h ssherr.h packet.h openbsd-compat/sys-queue.h dispatch.h ssh2.h sshbuf.h digest.h
kexgex.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h
kexgexc.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h
kexgexs.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h
kexsntrup761x25519.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h ssherr.h
krl.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h ./openbsd-compat/sys-tree.h openbsd-compat/sys-queue.h sshbuf.h ssherr.h sshkey.h authfile.h misc.h log.h digest.h bitmap.h utf8.h krl.h
log.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h log.h ssherr.h match.h
loginrec.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h xmalloc.h sshkey.h hostfile.h ssh.h loginrec.h log.h ssherr.h atomicio.h packet.h openbsd-compat/sys-queue.h dispatch.h canohost.h auth.h auth-pam.h audit.h sshbuf.h
logintest.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h loginrec.h
mac.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h digest.h hmac.h umac.h mac.h misc.h ssherr.h sshbuf.h openbsd-compat/openssl-compat.h
match.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h xmalloc.h match.h misc.h
md5crypt.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h
misc.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h xmalloc.h misc.h log.h ssherr.h ssh.h sshbuf.h
moduli.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h
monitor.o: chacha.h poly1305.h cipher-aesctr.h rijndael.h kex.h mac.h crypto_api.h dh.h packet.h dispatch.h auth-options.h sshpty.h channels.h session.h sshlogin.h canohost.h log.h ssherr.h misc.h servconf.h monitor.h monitor_wrap.h monitor_fdpass.h compat.h ssh2.h authfd.h match.h sk-api.h
monitor.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h ./openbsd-compat/sys-tree.h openbsd-compat/sys-queue.h openbsd-compat/openssl-compat.h atomicio.h xmalloc.h ssh.h sshkey.h sshbuf.h hostfile.h auth.h auth-pam.h audit.h loginrec.h cipher.h cipher-chachapoly.h
monitor_fdpass.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h log.h ssherr.h monitor_fdpass.h
monitor_wrap.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h openbsd-compat/sys-queue.h xmalloc.h ssh.h sshbuf.h sshkey.h cipher.h cipher-chachapoly.h chacha.h poly1305.h cipher-aesctr.h rijndael.h kex.h mac.h crypto_api.h hostfile.h auth.h auth-pam.h audit.h
monitor_wrap.o: loginrec.h auth-options.h packet.h dispatch.h log.h ssherr.h monitor.h monitor_wrap.h atomicio.h monitor_fdpass.h misc.h channels.h session.h servconf.h
msg.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h sshbuf.h ssherr.h log.h atomicio.h msg.h misc.h
mux.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h openbsd-compat/sys-queue.h xmalloc.h log.h ssherr.h ssh.h ssh2.h pathnames.h misc.h match.h sshbuf.h channels.h msg.h packet.h dispatch.h monitor_fdpass.h sshpty.h sshkey.h readconf.h clientloop.h
nchan.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h openbsd-compat/sys-queue.h ssh2.h sshbuf.h ssherr.h packet.h dispatch.h channels.h compat.h log.h
packet.o: channels.h ssh.h packet.h dispatch.h sshbuf.h
packet.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h openbsd-compat/sys-queue.h xmalloc.h compat.h ssh2.h cipher.h cipher-chachapoly.h chacha.h poly1305.h cipher-aesctr.h rijndael.h sshkey.h kex.h mac.h crypto_api.h digest.h log.h ssherr.h canohost.h misc.h
platform-misc.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h
platform-pledge.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h
platform-tracing.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h log.h ssherr.h
platform.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h log.h ssherr.h misc.h servconf.h openbsd-compat/sys-queue.h sshkey.h hostfile.h auth.h auth-pam.h audit.h loginrec.h
poly1305.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h poly1305.h
progressmeter.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h progressmeter.h atomicio.h misc.h utf8.h
readconf.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h openbsd-compat/glob.h xmalloc.h ssh.h ssherr.h compat.h cipher.h cipher-chachapoly.h chacha.h poly1305.h cipher-aesctr.h rijndael.h pathnames.h log.h sshkey.h misc.h readconf.h match.h kex.h mac.h crypto_api.h
readconf.o: uidswap.h myproposal.h digest.h
readpass.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h xmalloc.h misc.h pathnames.h log.h ssherr.h ssh.h uidswap.h
rijndael.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h rijndael.h
sandbox-capsicum.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h
sandbox-darwin.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h
sandbox-null.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h
sandbox-pledge.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h
sandbox-rlimit.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h
sandbox-seccomp-filter.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h
sandbox-solaris.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h
sandbox-systrace.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h
sc25519.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h sc25519.h crypto_api.h
scp.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h xmalloc.h ssh.h atomicio.h pathnames.h log.h ssherr.h misc.h progressmeter.h utf8.h
servconf.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h openbsd-compat/glob.h openbsd-compat/sys-queue.h xmalloc.h ssh.h log.h ssherr.h sshbuf.h misc.h servconf.h compat.h pathnames.h cipher.h cipher-chachapoly.h chacha.h poly1305.h cipher-aesctr.h rijndael.h sshkey.h
servconf.o: kex.h mac.h crypto_api.h match.h channels.h groupaccess.h canohost.h packet.h dispatch.h hostfile.h auth.h auth-pam.h audit.h loginrec.h myproposal.h digest.h
serverloop.o: cipher-aesctr.h rijndael.h kex.h mac.h crypto_api.h hostfile.h auth.h auth-pam.h audit.h loginrec.h session.h auth-options.h serverloop.h
serverloop.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h openbsd-compat/sys-queue.h xmalloc.h packet.h dispatch.h sshbuf.h log.h ssherr.h misc.h servconf.h canohost.h sshpty.h channels.h compat.h ssh2.h sshkey.h cipher.h cipher-chachapoly.h chacha.h poly1305.h
session.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h openbsd-compat/sys-queue.h xmalloc.h ssh.h ssh2.h sshpty.h packet.h dispatch.h sshbuf.h ssherr.h match.h uidswap.h compat.h channels.h sshkey.h cipher.h cipher-chachapoly.h chacha.h poly1305.h cipher-aesctr.h
session.o: rijndael.h hostfile.h auth.h auth-pam.h audit.h loginrec.h auth-options.h authfd.h pathnames.h log.h misc.h servconf.h sshlogin.h serverloop.h canohost.h session.h kex.h mac.h crypto_api.h monitor_wrap.h sftp.h atomicio.h
sftp-client.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h openbsd-compat/sys-queue.h xmalloc.h ssherr.h sshbuf.h log.h atomicio.h progressmeter.h misc.h utf8.h sftp.h sftp-common.h sftp-client.h openbsd-compat/glob.h
sftp-common.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h xmalloc.h ssherr.h sshbuf.h log.h misc.h sftp.h sftp-common.h
sftp-glob.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h xmalloc.h sftp.h sftp-common.h sftp-client.h openbsd-compat/glob.h
sftp-realpath.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h
sftp-server-main.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h log.h ssherr.h sftp.h misc.h xmalloc.h
sftp-server.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h xmalloc.h sshbuf.h ssherr.h log.h misc.h match.h uidswap.h sftp.h sftp-common.h
sftp.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h xmalloc.h log.h ssherr.h pathnames.h misc.h utf8.h sftp.h sshbuf.h sftp-common.h sftp-client.h openbsd-compat/glob.h
sk-usbhid.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h
sntrup761.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h
srclimit.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h addr.h canohost.h log.h ssherr.h misc.h srclimit.h xmalloc.h
ssh-add.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h xmalloc.h ssh.h log.h ssherr.h sshkey.h sshbuf.h authfd.h authfile.h pathnames.h misc.h digest.h ssh-sk.h sk-api.h
ssh-agent.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h openbsd-compat/sys-queue.h xmalloc.h ssh.h ssh2.h sshbuf.h sshkey.h authfd.h compat.h log.h ssherr.h misc.h digest.h match.h msg.h pathnames.h ssh-pkcs11.h sk-api.h
ssh-dss.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h
ssh-ecdsa-sk.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h openbsd-compat/openssl-compat.h sshbuf.h ssherr.h digest.h sshkey.h
ssh-ecdsa.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h
ssh-ed25519-sk.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h crypto_api.h log.h ssherr.h sshbuf.h sshkey.h ssh.h digest.h
ssh-ed25519.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h crypto_api.h log.h ssherr.h sshbuf.h sshkey.h ssh.h
ssh-keygen.o: cipher-chachapoly.h chacha.h poly1305.h cipher-aesctr.h rijndael.h
ssh-keygen.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h xmalloc.h sshkey.h authfile.h sshbuf.h pathnames.h log.h ssherr.h misc.h match.h hostfile.h dns.h ssh.h ssh2.h ssh-pkcs11.h atomicio.h krl.h digest.h utf8.h authfd.h sshsig.h ssh-sk.h sk-api.h cipher.h
ssh-keyscan.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h openbsd-compat/sys-queue.h xmalloc.h ssh.h sshbuf.h sshkey.h cipher.h cipher-chachapoly.h chacha.h poly1305.h cipher-aesctr.h rijndael.h kex.h mac.h crypto_api.h compat.h myproposal.h packet.h dispatch.h log.h
ssh-keyscan.o: ssherr.h atomicio.h misc.h hostfile.h ssh_api.h ssh2.h dns.h
ssh-keysign.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h xmalloc.h log.h ssherr.h sshkey.h ssh.h ssh2.h misc.h sshbuf.h authfile.h msg.h canohost.h pathnames.h readconf.h uidswap.h
ssh-pkcs11-client.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h
ssh-pkcs11-helper.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h openbsd-compat/sys-queue.h xmalloc.h sshbuf.h log.h ssherr.h misc.h sshkey.h authfd.h ssh-pkcs11.h
ssh-pkcs11.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h log.h ssherr.h sshkey.h
ssh-rsa.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h
ssh-sk-client.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h log.h ssherr.h sshbuf.h sshkey.h msg.h digest.h pathnames.h ssh-sk.h misc.h
ssh-sk-helper.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h xmalloc.h log.h ssherr.h sshkey.h authfd.h misc.h sshbuf.h msg.h uidswap.h ssh-sk.h
ssh-sk.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h
ssh-xmss.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h
ssh.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h openbsd-compat/openssl-compat.h openbsd-compat/sys-queue.h xmalloc.h ssh.h ssh2.h canohost.h compat.h cipher.h cipher-chachapoly.h chacha.h poly1305.h cipher-aesctr.h rijndael.h packet.h dispatch.h sshbuf.h channels.h
ssh.o: sshkey.h authfd.h authfile.h pathnames.h clientloop.h log.h ssherr.h misc.h readconf.h sshconnect.h kex.h mac.h crypto_api.h sshpty.h match.h msg.h version.h myproposal.h utf8.h
ssh_api.o: authfile.h misc.h version.h myproposal.h sshbuf.h openbsd-compat/openssl-compat.h
ssh_api.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h ssh_api.h openbsd-compat/sys-queue.h cipher.h cipher-chachapoly.h chacha.h poly1305.h cipher-aesctr.h rijndael.h sshkey.h kex.h mac.h crypto_api.h ssh.h ssh2.h packet.h dispatch.h compat.h log.h ssherr.h
sshbuf-getput-basic.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h ssherr.h sshbuf.h
sshbuf-getput-crypto.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h
sshbuf-io.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h ssherr.h sshbuf.h atomicio.h
sshbuf-misc.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h ssherr.h sshbuf.h
sshbuf.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h ssherr.h sshbuf.h misc.h
sshconnect.o: authfd.h kex.h mac.h crypto_api.h
sshconnect.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h xmalloc.h hostfile.h ssh.h sshbuf.h packet.h openbsd-compat/sys-queue.h dispatch.h compat.h sshkey.h sshconnect.h log.h ssherr.h misc.h readconf.h atomicio.h dns.h monitor_fdpass.h ssh2.h version.h authfile.h
sshconnect2.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h openbsd-compat/sys-queue.h xmalloc.h ssh.h ssh2.h sshbuf.h packet.h dispatch.h compat.h cipher.h cipher-chachapoly.h chacha.h poly1305.h cipher-aesctr.h rijndael.h sshkey.h kex.h mac.h crypto_api.h
sshconnect2.o: myproposal.h sshconnect.h authfile.h dh.h authfd.h log.h ssherr.h misc.h readconf.h match.h canohost.h msg.h pathnames.h uidswap.h hostfile.h utf8.h ssh-sk.h sk-api.h
sshd.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h ./openbsd-compat/sys-tree.h openbsd-compat/sys-queue.h xmalloc.h ssh.h ssh2.h sshpty.h packet.h dispatch.h log.h ssherr.h sshbuf.h misc.h match.h servconf.h uidswap.h compat.h cipher.h cipher-chachapoly.h chacha.h
sshd.o: poly1305.h cipher-aesctr.h rijndael.h digest.h sshkey.h kex.h mac.h crypto_api.h myproposal.h authfile.h pathnames.h atomicio.h canohost.h hostfile.h auth.h auth-pam.h audit.h loginrec.h authfd.h msg.h channels.h session.h monitor.h monitor_wrap.h ssh-sandbox.h auth-options.h version.h sk-api.h srclimit.h dh.h
ssherr.o: ssherr.h
sshkey-xmss.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h
sshkey.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h crypto_api.h ssh2.h ssherr.h misc.h sshbuf.h cipher.h cipher-chachapoly.h chacha.h poly1305.h cipher-aesctr.h rijndael.h digest.h sshkey.h match.h ssh-sk.h openbsd-compat/openssl-compat.h
sshlogin.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h sshlogin.h ssherr.h loginrec.h log.h sshbuf.h misc.h servconf.h openbsd-compat/sys-queue.h
sshpty.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h sshpty.h log.h ssherr.h misc.h
sshsig.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h authfd.h authfile.h log.h ssherr.h misc.h sshbuf.h sshsig.h sshkey.h match.h digest.h
sshtty.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h sshpty.h
ttymodes.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h packet.h openbsd-compat/sys-queue.h dispatch.h log.h ssherr.h compat.h sshbuf.h ttymodes.h
uidswap.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h log.h ssherr.h uidswap.h xmalloc.h
umac.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h xmalloc.h umac.h misc.h rijndael.h
umac128.o: umac.c includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h xmalloc.h umac.h misc.h rijndael.h
utf8.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h utf8.h
verify.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h crypto_api.h
xmalloc.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h xmalloc.h log.h ssherr.h
xmss_commons.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h
xmss_fast.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h
xmss_hash.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h
xmss_hash_address.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h
xmss_wots.o: includes.h config.h defines.h platform.h openbsd-compat/openbsd-compat.h openbsd-compat/base64.h openbsd-compat/sigact.h openbsd-compat/readpassphrase.h openbsd-compat/vis.h openbsd-compat/getrrsetbyname.h openbsd-compat/sha1.h openbsd-compat/sha2.h openbsd-compat/md5.h openbsd-compat/blf.h openbsd-compat/fnmatch.h openbsd-compat/getopt.h openbsd-compat/bsd-misc.h openbsd-compat/bsd-setres_id.h openbsd-compat/bsd-signal.h openbsd-compat/bsd-statvfs.h openbsd-compat/bsd-waitpid.h openbsd-compat/bsd-poll.h openbsd-compat/fake-rfc2553.h openbsd-compat/bsd-cygwin_util.h openbsd-compat/port-aix.h openbsd-compat/port-irix.h openbsd-compat/port-linux.h openbsd-compat/port-solaris.h openbsd-compat/port-net.h openbsd-compat/port-uw.h openbsd-compat/bsd-nextstep.h entropy.h
