/******************************************************************
 *
 * uHTTP for C++
 *
 * Copyright (C) Satoshi Konno 2002
 *
 * This is licensed under BSD-style license, see file COPYING.
 *
 ******************************************************************/

#include <uhttp/http/HTTPServerList.h>
#include <uhttp/util/StringUtil.h>
#include <uhttp/util/Debug.h>

#include <sstream>

using namespace std;
using namespace uHTTP;

////////////////////////////////////////////////
//  Constructor
////////////////////////////////////////////////

HTTPServerList::HTTPServerList() {
}

HTTPServerList::~HTTPServerList() {
  stop();
  close();
}

////////////////////////////////////////////////
//  addRequestListener
////////////////////////////////////////////////

void HTTPServerList::addRequestListener(HTTPRequestListener *listener) {
  size_t nServers = size();
  for (size_t n = 0; n < nServers; n++) {
    HTTPServer *server = getHTTPServer(n);
    server->addRequestListener(listener);
  }
}

////////////////////////////////////////////////
//  open/close
////////////////////////////////////////////////

void HTTPServerList::close() {
  size_t nServers = size();
  for (size_t n = 0; n < nServers; n++) {
    HTTPServer *server = getHTTPServer(n);
    server->close();
  }
  clear();
}

bool HTTPServerList::open(int port) {
  bool ret = true;
  size_t nHostAddrs = GetNHostAddresses();
  for (int n = 0; n < nHostAddrs; n++) {
    string buf;
    const char *bindAddr = GetHostAddress(n, buf);
    HTTPServer *httpServer = new HTTPServer();
    // Thanks for Ilkka Poutanen and Stefano Lenzi (07/16/04)
    if (httpServer->open(port, bindAddr) == false) {
      string msg;
      string ibuf;
      msg += "Couldn't bind to ";
      msg += bindAddr;
      msg += ":";
      msg += Integer2String(port, ibuf);;
      Debug::warning(msg.c_str());
      ret = false;
      continue;
    }
    add(httpServer);
  }
  return ret;
}

////////////////////////////////////////////////
//  start/stop
////////////////////////////////////////////////

void HTTPServerList::start() {
  size_t nServers = size();
  for (size_t n = 0; n < nServers; n++) {
    HTTPServer *server = getHTTPServer(n);
    server->start();
  }
}

void HTTPServerList::stop() {
  size_t nServers = size();
  for (size_t n = 0; n < nServers; n++) {
    HTTPServer *server = getHTTPServer(n);
    server->stop();
  }
}

////////////////////////////////////////////////
// clear
////////////////////////////////////////////////

void HTTPServerList::clear() {
  size_t nServers = size();
  for (size_t n = 0; n < nServers; n++) {
    HTTPServer *server = getHTTPServer(n);
    delete server;
  }
  Vector::clear();
}
