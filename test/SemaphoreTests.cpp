/******************************************************************
 *
 * uHTTP for C++
 *
 * Copyright (C) Satoshi Konno 2002
 *
 * This is licensed under BSD-style license, see file COPYING.
 *
 ******************************************************************/

#include <boost/test/unit_test.hpp>

#include <uhttp/util/Thread.h>
#include <uhttp/util/Semaphore.h>
#include <uhttp/util/TimeUtil.h>

using namespace std;
using namespace uHTTP;

BOOST_AUTO_TEST_CASE(SemaphoreBasicTest) {
  Semaphore *sem = new Semaphore(1);

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

BOOST_AUTO_TEST_CASE(SemaphoreWaitTest) {
  const time_t TEST_WAIT_TIME = 1;
  
  Semaphore *sem = new Semaphore(0);
  
  BOOST_CHECK_EQUAL(sem->wait(TEST_WAIT_TIME), false);
  
  BOOST_CHECK_EQUAL(sem->post(), true);
  BOOST_CHECK_EQUAL(sem->wait(TEST_WAIT_TIME), true);

  BOOST_CHECK_EQUAL(sem->wait(TEST_WAIT_TIME), false);
  
  BOOST_CHECK_EQUAL(sem->post(), true);
  BOOST_CHECK_EQUAL(sem->post(), true);
  BOOST_CHECK_EQUAL(sem->wait(TEST_WAIT_TIME), true);
  BOOST_CHECK_EQUAL(sem->wait(TEST_WAIT_TIME), true);
  
  BOOST_CHECK_EQUAL(sem->wait(TEST_WAIT_TIME), false);
  
  BOOST_CHECK_EQUAL(sem->post(), true);
  BOOST_CHECK_EQUAL(sem->post(), true);
  BOOST_CHECK_EQUAL(sem->post(), true);
  BOOST_CHECK_EQUAL(sem->wait(TEST_WAIT_TIME), true);
  BOOST_CHECK_EQUAL(sem->wait(TEST_WAIT_TIME), true);
  BOOST_CHECK_EQUAL(sem->wait(TEST_WAIT_TIME), true);
  
  delete sem;
}

static const int SEMAPHORE_THREAD_TEST_LOOP_NUM = 5;

class SemaphorePostThread : public Thread {
 public:
  SemaphorePostThread() {
  }

  void run() {
    Semaphore *sem = (Semaphore *)getObject();
    for (int n = 0; n < SEMAPHORE_THREAD_TEST_LOOP_NUM; n++) {
      BOOST_CHECK_EQUAL(sem->post(), true);
    }
  }
};

BOOST_AUTO_TEST_CASE(SemaphorePostThreadTest) {
  Semaphore *sem = new Semaphore(1);
  
  SemaphorePostThread semThread;
  semThread.setObject(sem);
  semThread.start();
  
  for (int n = 0; n < SEMAPHORE_THREAD_TEST_LOOP_NUM; n++) {
    BOOST_CHECK_EQUAL(sem->wait(), true);
  }
  
  delete sem;
}

BOOST_AUTO_TEST_CASE(SemaphoreCalcelTest) {
  Semaphore *sem = new Semaphore(0);
  
  BOOST_CHECK_EQUAL(sem->post(), true);
  BOOST_CHECK_EQUAL(sem->wait(), true);
  
  BOOST_CHECK_EQUAL(sem->cancel(), true);
  
  BOOST_CHECK_EQUAL(sem->post(), false);
  BOOST_CHECK_EQUAL(sem->wait(), false);
  
  delete sem;
}

class SemaphoreCancelThread : public Thread {
public:
  SemaphoreCancelThread() {
  }
  
  void run() {
    Wait(1000);
    BOOST_CHECK(((Semaphore *)getObject())->cancel());
  }
};

BOOST_AUTO_TEST_CASE(SemaphoreAsyncCalcelTest) {
  Semaphore *sem = new Semaphore(0);
  
  SemaphoreCancelThread semThread;
  semThread.setObject(sem);
  semThread.start();
  
  BOOST_CHECK_EQUAL(sem->post(), true);
  BOOST_CHECK_EQUAL(sem->wait(), true);
  
  BOOST_CHECK_EQUAL(sem->wait(), false);
  
  BOOST_CHECK_EQUAL(sem->post(), false);
  BOOST_CHECK_EQUAL(sem->wait(), false);
  
  delete sem;
}
