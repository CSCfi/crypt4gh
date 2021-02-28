# -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([crypt4gh], [1.0], [silverdaz@gmail.com])

AC_CONFIG_SRCDIR([main.c])

# AC_CONFIG_AUX_DIR([build-aux])

# Checks for programs.
AC_PROG_CC #([cc clang gcc])
AC_CHECK_TOOLS([install])

# First of all, we need libsodium
AC_SEARCH_LIBS([sodium_malloc], [sodium], [], [AC_ERROR("libsodium is required. Install it from https://libsodium.org/.")])

# We then need to auxiliary Crypt4GH libraries
AC_SEARCH_LIBS([crypt4gh_encrypt], [crypt4gh], [], [AC_ERROR("libcrypt4gh is required. Install it from https://github.com/silverdaz/libcrypt4gh.")])
AC_SEARCH_LIBS([crypt4gh_c4gh_public_key_from_blob], [c4gh-keys], [], [AC_ERROR("libc4gh-keys is required. Install it from https://github.com/silverdaz/libcrypt4gh-keys.")])

# Checks for header files.
AC_CHECK_HEADERS([\
	stddef.h \
	stdint.h \
	stdlib.h \
	stdio.h \
	unistd.h \
	termios.h \
	fcntl.h \
	string.h \
	errno.h \
	sys/stat.h \
	sys/types.h \
])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_INLINE
AC_TYPE_OFF_T
AC_TYPE_SIZE_T
AC_TYPE_UINT32_T
AC_TYPE_UINT8_T

# Checks for library functions.
AC_CHECK_FUNCS([memcpy strerror])
AC_FUNC_MALLOC

dnl # Allow user to specify debug level
dnl AC_ARG_WITH([debug],
dnl 	[  --with-debug           Specify additional flags to pass to compiler],
dnl 	[
dnl 		if test "$withval" -ge 1 && test "$withval" -le 3 ; then \
dnl 			CFLAGS="$CFLAGS -g -DDEBUG=$withval"
dnl 		elif test "x$withval" == "xyes"; then
dnl 			CFLAGS="$CFLAGS -g -DDEBUG=1"
dnl 		fi
dnl 	])

AC_CONFIG_FILES([Makefile])

AC_SUBST([DEPEND], [$(cat $srcdir/.depend)])

dnl CFLAGS="$debug_flag $CFLAGS"

AC_OUTPUT

# Print summary of options

echo ""
echo "            Compiler: ${CC}"
echo "      Compiler flags: ${CFLAGS}"
echo "  Preprocessor flags: ${CPPFLAGS}"
echo "                LIBS: ${LIBS}"

echo ""
