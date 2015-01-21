/******************************************************************
*
* Round for C++
*
* Copyright (C) Satoshi Konno 2015
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef _ROUNDCC_PLATFORM_H_
#define _ROUNDCC_PLATFORM_H_

#ifdef HAVE_CONFIG_H
#  include "config.h"
#endif

#define ROUND_USE_JSON_PARSER_JANSSON 1
#if defined(__APPLE__)
#define ROUND_USE_JANSSON_JSON_OBJECT_FOREACH 1
#define ROUND_USE_JANSSON_JSON_ARRAY_FOREACH 1
#endif

#if defined(__APPLE__)
#define ROUND_SUPPORT_JAVA_JNI 1
#define ROUND_SUPPORT_JS_SM 1
#define ROUND_SUPPORT_TCL 1
#endif

#endif
