/******************************************************************
*
* uHTTP for C++
*
* Copyright (C) Satoshi Konno 2002-2013
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/


#ifndef _CUTIL_STRINGTOKENIZER_H_
#define _CUTIL_STRINGTOKENIZER_H_

#include <string>

namespace uHTTP {
class StringTokenizer {
  std::string strBuf;
  std::string strDelim;
  std::string strCurrToken;
  std::string strNextToken;
  std::string::size_type lastDelimPos;
  bool hasNextTokens;

 public:
  StringTokenizer(const std::string &str, const std::string &delim);
  ~StringTokenizer();

  bool hasMoreTokens();

  const char *nextToken();
  const char *nextToken(const std::string &delim);
};

}

#endif
