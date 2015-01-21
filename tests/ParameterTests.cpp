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

BOOST_AUTO_TEST_CASE(ParameterListTest)
{
  size_t TEST_PARAM_LOOP_COUNT = 10;
  
  ParameterList paramList;
  
  BOOST_CHECK_EQUAL(paramList.size(), 0);
  
  for (size_t n=0; n<TEST_PARAM_LOOP_COUNT; n++) {
    BOOST_CHECK_EQUAL(paramList.size(), n);
    
    char paramName[32], paramValue[32];
    snprintf(paramName, sizeof(paramName), "param%d", (int)n);
    snprintf(paramValue, sizeof(paramValue), "value%d", (int)n);

    Parameter *param = new Parameter(paramName, paramValue);
    paramList.add(param);
    BOOST_CHECK_EQUAL(paramList.size(), (n+1));
    
    std::string storedParamValue;
    BOOST_CHECK(paramList.getParameterValue(paramName, &storedParamValue));
    BOOST_CHECK_EQUAL(storedParamValue.compare(paramValue), 0);
  }
}
