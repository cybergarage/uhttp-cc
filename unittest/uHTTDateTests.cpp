/******************************************************************
*
* uHTTP for C++
*
* Copyright (C) Satoshi Konno 2002-2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#include <string>
#include <vector>

#include <boost/test/unit_test.hpp>

#include <uhttp/HTTP.h>

using namespace uHTTP;

BOOST_AUTO_TEST_CASE(HTTPDateTests)
{
	HTTPDate httpDate(1118220696);
	const char *dateStr = httpDate.getDateString();
	printf("%s\n", dateStr);
	BOOST_CHECK_EQUAL(strcmp(dateStr, "Wed, 08 Jun 2005 08:51:36 GMT"), 0);
}
