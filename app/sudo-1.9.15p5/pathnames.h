/* pathnames.h.  Generated from pathnames.h.in by configure.  */
/*
 * SPDX-License-Identifier: ISC
 *
 * Copyright (c) 1996, 1998, 1999, 2001, 2004, 2005, 2007-2021
 *	Todd C. Miller <Todd.Miller@sudo.ws>.
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 * Sponsored in part by the Defense Advanced Research Projects
 * Agency (DARPA) and Air Force Research Laboratory, Air Force
 * Materiel Command, USAF, under agreement number F39502-99-1-0512.
 */

/*
 *  Pathnames to programs and files used by sudo.
 */

#ifdef HAVE_PATHS_H
# include <paths.h>
#endif /* HAVE_PATHS_H */

#ifdef HAVE_MAILLOCK_H
# include <maillock.h>
#endif /* HAVE_MAILLOCK_H */

#ifndef _PATH_DEV
# define _PATH_DEV		"/dev/"
#endif /* _PATH_DEV */

#ifndef _PATH_TTY
# define _PATH_TTY		_PATH_DEV "tty"
#endif /* _PATH_TTY */

#ifndef _PATH_DEVNULL
# define _PATH_DEVNULL		_PATH_DEV "null"
#endif /* _PATH_DEVNULL */

#ifndef _PATH_DEFPATH
# define _PATH_DEFPATH		"/usr/bin:/bin"
#endif /* _PATH_DEFPATH */

#ifndef _PATH_STDPATH
# define _PATH_STDPATH		"/usr/bin:/bin:/usr/sbin:/sbin"
#endif /* _PATH_STDPATH */

/* Use /etc/environment on AIX or Linux w/o PAM (where pam_env handles it). */
#if defined(_AIX) || (defined(__linux__) && !defined(HAVE_PAM))
# define _PATH_ENVIRONMENT	"/etc/environment"
#endif /* _PATH_ENVIRONMENT */

/*
 * The following paths are controlled via the configure script.
 */

/*
 * NOTE: _PATH_SUDO_CONF is usually overridden by the Makefile.
 */
#ifndef _PATH_SUDO_CONF
# define _PATH_SUDO_CONF "/etc/sudo.conf"
#endif /* _PATH_SUDO_CONF */

/*
 * NOTE: _PATH_SUDOERS is usually overridden by the Makefile.
 */
#ifndef _PATH_SUDOERS
# define _PATH_SUDOERS "/etc/sudoers"
#endif /* _PATH_SUDOERS */

/*
 * NOTE: _PATH_CVTSUDOERS_CONF is usually overridden by the Makefile.
 */
#ifndef _PATH_CVTSUDOERS_CONF
# define _PATH_CVTSUDOERS_CONF "/etc/cvtsudoers.conf"
#endif /* _PATH_CVTSUDOERS_CONF */

/*
 * NOTE: _PATH_SUDO_LOGSRVD_CONF is usually overridden by the Makefile.
 */
#ifndef _PATH_SUDO_LOGSRVD_CONF
# define _PATH_SUDO_LOGSRVD_CONF "/etc/sudo_logsrvd.conf"
#endif /* _PATH_SUDO_LOGSRVD_CONF */

/*
 * Where sudo_logsrvd stores its pid file files.  Defaults to
 * /var/run/sudo/sudo_logsrvd.pid, /var/db/sudo/sudo_logsrvd.pid,
 * /var/lib/sudo/sudo_logsrvd.pid, /var/adm/sudo/sudo_logsrvd.pid or
 * /usr/adm/sudo/sudo_logsrvd.pid depending on what exists on the system.
 */
#ifndef _PATH_SUDO_LOGSRVD_PID
# define _PATH_SUDO_LOGSRVD_PID "/run/sudo/sudo_logsrvd.pid"
#endif /* _PATH_SUDO_LOGSRVD_PID */

/*
 * Where to store the time stamp files.  Defaults to /var/run/sudo/ts,
 * /var/db/sudo/ts, /var/lib/sudo/ts, /var/adm/sudo/ts or /usr/adm/sudo/ts
 * depending on what exists on the system.
 */
#ifndef _PATH_SUDO_TIMEDIR
# define _PATH_SUDO_TIMEDIR "/run/sudo/ts"
#endif /* _PATH_SUDO_TIMEDIR */

/*
 * Where to store the lecture status files.  Defaults to /var/db/sudo/lectured,
 * /var/lib/sudo/lectured, /var/adm/sudo/lectured or /usr/adm/sudo/lectured
 * depending on what exists on the system.
 */
#ifndef _PATH_SUDO_LECTURE_DIR
# define _PATH_SUDO_LECTURE_DIR "/var/lib/sudo/lectured"
#endif /* _PATH_SUDO_LECTURE_DIR */

/*
 * Where to put the I/O log files.  Defaults to /var/log/sudo-io,
 * /var/adm/sudo-io or /usr/adm/sudo-io depending on what exists.
 */
#ifndef _PATH_SUDO_IO_LOGDIR
# define _PATH_SUDO_IO_LOGDIR "/var/log/sudo-io"
#endif /* _PATH_SUDO_IO_LOGDIR */

/*
 * Where to put the audit and other log files.  Defaults to /var/log,
 * /var/adm or /usr/adm depending on what exists.
 */
#ifndef _PATH_SUDO_LOGDIR
# define _PATH_SUDO_LOGDIR "/var/log"
#endif /* _PATH_SUDO_LOGDIR */

/*
 * Where to store sudo_logsrvd relay temporary files. Defaults to
 * /var/log/sudo_logsrvd, /var/adm/sudo_logsrvd or /usr/adm/sudo_logsrvd
 * depending on what exists.
 */
#ifndef _PATH_SUDO_RELAY_DIR
# define _PATH_SUDO_RELAY_DIR "/var/log/sudo_logsrvd"
#endif /* _PATH_SUDO_RELAY_DIR */

/*
 * Where to put the sudo log file when logging to a file.  Defaults to
 * /var/log/sudo.log if /var/log exists, else /var/adm/sudo.log.
 */
#ifndef _PATH_SUDO_LOGFILE
# define _PATH_SUDO_LOGFILE "/var/log/sudo.log"
#endif /* _PATH_SUDO_LOGFILE */

/*
 * The path to an Ubuntu-style admin flag file that is created the
 * first time a user runs sudo.
 */
#ifndef _PATH_SUDO_ADMIN_FLAG
/* # undef _PATH_SUDO_ADMIN_FLAG */
#endif /* _PATH_SUDO_ADMIN_FLAG */

#ifndef _PATH_SUDO_SENDMAIL
/* # undef _PATH_SUDO_SENDMAIL */
#endif /* _PATH_SUDO_SENDMAIL */

#ifndef _PATH_SUDO_INTERCEPT
/* # undef _PATH_SUDO_INTERCEPT */
#endif /* _PATH_SUDO_INTERCEPT */

#ifndef _PATH_SUDO_NOEXEC
/* # undef _PATH_SUDO_NOEXEC */
#endif /* _PATH_SUDO_NOEXEC */

#ifndef _PATH_SUDO_ASKPASS
# define _PATH_SUDO_ASKPASS NULL
#endif /* _PATH_SUDO_ASKPASS */

#ifndef _PATH_SUDO_PLUGIN_DIR
# define _PATH_SUDO_PLUGIN_DIR NULL
#endif /* _PATH_SUDO_PLUGIN_DIR */

#ifndef _PATH_SUDO_DEVSEARCH
# define _PATH_SUDO_DEVSEARCH _PATH_DEV "pts:" _PATH_DEV "vt:" _PATH_DEV "term:" _PATH_DEV "zcons:" _PATH_DEV "pty:" _PATH_DEV "" 
#endif /* _PATH_SUDO_DEVSEARCH */

#ifndef _PATH_SUDOERS_PLUGIN
# define _PATH_SUDOERS_PLUGIN "sudoers.so"
#endif /* _PATH_SUDOERS_PLUGIN */

#ifndef _PATH_ASAN_LIB
/* # undef _PATH_ASAN_LIB */
#endif /* _PATH_ASAN_LIB */

#ifndef _PATH_VI
# define _PATH_VI "/usr/bin/vi"
#endif /* _PATH_VI */

#ifndef _PATH_MV
# define _PATH_MV "/usr/bin/mv"
#endif /* _PATH_MV */

#ifndef _PATH_BSHELL
# define _PATH_BSHELL "/usr/bin/sh"
#endif /* _PATH_BSHELL */

#ifndef _PATH_TMP
# define _PATH_TMP	"/tmp/"
#endif /* _PATH_TMP */

#ifndef _PATH_VARTMP
# define _PATH_VARTMP	"/var/tmp/"
#endif /* _PATH_VARTMP */

#ifndef _PATH_USRTMP
# define _PATH_USRTMP	"/usr/tmp/"
#endif /* _PATH_USRTMP */

#ifndef _PATH_MAILDIR
/* # undef _PATH_MAILDIR */
#endif /* _PATH_MAILDIR */

#ifndef _PATH_UTMP
/* # undef _PATH_UTMP */
#endif /* _PATH_UTMP */

#ifndef _PATH_SUDO_SESH
# define _PATH_SUDO_SESH NULL
#endif /* _PATH_SUDO_SESH */

#ifndef _PATH_LDAP_CONF
# define _PATH_LDAP_CONF "/etc/ldap.conf"
#endif /* _PATH_LDAP_CONF */

#ifndef _PATH_LDAP_SECRET
# define _PATH_LDAP_SECRET "/etc/ldap.secret"
#endif /* _PATH_LDAP_SECRET */

#ifndef _PATH_SSSD_CONF
# define _PATH_SSSD_CONF "/etc/sssd/sssd.conf"
#endif /* _PATH_SSSD_CONF */

#ifndef _PATH_SSSD_LIB
# define _PATH_SSSD_LIB ""LIBDIR""
#endif /* _PATH_SSSD_LIB */

#ifndef _PATH_NSSWITCH_CONF
# define _PATH_NSSWITCH_CONF "/etc/nsswitch.conf"
#endif /* _PATH_NSSWITCH_CONF */

#ifndef _PATH_NETSVC_CONF
/* # undef _PATH_NETSVC_CONF */
#endif /* _PATH_NETSVC_CONF */

#ifndef _PATH_ZONEINFO
# define _PATH_ZONEINFO "/usr/share/zoneinfo"
#endif /* _PATH_ZONEINFO */

/* On AIX, _PATH_BSHELL in paths.h is /usr/bin/bsh but we want /usr/bin/sh */
#ifndef _PATH_SUDO_BSHELL
# if defined(_AIX) && defined(HAVE_PATHS_H)
#  define _PATH_SUDO_BSHELL "/usr/bin/sh"
# else
#  define _PATH_SUDO_BSHELL _PATH_BSHELL
# endif
#endif /* _PATH_SUDO_BSHELL */
