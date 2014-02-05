/******************************************************************
*
* uHTTP for C++
*
* Copyright (C) Satoshi Konno 2002-2013
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/


#ifndef _CHTTP_HTTPSTATUS_H_
#define _CHTTP_HTTPSTATUS_H_

#include <string>

namespace uHTTP {
namespace HTTP {
const int CONTINUE = 100;
const int OK_REQUEST = 200;
// Thanks for Brent Hills (10/20/04)
const int PARTIAL_CONTENT = 206;
const int BAD_REQUEST = 400;
const int NOT_FOUND = 404;
const int PRECONDITION_FAILED = 412;
// Thanks for Brent Hills (10/20/04)
const int INVALID_RANGE =416;
const int INTERNAL_SERVER_ERROR = 500;
const int INTERNAL_CLIENT_ERROR = 600;
}

namespace HTTP {
const char *StatusCode2String(int code);
}

class HTTPStatus  {
  std::string version;
  int statusCode;
  std::string reasonPhrase;

 public:
  ////////////////////////////////////////////////
  //  Constructor
  ////////////////////////////////////////////////

  HTTPStatus();
  HTTPStatus(const std::string &lineStr);
  HTTPStatus(const std::string &ver, int code, const std::string &reason);
  
  ////////////////////////////////////////////////
  //  Member
  ////////////////////////////////////////////////

 public:
  void setVersion(const std::string &value) {
    this->version = value;
  }
    
  void setStatusCode(int value) {
    this->statusCode = value;
  }
    
  void setReasonPhrase(const std::string &value) {
    this->reasonPhrase = value;
  }
    
  const char *getVersion() {
    return version.c_str();
  }
    
  int getStatusCode() {
    return statusCode;
  }
    
  const char *getReasonPhrase() {
    return reasonPhrase.c_str();
  }

  ////////////////////////////////////////////////
  //  Status
  ////////////////////////////////////////////////
  
 public:
  static bool isSuccessful(int statCode);

  bool isSuccessful() {
    return isSuccessful(getStatusCode());
  }

  ////////////////////////////////////////////////
  //  set
  ////////////////////////////////////////////////

 public:
  void set(const std::string &lineStr);

};

}

#endif
