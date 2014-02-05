/******************************************************************
*
* uHTTP for C++
*
* Copyright (C) Satoshi Konno 2002-2013
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/


#ifndef _CUTIL_TIMERUTIL_H_
#define _CUTIL_TIMERUTIL_H_

namespace uHTTP {
void Wait(long mtime);
void WaitRandom(long mtime);
long GetCurrentSystemTime();
float Random();

}

#endif
