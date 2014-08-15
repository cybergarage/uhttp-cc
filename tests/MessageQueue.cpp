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

#include <uhttp/util/MessageQueue.h>
#include <uhttp/util/Thread.h>
#include <uhttp/util/TimeUtil.h>

using namespace std;
using namespace uHTTP;

#define FRACTAL_MESSAGE_BASIC_TEST_COUNT 10

class TestMessage : public Message {

public:
  
  TestMessage(int value = 0) {
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
  
  Message *popMsg;
  BOOST_CHECK_EQUAL(msgQueue.waitMessage(&popMsg, 1), false);
  
  TestMessage *msg = new TestMessage();
  BOOST_CHECK(msgQueue.pushMessage(msg));
  
  BOOST_CHECK_EQUAL(msgQueue.waitMessage(&popMsg), true);
}

BOOST_AUTO_TEST_CASE(MessageQueueClearTest) {
  MessageQueue msgQueue;
  
  TestMessage *msg = new TestMessage();
  
  BOOST_CHECK_EQUAL(msgQueue.size(), 0);
  
  BOOST_CHECK(msgQueue.pushMessage(msg));
  BOOST_CHECK_EQUAL(msgQueue.size(), 1);
  
  BOOST_CHECK(msgQueue.clear());
  BOOST_CHECK_EQUAL(msgQueue.size(), 0);
}

BOOST_AUTO_TEST_CASE(MessageQueueLoopTest) {
  MessageQueue msgQueue;
  
  for (int n = 0; n < FRACTAL_MESSAGE_BASIC_TEST_COUNT; n++) {
    TestMessage *msg = new TestMessage(n);
    BOOST_CHECK(msgQueue.pushMessage(msg));
  }

  for (int n = 0; n < FRACTAL_MESSAGE_BASIC_TEST_COUNT; n++) {
    Message *msg;
    BOOST_CHECK(msgQueue.waitMessage(&msg));
    TestMessage *testMsg = dynamic_cast<TestMessage *>(msg);
    BOOST_CHECK(testMsg);
    int msgValue = testMsg->getValue();
    BOOST_CHECK_EQUAL(n, msgValue);
    delete msg;
  }
}

class MessageCalcelThread : public Thread
{
public:
  
  MessageQueue *msgQueue;
  
  MessageCalcelThread(MessageQueue *msgQueue)
  {
    this->msgQueue = msgQueue;
  }
  
  void run()
  {
    Wait(1000);
    msgQueue->clear();
  }
};

BOOST_AUTO_TEST_CASE(MessageCancelTest) {
  MessageQueue msgQueue;

  MessageCalcelThread msgCancelThread(&msgQueue);
  msgCancelThread.start();
  
  Message *msg = NULL;
  BOOST_CHECK_EQUAL(msgQueue.waitMessage(&msg), false);
  BOOST_CHECK(!msg);
}
