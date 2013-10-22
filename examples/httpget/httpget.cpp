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

void usage(char *argv[])
{
    std::string programName = argv[0];
    size_t lastPathIndex = programName.find_last_of("/");
    if (lastPathIndex != std::string::npos)
        programName = programName.substr((lastPathIndex + 1));

    std::cout << "Usage: " << programName << " [options...] <url>" << std::endl;
    std::cout << " -0, Use HTTP 1.0" << std::endl;
    std::cout << " -1, Use HTTP 1.1" << std::endl;
    std::cout << " -h, This help text" << std::endl;
    std::cout << " -v, Enable verbose mode" << std::endl;
}

int main(int argc, char *argv[]) 
{
    const char *httpVersion = uHTTP::HTTP::VER_11;
    bool verboseMode = false;
    
    int ch;
    while ((ch = getopt(argc, argv, "01vh")) != -1) {
        switch (ch) {
        case '0':
            {
                httpVersion = uHTTP::HTTP::VER_10;
            }
            break;
        case '1':
            {
                httpVersion = uHTTP::HTTP::VER_11;
            }
            break;
        case 'v':
            {
                verboseMode = true;
            }
            break;
        case 'h':
        default:
            {
                usage(argv);
                exit(EXIT_SUCCESS);
            }
        }
    }
    
    argc -= optind;
    argv += optind;

	if (argc < 1) {
		usage((argv-optind));
        return EXIT_FAILURE;
	}
    
	uHTTP::URL uri(argv[0]);
    
    if (!uri.isValid()) {
        if (!uri.hasPath()) {
            uri.setPath("/");
        }
        if (!uri.isValid()) {
            std::cout << "ERR : Invalid URL <" << argv[0] << ">" << std::endl;
            return EXIT_FAILURE;
        }
    }
    
	uHTTP::HTTPRequest httpReq;
	httpReq.setVersion(httpVersion);
	httpReq.setMethod(uHTTP::HTTP::GET);
	httpReq.setURL(&uri);

    if (verboseMode) {
        std::string firstHeader;
        std::cout << "> " << httpReq.getRequestLine(firstHeader) <<  std::endl;
        for (uHTTP::HTTPHeaderList::iterator header = httpReq.getHeaders().begin(); header != httpReq.getHeaders().end(); header++) {
            std::cout << "> " << (*header)->getName() << " : " << (*header)->getValue() << std::endl;
        }
    }
    
	uHTTP::HTTPResponse *httpRes = httpReq.post();

    if (verboseMode) {
        std::cout << "< " << httpRes->getFirstLine() << std::endl;
        for (uHTTP::HTTPHeaderList::iterator header = httpRes->getHeaders().begin(); header != httpRes->getHeaders().end(); header++) {
            std::cout << "< " << (*header)->getName() << " : " << (*header)->getValue() << std::endl;
        }
    }

	if (!httpRes->isSuccessful()) {
		return EXIT_FAILURE;
	}

	std::string httpContent = httpRes->getContent();
	std::cout << httpContent << std::endl;
	
	return EXIT_SUCCESS;
}

