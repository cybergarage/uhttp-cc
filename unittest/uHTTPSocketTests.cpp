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
#include <boost/algorithm/string.hpp>

#include <uhttp/HTTP.h>

using namespace std;
using namespace uHTTP;

BOOST_AUTO_TEST_CASE(SocketAddrInfoTests)
{
    /*
	struct addrinfo *addrInfo;
	bool ret = toSocketAddrInfo(SOCK_STREAM, "192.168.100.10", 80, &addrInfo, true);
	if (ret == true)
		freeaddrinfo(addrInfo);
	BOOST_CHECK(ret);
    */
}

BOOST_AUTO_TEST_CASE(SocketHTTPTests)
{
    const char *CG_HOST_IPADDR = "203.138.119.39";
    const char *TEST_HTTP_METHOD = "GET /index.html HTTP/1.0";

	Socket *sock;
	int sentLen;
	int readLen;
	const char *line;
    
	sock = new Socket();
	BOOST_CHECK(sock != NULL);
	BOOST_CHECK(sock->connect(CG_HOST_IPADDR, 80));
    
	sentLen = sock->send(TEST_HTTP_METHOD, strlen(TEST_HTTP_METHOD));
	BOOST_CHECK(sentLen == strlen(TEST_HTTP_METHOD));
	sentLen = sock->send(HTTP::CRLF, strlen(HTTP::CRLF));
	BOOST_CHECK(sentLen == strlen(HTTP::CRLF));
	sentLen = sock->send(HTTP::CRLF, strlen(HTTP::CRLF));
	BOOST_CHECK(sentLen == strlen(HTTP::CRLF));
    
	SocketInputStream sockIn(sock);
	InputStreamReader inReader(&sockIn);
	BufferedReader bufReader(&inReader);
    
	do {
		line = bufReader.readLine();
		readLen = strlen(line);
		//printf("%d:%s\n", readLen, line);
	} while (2 < readLen);
    
	BOOST_CHECK(sock->close() == true);
	delete sock;
}
