/******************************************************************
*
* uHTTP for C++
*
* Copyright (C) Satoshi Konno 2002-2013
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/


#ifndef _CUTIL_EXCEPTION_H_
#define _CUTIL_EXCEPTION_H_

#include <string>

namespace uHTTP {
class Exception {
  std::string msg;

 public:
  Exception(const std::string &msg) {
    this->msg = msg;
  }

  const char *getMessage() {
    return msg.c_str();
  }
};

}

#endif

