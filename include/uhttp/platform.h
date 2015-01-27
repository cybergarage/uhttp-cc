/******************************************************************
 *
 * uHTTP for C++
 *
 * Copyright (C) Satoshi Konno 2002
 *
 * This is licensed under BSD-style license, see file COPYING.
 *
 ******************************************************************/

#ifndef _UHTTP_PLATFORM_H_
#define _UHTTP_PLATFORM_H_

#ifdef HAVE_CONFIG_H
#  include "config.h"
#endif

#if (defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201103L)) || defined(__APPLE__)
#define HAVE_STD_SHRAEDPTR 1
#define StdSharedPtr std::shared_ptr
#endif

#if !defined(HAVE_STD_SHRAEDPTR)
#include <boost/shared_ptr.hpp>
#define StdSharedPtr boost::shared_ptr
#endif

#endif
