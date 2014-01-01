/******************************************************************
*
* uHTTP for C++
*
* Copyright (C) Satoshi Konno 2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef _UHTTP_LOG_H_
#define _UHTTP_LOG_H_

#include <uhttp/util/Logger.h>
#include <uhttp/util/LoggerFileTarget.h>
#include <uhttp/util/LoggerStdTarget.h>

namespace uHTTP {

int Log(int logType, const char *fileName, int lineNo, const char *functionName, const char *format, ...);

#define LogTrace(format, ...)     uHTTP::Log(uHTTP::LoggerTarget::TRACE,   __FILE__,  __LINE__, __PRETTY_FUNCTION__, format, ##__VA_ARGS__)
#define LogInfo(format, ...)      uHTTP::Log(uHTTP::LoggerTarget::INFO,    __FILE__,  __LINE__, __PRETTY_FUNCTION__, format, ##__VA_ARGS__)
#define LogWarn(format, ...)      uHTTP::Log(uHTTP::LoggerTarget::WARN,    __FILE__,  __LINE__, __PRETTY_FUNCTION__, format, ##__VA_ARGS__)
#define LogError(format, ...)     uHTTP::Log(uHTTP::LoggerTarget::ERR,     __FILE__,  __LINE__, __PRETTY_FUNCTION__, format, ##__VA_ARGS__)
#define LogFatal(format, ...)     uHTTP::Log(uHTTP::LoggerTarget::FATAL,   __FILE__,  __LINE__, __PRETTY_FUNCTION__, format, ##__VA_ARGS__)

#if defined(DEBUG)
#define LogDebug(format, ...)     uHTTP::Log(uHTTP::LoggerTarget::DBG,     __FILE__,  __LINE__, __PRETTY_FUNCTION__, format, ##__VA_ARGS__)
#else
#define LogDebug(format, ...)     
#endif

}

#endif
