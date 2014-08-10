/******************************************************************
*
*uHTTP for C++
*
* Copyright (C) Satoshi Konno 2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#include <boost/test/unit_test.hpp>

#include <stdio.h>
#include <time.h>

#include <uhttp/util/MessageQueue.h>

using namespace std;
using namespace uHTTP;

#define FRACTAL_MESSAGE_BASIC_TEST_COUNT 10

class TestMessage : public Message {

public:
  
  TestMessage(int value) {
    this->value = value;
  }
  
  int getValue() {
    return this->value;
  }
  
private:
  int value;
};

BOOST_AUTO_TEST_CASE(MessageQueueTest) {
  MessageQueue msgQueue;

  for (int n = 0; n < FRACTAL_MESSAGE_BASIC_TEST_COUNT; n++) {
    TestMessage *msg = new TestMessage(n);
    BOOST_CHECK(msgQueue.pushMessage(msg));
  }

  for (int n = 0; n < FRACTAL_MESSAGE_BASIC_TEST_COUNT; n++) {
    Message *msg;
    BOOST_CHECK(msgQueue.popMessage(&msg));
    TestMessage *testMsg = dynamic_cast<TestMessage *>(msg);
    BOOST_CHECK(testMsg);
    int msgValue = testMsg->getValue();
    BOOST_CHECK_EQUAL(n, msgValue);
    delete msg;
  }
}
