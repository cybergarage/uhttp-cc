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

#include <time.h>
#include <uhttp/util/Log.h>

using namespace uHTTP;

#define LOGGER_TEST_MESSAGE "Hello"

BOOST_AUTO_TEST_CASE(LoggerTest)
{
  Logger testLogger;
  testLogger.setLevel(LoggerLevel::TRACE);

  for (int n = 0; n < 10; n++) {
    BOOST_CHECK_EQUAL(testLogger.trace(LOGGER_TEST_MESSAGE), n);
    BOOST_CHECK_EQUAL(testLogger.message(LOGGER_TEST_MESSAGE), n);
    BOOST_CHECK_EQUAL(testLogger.warning(LOGGER_TEST_MESSAGE), n);
    BOOST_CHECK_EQUAL(testLogger.error(LOGGER_TEST_MESSAGE), n);
    BOOST_CHECK_EQUAL(testLogger.fatal(LOGGER_TEST_MESSAGE), n);
#if defined(DEBUG)
    BOOST_CHECK_EQUAL(testLogger.debug(LOGGER_TEST_MESSAGE), n);
#endif
    testLogger.addTarget(new LoggerNullTarget());
  }
}

BOOST_AUTO_TEST_CASE(LogTest)
{
  Logger* testLogger = Logger::GetSharedInstance();
  testLogger->setLevel(LoggerLevel::TRACE);
  testLogger->clearAllTargets();
  testLogger->addTarget(new LoggerNullTarget());

  BOOST_CHECK_EQUAL(LogTrace("%s", LOGGER_TEST_MESSAGE), 1);
  BOOST_CHECK_EQUAL(LogInfo("%s", LOGGER_TEST_MESSAGE), 1);
  BOOST_CHECK_EQUAL(LogWarn("%s", LOGGER_TEST_MESSAGE), 1);
  BOOST_CHECK_EQUAL(LogError("%s", LOGGER_TEST_MESSAGE), 1);
  BOOST_CHECK_EQUAL(LogFatal("%s", LOGGER_TEST_MESSAGE), 1);
#if defined(DEBUG)
  BOOST_CHECK_EQUAL(LogDebug("%s", LOGGER_TEST_MESSAGE), 1);
#endif
  testLogger->clearAllTargets();
}
