/******************************************************************
*
* uHTTP for C++
*
* Copyright (C) Satoshi Konno 2002
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/


#ifndef _CHTTP_HTTPSTATUS_H_
#define _CHTTP_HTTPSTATUS_H_

#include <string>

namespace uHTTP {
  
namespace HTTP {
  // 1xx Informational
  const int CONTINUE = 100;
  
  // 2xx Success
  const int OK_REQUEST = 200;
  const int ACCEPTED = 202;
  const int PARTIAL_CONTENT = 206;

  // 4xx Client Error
  const int BAD_REQUEST = 400;
  const int NOT_FOUND = 404;
  const int PRECONDITION_FAILED = 412;
  const int INVALID_RANGE =416;
  
  // 5xx Server Error
  const int INTERNAL_SERVER_ERROR = 500;
  
  // xxx uHTTP Extentions
  const int PROCESSING = 102;
  const int INTERNAL_CLIENT_ERROR = 600;
}

namespace HTTP {
  bool IsStatusCodeSuccess(int code);
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

  bool isSuccessful() {
    return HTTP::IsStatusCodeSuccess(getStatusCode());
  }

  ////////////////////////////////////////////////
  //  set
  ////////////////////////////////////////////////

 public:
  void set(const std::string &lineStr);

};

}

#endif
