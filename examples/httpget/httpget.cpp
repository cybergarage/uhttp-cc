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
#include <iostream>

#include <stdlib.h>
#include <unistd.h>

#include <uhttp/HTTP.h>

using namespace std;
using namespace uHTTP;

void usage(const string &programName)
{
    cout << "Usage: " << programName << " <url>" << endl;
}

int main(int argc, char *argv[]) 
{
	if (argc <= 1) {
		usage(argv[0]);
        return EXIT_FAILURE;
	}
    
	URL uri(argv[1]);
    
	HTTPRequest httpReq;
	httpReq.setMethod(HTTP::GET);
	httpReq.setURL(&uri);
 
	HTTPResponse *httpRes = httpReq.post();

	cout << httpRes->getStatusCode() << endl;

	if (!httpRes->isSuccessful()) {
		return EXIT_FAILURE;
	}

	string httpContent = httpRes->getContent();

	cout << httpContent << endl;
	
	return EXIT_SUCCESS;
}
