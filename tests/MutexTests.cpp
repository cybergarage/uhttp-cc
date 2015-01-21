/******************************************************************
*
* uHTTP for C++
*
* Copyright (C) Satoshi Konno 2002
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#include <string>
#include <vector>

#include <boost/test/unit_test.hpp>

#include <uhttp/HTTP.h>

using namespace uHTTP;

BOOST_AUTO_TEST_CASE(MutexTests)
{
  Mutex *mutex = new Mutex();
  BOOST_CHECK_EQUAL(mutex->lock(), true);
  BOOST_CHECK_EQUAL(mutex->unlock(), true);
  delete mutex;
}
