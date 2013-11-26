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

#include <uhttp/HTTP.h>

using namespace std;
using namespace uHTTP;

BOOST_AUTO_TEST_CASE(StringUtilTests)
{
    std::string buf;
    
	BOOST_CHECK_EQUAL(HexString2Long("1"), 1);
	BOOST_CHECK_EQUAL(HexString2Long("9"), 9);
	BOOST_CHECK_EQUAL(HexString2Long("A"), 10);
	BOOST_CHECK_EQUAL(HexString2Long("F"), 15);
	BOOST_CHECK_EQUAL(HexString2Long("FF"), 255);
	BOOST_CHECK_EQUAL(HexString2Long("a"), 10);
	BOOST_CHECK_EQUAL(HexString2Long("f"), 15);
	BOOST_CHECK_EQUAL(HexString2Long("ff"), 255);
    
	BOOST_CHECK_EQUAL(strcmp(Integer2HexString(1, buf), "1"), 0);
	BOOST_CHECK_EQUAL(strcmp(Integer2HexString(9, buf), "9"), 0);
	BOOST_CHECK_EQUAL(strcmp(Integer2HexString(10, buf), "a"), 0);
	BOOST_CHECK_EQUAL(strcmp(Integer2HexString(15, buf), "f"), 0);
	BOOST_CHECK_EQUAL(strcmp(Integer2HexString(255, buf), "ff"), 0);

	BOOST_CHECK_EQUAL(strcmp(Size2HexString(1, buf), "1"), 0);
	BOOST_CHECK_EQUAL(strcmp(Size2HexString(9, buf), "9"), 0);
	BOOST_CHECK_EQUAL(strcmp(Size2HexString(10, buf), "a"), 0);
	BOOST_CHECK_EQUAL(strcmp(Size2HexString(15, buf), "f"), 0);
	BOOST_CHECK_EQUAL(strcmp(Size2HexString(255, buf), "ff"), 0);
}

BOOST_AUTO_TEST_CASE(StringUtilParseTests)
{
	string valueStr;
	
	//UINT_MAX : 4294967295U
	// INT_MAX : 2147483647
	Integer2String(1, valueStr);
	BOOST_CHECK(strcmp("1", valueStr.c_str()) == 0);
	Integer2String(INT_MAX, valueStr);
	BOOST_CHECK(strcmp("2147483647", valueStr.c_str()) == 0);
	Integer2String(-1, valueStr);
	BOOST_CHECK(strcmp("-1", valueStr.c_str()) == 0);
	Integer2String(-INT_MAX, valueStr);
	BOOST_CHECK(strcmp("-2147483647", valueStr.c_str()) == 0);
	
	// UINT_LONG : 18446744073709551615UL
	// LONG_MAX :	9223372036854775807L
	Long2String(1, valueStr);
	BOOST_CHECK(strcmp("1", valueStr.c_str()) == 0);
	Long2String(INT_MAX, valueStr);
	BOOST_CHECK(strcmp("2147483647", valueStr.c_str()) == 0);
	Long2String(-1, valueStr);
	BOOST_CHECK(strcmp("-1", valueStr.c_str()) == 0);
	Long2String(-INT_MAX, valueStr);
	BOOST_CHECK(strcmp("-2147483647", valueStr.c_str()) == 0);
}

BOOST_AUTO_TEST_CASE(StringUtilTokenizerTests)
{
	StringTokenizer *strToken;
	char *token[] = { "abcde", "test", "skonno" };
	char tokenStr[128];
	int tokenCnt;
    
	sprintf(tokenStr, "%s", token[0]);
	strToken = new StringTokenizer(tokenStr, ",");
	tokenCnt = 0;
	while( strToken->hasMoreTokens() == true) {
		const char *tstr = strToken->nextToken();
		BOOST_CHECK(strcmp(tstr, token[tokenCnt]) == 0);
		tokenCnt++;
	}
	BOOST_CHECK(tokenCnt == 1);
	delete strToken;
    
	sprintf(tokenStr, "%s,%s,%s", token[0], token[1], token[2]);
	strToken = new StringTokenizer(tokenStr, ",");
	tokenCnt = 0;
	while( strToken->hasMoreTokens() == true) {
		const char *tstr = strToken->nextToken();
		BOOST_CHECK(strcmp(tstr, token[tokenCnt]) == 0);
		tokenCnt++;
	}
	BOOST_CHECK(tokenCnt == 3);
	delete strToken;
    
	sprintf(tokenStr, "%s,%s,%s,", token[0], token[1], token[2]);
	strToken = new StringTokenizer(tokenStr, ",");
	tokenCnt = 0;
	while( strToken->hasMoreTokens() == true) {
		const char *tstr = strToken->nextToken();
		BOOST_CHECK(strcmp(tstr, token[tokenCnt]) == 0);
		tokenCnt++;
	}
	BOOST_CHECK(tokenCnt == 3);
	delete strToken;
    
	sprintf(tokenStr, ",%s,%s,%s,", token[0], token[1], token[2]);
	strToken = new StringTokenizer(tokenStr, ",");
	tokenCnt = 0;
	while( strToken->hasMoreTokens() == true) {
		const char *tstr = strToken->nextToken();
		BOOST_CHECK(strcmp(tstr, token[tokenCnt]) == 0);
		tokenCnt++;
	}
	BOOST_CHECK(tokenCnt == 3);
	delete strToken;
    
	strToken = new StringTokenizer("*", ",");
	tokenCnt = 0;
	while( strToken->hasMoreTokens() == true) {
		const char *tstr = strToken->nextToken();
		BOOST_CHECK(strcmp(tstr, "*") == 0);
		tokenCnt++;
	}
	BOOST_CHECK(tokenCnt == 1);
	delete strToken;
    
	sprintf(tokenStr, "%s", token[0]);
	strToken = new StringTokenizer(tokenStr, ", \n\t");
	tokenCnt = 0;
	while( strToken->hasMoreTokens() == true) {
		const char *tstr = strToken->nextToken();
		BOOST_CHECK(strcmp(tstr, token[tokenCnt]) == 0);
		tokenCnt++;
	}
	BOOST_CHECK(tokenCnt == 1);
	delete strToken;
    
	sprintf(tokenStr, "%s,,%s,,%s", token[0], token[1], token[2]);
	strToken = new StringTokenizer(tokenStr, ", \n\t");
	tokenCnt = 0;
	while( strToken->hasMoreTokens() == true) {
		const char *tstr = strToken->nextToken();
		BOOST_CHECK(strcmp(tstr, token[tokenCnt]) == 0);
		tokenCnt++;
	}
	BOOST_CHECK(tokenCnt == 3);
	delete strToken;
    
	sprintf(tokenStr, "  %s,  %s,  %s,  ", token[0], token[1], token[2]);
	strToken = new StringTokenizer(tokenStr, ", \n\t");
	tokenCnt = 0;
	while( strToken->hasMoreTokens() == true) {
		const char *tstr = strToken->nextToken();
		BOOST_CHECK(strcmp(tstr, token[tokenCnt]) == 0);
		tokenCnt++;
	}
	BOOST_CHECK(tokenCnt == 3);
	delete strToken;
    
	strToken = new StringTokenizer("*", ", \n\t");
	tokenCnt = 0;
	while( strToken->hasMoreTokens() == true) {
		const char *tstr = strToken->nextToken();
		BOOST_CHECK(strcmp(tstr, "*") == 0);
		tokenCnt++;
	}
	BOOST_CHECK(tokenCnt == 1);
	delete strToken;
}

