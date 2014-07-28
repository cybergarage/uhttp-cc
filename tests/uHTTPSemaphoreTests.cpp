/******************************************************************
 *
 * Fractal for C++
 *
 * Copyright (C) Satoshi Konno 2012
 *
 * This is licensed under BSD-style license, see file COPYING.
 *
 ******************************************************************/

#include <boost/test/unit_test.hpp>

#include <uhttp/util/Thread.h>
#include <uhttp/util/Semaphore.h>

using namespace std;
using namespace uHTTP;

BOOST_AUTO_TEST_CASE(SemaphoreBasicTest) {
  Semaphore *sem = new Semaphore();

  BOOST_CHECK_EQUAL(sem->post(), true);
  BOOST_CHECK_EQUAL(sem->wait(), true);

  BOOST_CHECK_EQUAL(sem->post(), true);
  BOOST_CHECK_EQUAL(sem->post(), true);
  BOOST_CHECK_EQUAL(sem->wait(), true);
  BOOST_CHECK_EQUAL(sem->wait(), true);

  BOOST_CHECK_EQUAL(sem->post(), true);
  BOOST_CHECK_EQUAL(sem->wait(), true);
  BOOST_CHECK_EQUAL(sem->post(), true);
  BOOST_CHECK_EQUAL(sem->wait(), true);

  delete sem;
}

static const int SEMAPHORE_THREAD_TEST_LOOP_NUM = 5;

class SemaphoreThread : public Thread {
 public:
  SemaphoreThread() {
  }

  void run() {
    Semaphore *sem = (Semaphore *)getObject();
    for (int n = 0; n < SEMAPHORE_THREAD_TEST_LOOP_NUM; n++) {
      BOOST_CHECK_EQUAL(sem->post(), true);
    }
  }
};

BOOST_AUTO_TEST_CASE(SemaphoreThreadTest) {
  Semaphore *sem = new Semaphore();
  
  SemaphoreThread semThread;
  semThread.setObject(sem);
  semThread.start();
  
  for (int n = 0; n < SEMAPHORE_THREAD_TEST_LOOP_NUM; n++) {
    BOOST_CHECK_EQUAL(sem->wait(), true);
  }
  
  delete sem;
}
