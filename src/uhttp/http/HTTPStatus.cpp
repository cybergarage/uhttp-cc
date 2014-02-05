/******************************************************************
*
* uHTTP for C++
*
* Copyright (C) Satoshi Konno 2002-2013
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/


#include <stdlib.h>

#include <uhttp/http/HTTP.h>
#include <uhttp/http/HTTPStatus.h>
#include <uhttp/util/StringTokenizer.h>
#include <uhttp/util/StringUtil.h>

using namespace uHTTP;
using namespace uHTTP;

////////////////////////////////////////////////
//  Constructor
////////////////////////////////////////////////

HTTPStatus::HTTPStatus() {
  setVersion("");
  setStatusCode(0);
  setReasonPhrase("");
}
  
HTTPStatus::HTTPStatus(const std::string &ver, int code, const std::string &reason) {
  setVersion(ver);
  setStatusCode(code);
  setReasonPhrase(reason);
}

HTTPStatus::HTTPStatus(const std::string &lineStr) {
  set(lineStr);
}

////////////////////////////////////////////////
//  set
////////////////////////////////////////////////

void HTTPStatus::set(const std::string &lineStr) {
    if (lineStr.length() <= 0) {
      setVersion(HTTP::VER);
      setStatusCode(HTTP::INTERNAL_SERVER_ERROR);
      setReasonPhrase(HTTP::StatusCode2String(HTTP::INTERNAL_SERVER_ERROR));
      return;
    }

    StringTokenizer st(lineStr, HTTP::STATUS_LINE_DELIM);
    std::string trimBuf;
    
    if (st.hasMoreTokens() == false)
      return;
    std::string ver = st.nextToken();
    setVersion(StringTrim(ver.c_str(), trimBuf));

    if (st.hasMoreTokens() == false)
      return;
    std::string codeStr = st.nextToken();
    int code = atoi(codeStr.c_str());
    setStatusCode(code);

    std::string reason = "";
    while (st.hasMoreTokens() == true) {
      if (0 < reason.length())
        reason.append(" ");
      reason.append(st.nextToken());
    }
    setReasonPhrase(StringTrim(reason.c_str(), trimBuf));
}

////////////////////////////////////////////////
//  Status
////////////////////////////////////////////////
  
bool HTTPStatus::isSuccessful(int statCode) {
  if (200 <= statCode && statCode < 300)
    return true;
  return false;
}

////////////////////////////////////////////////
//  StatusCode2String
////////////////////////////////////////////////
  
const char *uHTTP::HTTP::StatusCode2String(int code) {
  switch (code) {
  case HTTP::CONTINUE: return "Continue";
  case HTTP::OK_REQUEST: return "OK";
  case HTTP::PARTIAL_CONTENT: return "Partial Content";
  case HTTP::BAD_REQUEST: return "Bad Request";
  case HTTP::NOT_FOUND: return "Not Found";
  case HTTP::PRECONDITION_FAILED: return "Precondition Failed";
  case HTTP::INVALID_RANGE: return "Invalid Range";
  case HTTP::INTERNAL_SERVER_ERROR: return "Internal Server Error";
  }
  
  if ((code % 100) == HTTP::INTERNAL_CLIENT_ERROR)
    return "Internal Client Error";
  
   return "Unknown Error";
}

