/******************************************************************
*
* uHTTP for C++
*
* Copyright (C) Satoshi Konno 2002-2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef _CHTTP_HTTPSERVER_H_
#define _CHTTP_HTTPSERVER_H_

#include <uhttp/net/ServerSocket.h>
#include <uhttp/util/ListenerList.h>
#include <uhttp/http/HTTPRequest.h>
#include <uhttp/http/HTTPRequestListener.h>
#include <uhttp/util/Thread.h>

#include <string>

namespace uHTTP {

class HTTPServer : public uHTTP::Thread
{
	uHTTP::ServerSocket *serverSock;
	uHTTP::ListenerList httpRequestListenerList;

public:
	
	HTTPServer();
	~HTTPServer();

	////////////////////////////////////////////////
	//	ServerSocket
	////////////////////////////////////////////////

	uHTTP::ServerSocket *getServerSock()
	{
		return serverSock;
	}

	bool bind(int port, const std::string &addr = "");
	bool close();
	bool accept(uHTTP::Socket *socket);
	bool isOpened();

	////////////////////////////////////////////////
	//	httpRequest
	////////////////////////////////////////////////
	 	
	void addRequestListener(HTTPRequestListener *listener)
	{
		httpRequestListenerList.add(listener);
	}		

	void removeRequestListener(HTTPRequestListener *listener)
	{
		httpRequestListenerList.remove(listener);
	}		

	void performRequestListener(HTTPRequest *httpReq)
	{
		int listenerSize = httpRequestListenerList.size();
		for (int n=0; n<listenerSize; n++) {
			HTTPRequestListener *listener = (HTTPRequestListener *)httpRequestListenerList.get(n);
			listener->httpRequestRecieved(httpReq);
		}
	}		

	////////////////////////////////////////////////
	//	run	
	////////////////////////////////////////////////

	void run();

};

const char *GetServerName(std::string &buf);

}

#endif
