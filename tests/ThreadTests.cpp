/******************************************************************
*
* uHTTP for C++
*
* Copyright (C) Satoshi Konno 2002-2013
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#include <boost/test/unit_test.hpp>
#include <boost/thread.hpp>

#include <uhttp/util/Thread.h>

using namespace uHTTP;

const int THREAD_TEST_LOOP_NUM = 10;

class TestThread : public Thread
{
public:
  
  int value;
    
  TestThread()
  {
    value = 0;
  }
    
  void run()
  {
    for (int n=0; n<THREAD_TEST_LOOP_NUM; n++)
      value++;
  }
};

BOOST_AUTO_TEST_CASE(ThreadTests)
{
  TestThread *thread = new TestThread();
  BOOST_CHECK_EQUAL (thread->start(), true);
  while (thread->value != THREAD_TEST_LOOP_NUM) {
    boost::this_thread::sleep(boost::posix_time::milliseconds(100));
  }
  BOOST_CHECK_EQUAL(thread->value, THREAD_TEST_LOOP_NUM);
  BOOST_CHECK_EQUAL(thread->stop(), true);
  delete thread;
}
