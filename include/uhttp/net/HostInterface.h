/******************************************************************
*
* uHTTP for C++
*
* Copyright (C) Satoshi Konno 2002-2013
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef _CNET_HOSTINTERFACE_H_
#define _CNET_HOSTINTERFACE_H_

#include <uhttp/net/Socket.h>
#include <uhttp/net/NetworkInterfaceList.h>

#include <string>

namespace uHTTP {
class HostInterface {
public:
  static bool USE_LOOPBACK_ADDR;
  static bool USE_ONLY_IPV4_ADDR;
  static bool USE_ONLY_IPV6_ADDR;
  const static char *DEFAULT_IFNAME;
};

int GetNHostAddresses();
const char *GetHostAddress(int n, std::string &buf);
int GetHostAddresses(NetworkInterfaceList &netifList);

bool IsIPv6Address(const std::string &host);
const char *StripIPv6ScopeID(const std::string &addr, std::string &buf);
int GetIPv6ScopeID(const std::string &addr);
bool HasIPv4Addresses();
bool HasIPv6Addresses();

void SetHostInterface(const std::string &ifaddr);
const char *GetHostInterface();
bool HasAssignedHostInterface();

}

#endif
