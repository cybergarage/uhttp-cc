/******************************************************************
*
* uHTTP for C++
*
* Copyright (C) Satoshi Konno 2002-2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#include "FileServer.h"

#include <uhttp/net/URI.h>

////////////////////////////////////////////////
//	Constructor
////////////////////////////////////////////////
	
FileServer::FileServer()
{
    setPort(uHTTP::HTTP::DEFAULT_PORT);
}

FileServer::~FileServer()
{
}

////////////////////////////////////////////////
//	HTTP Server	
////////////////////////////////////////////////

void FileServer::httpRequestRecieved(uHTTP::HTTPRequest *httpReq)
{
	if (!httpReq->isGetRequest()) {
        httpReq->returnBadRequest();
		return;
	}

    uHTTP::URI reqUri;
    httpReq->getURI(reqUri);
    
    
	httpReq->returnBadRequest();
}

////////////////////////////////////////////////
//	start
////////////////////////////////////////////////

bool FileServer::start()
{
	stop();

    if (!open(getPort()))
        return false;
    
    return HTTPServer::start();
}

////////////////////////////////////////////////
//	stop
////////////////////////////////////////////////

bool FileServer::stop()
{
    return HTTPServer::stop();
}
