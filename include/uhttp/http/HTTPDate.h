/******************************************************************
*
* uHTTP for C++
*
* Copyright (C) Satoshi Konno 2002-2013
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef _CHTTP_HTTPDATE_H_
#define _CHTTP_HTTPDATE_H_

#include <uhttp/util/Date.h>

namespace uHTTP {
class HTTPDate : public uHTTP::Date {
  char dateStr[64];
  char timeStr[64];

 public:
  HTTPDate();
  HTTPDate(SysTime date);

  ////////////////////////////////////////////////
  //  get*String
  ////////////////////////////////////////////////

  const char *getDateString();
};

const char *toMonthString(int value);
const char *toWeekString(int value);

}

#endif
