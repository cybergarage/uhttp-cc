###################################################################
#
# uHTTP for C++
#
# Copyright (C) Satoshi Konno 2002-2012
#
# This is licensed under BSD-style license, see file COPYING.
#
###################################################################

AC_CONFIG_AUX_DIR(config)
AM_CONFIG_HEADER(config.h)

AC_INIT([uhttpcc], [0.6])
AC_CONFIG_SRCDIR([include/uhttp/http/HTTP.h])
AM_INIT_AUTOMAKE([subdir-objects])

##############################
# Checks for programs.
##############################

AC_PROG_CC
AC_PROG_CXX
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_AWK
AC_PROG_RANLIB
AC_LANG_CPLUSPLUS

##############################
# Checks for header files.
##############################

AC_HEADER_STDC
AC_CHECK_HEADERS([limits.h stdlib.h string.h])
AC_CHECK_HEADERS([arpa/inet.h netdb.h netinet/in.h sys/param.h sys/socket.h])
AC_CHECK_HEADERS([unistd.h])
AC_CHECK_HEADERS([ulimit.h sys/resource.h])

##############################
# Checks for iconv
##############################

AC_CHECK_FUNCS([iconv])
AC_CHECK_HEADERS([iconv.h])
AC_CHECK_LIB([iconv],[main])

##############################
# Checks for pthread
##############################

AC_CHECK_HEADERS([pthread.h],,[AC_MSG_ERROR(uHTTP needs POSIX thread library)])
AC_CHECK_LIB([pthread],[main])

##############################
# Checks for typedefs, structures, and compiler characteristics.
##############################

#AC_HEADER_STDBOOL
AC_C_CONST
AC_C_INLINE
AC_STRUCT_TM

##############################
# Checks for Network functions
##############################

AC_CHECK_FUNCS([socket])
AC_CHECK_FUNCS([inet_ntoa])
AC_CHECK_HEADERS([ifaddrs.h])
AC_CHECK_FUNCS([getifaddrs])

AC_MSG_CHECKING(for socklen_t)
AC_TRY_COMPILE([
#include <sys/types.h>
#include <sys/socket.h>
socklen_t foosocket;
],
[],
[AC_MSG_RESULT(yes)
AC_DEFINE([HAVE_SOCKLEN_T],1,[SOCKLEN_T])],
[AC_MSG_RESULT(no)]
)

AC_MSG_CHECKING(for SO_NOSIGPIPE)
AC_TRY_COMPILE([
#include <sys/types.h>
#include <sys/socket.h>
int sockOpt = SO_NOSIGPIPE;
],
[],
[AC_MSG_RESULT(yes)
AC_DEFINE([HAVE_SO_NOSIGPIPE],1,[SO_NOSIGPIPE])],
[AC_MSG_RESULT(no)]
)

AC_CHECK_DECL()

##############################
# Checks for C++ stream.
##############################

AC_CHECK_HEADERS([sstream])

AC_MSG_CHECKING(for std::cout)
AC_TRY_COMPILE([
#include <iostream>
void testFunc(){
std::cout << "" << std::endl;
}
],
[],
[AC_MSG_RESULT(yes)
AC_DEFINE([HAVE_STD_COUT],1,[STD_COUT])],
[AC_MSG_RESULT(no)]
)

##############################
# Checks for shared_ptr
##############################

AC_MSG_CHECKING(for std::shared_ptr)
AC_TRY_COMPILE([
#include <iostream>
void testFunc(){
std::shared_ptr<int> p(new int(0));
}
],
[],
[AC_MSG_RESULT(yes)
AC_DEFINE([HAVE_STD_SHRAEDPTR],1,[HAVE_STD_SHAREDPTR])],
[AC_MSG_RESULT(no)]
)

AC_MSG_CHECKING(for boost::shared_ptr)
AC_TRY_COMPILE([
#include <boost/shared_ptr.hpp>
void testFunc(){
boost::shared_ptr<int> p(new int(0));
}
],
[],
[AC_MSG_RESULT(yes)
AC_DEFINE([HAVE_BOOST_SHRAEDPTR],1,[HAVE_BOOST_SHAREDPTR])],
[AC_MSG_RESULT(no)]
)

##############################
# Checks for other functions.
##############################

AC_CHECK_FUNCS([fopen])
AC_CHECK_FUNCS([memset])
AC_CHECK_FUNCS([realpath])
AC_CHECK_FUNCS([localtime_r])
AC_CHECK_FUNCS([gmtime_r])
AC_CHECK_FUNCS([snprintf])
AC_CHECK_FUNCS([strchr])
AC_CHECK_FUNCS([uname])

##############################
# Checks for enable options.
##############################

#AC_ARG_ENABLE([examples], AC_HELP_STRING([--enable-examples], [ builds examples (default = no) ]), [build_examples="yes"], [])
#AM_CONDITIONAL(EXAMPLES,test "$build_examples" = yes)
#if [ test "$build_examples" = yes ]; then
#fi

AC_ARG_ENABLE([debug], AC_HELP_STRING([--enable-debug], [ enable debugging (default = no) ]), [debug="yes"], [])
AM_CONDITIONAL(DEBUG, test "$debug" = "yes")

AC_ARG_ENABLE([tests], AC_HELP_STRING([--enable-tests], [ build tests (default = no) ]), [build_tests="yes"], [])
AM_CONDITIONAL(UNITTESTS, test "$build_tests" = "yes")
if [ test "$build_tests" = yes ]; then
	AC_CHECK_LIB([boost_unit_test_framework-mt],[main],,[AC_MSG_ERROR(uHTTP tests need boost::unit_test_framework)])
	AC_CHECK_LIB([boost_system-mt],[main],,[AC_MSG_ERROR(uHTTP tests need boost::system)])
	AC_CHECK_LIB([boost_thread-mt],[main],,[AC_MSG_ERROR(uHTTP tests need boost::thread)])
	AC_CHECK_LIB([boost_filesystem-mt],[main],,[AC_MSG_ERROR(uHTTP tests need boost::filesystem)])
fi

##############################
# Checks libraries for examples
##############################

AC_CHECK_LIB([edit],[main],,[AC_MSG_ERROR(uHTTP needs libedit)])

##############################
# Makefiles
##############################

AC_OUTPUT([
Makefile
include/Makefile
lib/Makefile
lib/unix/Makefile
examples/Makefile
examples/httpget/Makefile
examples/httpget/unix/Makefile
examples/fsserver/Makefile
examples/fsserver/unix/Makefile
tests/Makefile
tests/unix/Makefile
])
