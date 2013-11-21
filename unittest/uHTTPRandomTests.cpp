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
#include <boost/algorithm/string.hpp>

#include <uhttp/util/Random.h>

using namespace std;
using namespace uHTTP;

BOOST_AUTO_TEST_CASE(RandomTest01)
{
  Random rand;

  int randVal = rand.rand();
  BOOST_CHECK(0 <= randVal);
  BOOST_CHECK(randVal <= RAND_MAX);
}

BOOST_AUTO_TEST_CASE(RandomTest02)
{
  int minRange = 1;
  int maxRange = 10;

  Random randRange(minRange, maxRange);

  int randVal = randRange.rand();
  BOOST_CHECK(minRange <= randVal);
  BOOST_CHECK(randVal <= RAND_MAX);
}

BOOST_AUTO_TEST_CASE(RandomTest03)
{
  Random rand;

  int minRange = rand.rand();
  int maxRange = rand.rand();

  Random randRange(minRange, maxRange);

  int randVal = randRange.rand();
  BOOST_CHECK(minRange <= randVal);
  BOOST_CHECK(randVal <= RAND_MAX);
}
