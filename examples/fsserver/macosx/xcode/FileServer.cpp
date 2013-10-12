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

////////////////////////////////////////////////
//	Constructor
////////////////////////////////////////////////
	
FileServer::FileServer()
{
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

	httpReq->returnBadRequest();
}

////////////////////////////////////////////////
//	start
////////////////////////////////////////////////

bool FileServer::start()
{
	stop();
/*
	////////////////////////////////////////
	// HTTP Server
	////////////////////////////////////////
		
	int retryCnt = 0;
	int bindPort = getHTTPPort();
	HTTPServerList *httpServerList = getHTTPServerList();
	while (httpServerList->open(bindPort) == false) {
		retryCnt++;
		if (UPnP::SERVER_RETRY_COUNT < retryCnt)
			return false;
		setHTTPPort(bindPort + 1);
		bindPort = getHTTPPort();
	}
	httpServerList->addRequestListener(this);
	httpServerList->start();

	////////////////////////////////////////
	// SSDP Seach Socket
	////////////////////////////////////////
	
	SSDPSearchSocketList *ssdpSearchSockList = getSSDPSearchSocketList();
	if (ssdpSearchSockList->open() == false)
		return false;
	ssdpSearchSockList->addSearchListener(this);
	ssdpSearchSockList->start();

	////////////////////////////////////////
	// Announce
	////////////////////////////////////////

	announce();

	////////////////////////////////////////
	// Advertiser
	////////////////////////////////////////

	Advertiser *adv = new Advertiser(this);
	setAdvertiser(adv);
	adv->start();
*/
	return true;
}

////////////////////////////////////////////////
//	stop
////////////////////////////////////////////////

bool FileServer::stop()
{
/*
	if (doByeBye == true)
		byebye();
		
	HTTPServerList *httpServerList = getHTTPServerList();
	httpServerList->stop();
	httpServerList->close();
	httpServerList->clear();

	SSDPSearchSocketList *ssdpSearchSockList = getSSDPSearchSocketList();
	ssdpSearchSockList->stop();
	ssdpSearchSockList->close();
	ssdpSearchSockList->clear();
		
	Advertiser *adv = getAdvertiser();
	if (adv != NULL) {
		adv->stop();
		setAdvertiser(NULL);
	}
*/
	return true;
}
