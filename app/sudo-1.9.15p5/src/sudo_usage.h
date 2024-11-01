/*
 * SPDX-License-Identifier: ISC
 *
 * Copyright (c) 2007-2010, 2013, 2015, 2017, 2020-2023
 *	Todd C. Miller <Todd.Miller@sudo.ws>
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
 */

#ifndef SUDO_USAGE_H
#define SUDO_USAGE_H

/*
 * Usage strings for sudo.  These are here because we
 * need to be able to substitute values from configure.
 */
static const char *sudo_usage1[] = {
    "-h | -K | -k | -V",
    NULL
};
static const char *sudo_usage2[] = {
    "-v [-ABkNnS] [-g group] [-h host] [-p prompt] [-u user]",
    NULL
};
static const char *sudo_usage3[] = {
    "-l [-ABkNnS] [-g group] [-h host] [-p prompt] [-U user]",
    "[-u user] [command [arg ...]]",
    NULL
};
static const char *sudo_usage4[] = {
    "[-ABbEHkNnPS] [-C num] [-D directory]",
    "[-g group] [-h host] [-p prompt] [-R directory] [-T timeout]",
    "[-u user] [VAR=value] [-i | -s] [command [arg ...]]",
    NULL
};
static const char *sudo_usage5[] = {
    "-e [-ABkNnS] [-C num] [-D directory]",
    "[-g group] [-h host] [-p prompt] [-R directory] [-T timeout]",
    "[-u user] file ...",
    NULL
};
static const char * const *sudo_usage[] = {
    sudo_usage1,
    sudo_usage2,
    sudo_usage3,
    sudo_usage4,
    sudo_usage5,
    NULL
};

static const char *sudoedit_usage1[] = {
    "-h | -V",
    NULL
};
static const char *sudoedit_usage2[] = {
    /* Same as sudo_usage5 but no -e flag. */
    "[-ABkNnS] [-C num] [-D directory]",
    "[-g group] [-h host] [-p prompt] [-R directory] [-T timeout]",
    "[-u user] file ...",
    NULL
};
static const char * const *sudoedit_usage[] = {
    sudoedit_usage1,
    sudoedit_usage2,
    NULL
};

#endif /* SUDO_USAGE_H */
