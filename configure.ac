# -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([crypt4gh], [1.0], [silverdaz@gmail.com])

AC_CONFIG_SRCDIR([main.c])
AC_CONFIG_HEADER([config.h])

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
	sys/types.h \
	stdint.h \
	stdlib.h \
	stdio.h \
	unistd.h \
	termios.h \
	fcntl.h \
	string.h \
	errno.h \
	sys/stat.h \
])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_INLINE

dnl # Checks for library functions.
dnl AC_CHECK_FUNCS([memcpy strerror])
dnl AC_FUNC_MALLOC

#######################################################

# Check for  long long datatypes
AC_TYPE_OFF_T
AC_CHECK_TYPES([unsigned long long])

AC_CHECK_SIZEOF([int])

# More checks for data types
AC_CACHE_CHECK([for uintXX_t types], ac_cv_have_uintxx_t, [
		AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#include <sys/types.h>
			]], [[
	uint8_t a;
	uint32_t c;
	a = b = c = 1;
			]])],
		[ ac_cv_have_uintxx_t="yes" ], [ ac_cv_have_uintxx_t="no"
		])
	])
if test "x$ac_cv_have_uintxx_t" = "xyes" ; then
	AC_DEFINE([HAVE_UINTXX_T], [1],
		[define if you have uintxx_t data type])
fi

if (test -z "$have_uintxx_t" && \
	   test "x$ac_cv_header_stdint_h" = "xyes")
then
    AC_MSG_CHECKING([for uintXX_t types in stdint.h])
	AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[ #include <stdint.h> ]],
	[[ uint8_t a; uint32_t b; a = b = 1;]])],
		[
			AC_DEFINE([HAVE_UINTXX_T])
			AC_MSG_RESULT([yes])
		], [ AC_MSG_RESULT([no])
	])
fi

AC_CACHE_CHECK([for size_t], ac_cv_have_size_t, [
	AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[ #include <sys/types.h> ]],
	[[ size_t foo; foo = 1235; ]])],
	[ ac_cv_have_size_t="yes" ], [ ac_cv_have_size_t="no"
	])
])
if test "x$ac_cv_have_size_t" = "xyes" ; then
	AC_DEFINE([HAVE_SIZE_T], [1], [define if you have size_t data type])
fi

#######################################################


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

#######################################################

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
