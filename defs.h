#ifndef __CRYPT4GH_DEFS_H_INCLUDED__
#define __CRYPT4GH_DEFS_H_INCLUDED__

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifndef _GNU_SOURCE
#define _GNU_SOURCE /* activate extra prototypes for glibc */
#endif

#ifdef HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif

#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif

#ifdef HAVE_STDINT_H
# include <stdint.h>
#endif

/* Constants */

#ifndef STDIN_FILENO
# define STDIN_FILENO    0
#endif
#ifndef STDOUT_FILENO
# define STDOUT_FILENO   1
#endif
#ifndef STDERR_FILENO
# define STDERR_FILENO   2
#endif

/* Types */

#ifndef HAVE_STDINT_H
#    ifndef HAVE_UINTXX_T
typedef unsigned char uint8_t;
#        if (SIZEOF_INT == 4)
typedef unsigned int uint32_t;
#        else
#            error "32 bit int type not found."
#        endif
#    endif
#endif

#ifndef HAVE_SYS_TYPES_H
#    ifndef HAVE_SIZE_T
typedef unsigned int size_t;
#    define HAVE_SIZE_T
#    endif /* HAVE_SIZE_T */
#endif

/* Macros */

#if !defined(__GNUC__) || (__GNUC__ < 2)
# define __attribute__(x)
#endif /* !defined(__GNUC__) || (__GNUC__ < 2) */

#if !defined(HAVE_ATTRIBUTE__NONNULL__) && !defined(__nonnull__)
# define __nonnull__(x)
#endif

/* Function replacement / compatibility hacks */

#if !defined(HAVE___func__) && defined(HAVE___FUNCTION__)
#  define __func__ __FUNCTION__
#elif !defined(HAVE___func__)
#  define __func__ ""
#endif


/* Crypt4GH contants */
#include <sodium.h>

#define CRYPT4GH_SESSION_KEY_SIZE   crypto_aead_chacha20poly1305_IETF_KEYBYTES


#endif /* !__CRYPT4GH_DEFS_H_INCLUDED__ */
