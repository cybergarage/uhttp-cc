/******************************************************************
*
* uHTTP for C++
*
* Copyright (C) Satoshi Konno 2002-2013
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef _CIO_LINENUMBERREADER_H_
#define _CIO_LINENUMBERREADER_H_

#include <string>

#include <uhttp/io/BufferedReader.h>

namespace uHTTP {
class LineNumberReader : public BufferedReader {
  int lineNum;

 public:
  LineNumberReader(Reader *reader) : BufferedReader(reader) {
    lineNum = -1;
  }

  int getLineNumber() {
    return lineNum;
  }

  const char *readLine() {
    lineNum++;
    return BufferedReader::readLine();
  }
};

}

#endif
