/******************************************************************
*
* uHTTP for C++
*
* Copyright (C) Satoshi Konno 2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#include <uhttp/util/Logger.h>

uHTTP::LoggerTargetList::LoggerTargetList() {
}

uHTTP::LoggerTargetList::~LoggerTargetList() {
}

void uHTTP::LoggerTargetList::clear() {
  for (LoggerTargetList::iterator loggerTarget = begin(); loggerTarget != end(); loggerTarget++) {
    delete (*loggerTarget);
  }
  std::vector<LoggerTarget *>::clear();
}
