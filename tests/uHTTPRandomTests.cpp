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
  BOOST_CHECK(randVal <= maxRange);
}

BOOST_AUTO_TEST_CASE(RandomTest03)
{
  int minRange = 10;
  int maxRange = 1;

  Random randRange(minRange, maxRange);
  std::swap(minRange, maxRange);

  int randVal = randRange.rand();
  BOOST_CHECK(minRange <= randVal);
  BOOST_CHECK(randVal <= maxRange);
}

BOOST_AUTO_TEST_CASE(RandomTest04)
{
  Random rand;

  int randValue1 = rand.rand();
  int randValue2 = rand.rand();

  int minRange = std::min(randValue1, randValue2);
  int maxRange = std::max(randValue1, randValue2);

  Random randRange(minRange, maxRange);

  int randVal = randRange.rand();
  BOOST_CHECK(minRange <= randVal);
  BOOST_CHECK(randVal <= maxRange);
}
