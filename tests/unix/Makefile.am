############################################################
#
# uHTTP for C++
#
# Copyright (C) Satoshi Konno 2002
#
############################################################

noinst_PROGRAMS = uhttpcctestunit

AM_CPPFLAGS = -I$(top_srcdir)/include -I../

uhttpcctestunit_SOURCES = \
	..//uHTTDateTests.cpp \
	..//uHTTPGetTests.cpp \
	..//uHTTPLoggerTests.cpp \
	..//uHTTPMutexTests.cpp \
	..//uHTTPNetworkInterfaceTests.cpp \
	..//uHTTPPacketTests.cpp \
	..//uHTTPRandomTests.cpp \
	..//uHTTPRequestTests.cpp \
	..//uHTTPSemaphoreTests.cpp \
	..//uHTTPServerTests.cpp \
	..//uHTTPSocketTests.cpp \
	..//uHTTPStringTests.cpp \
	..//uHTTPTestMain.cpp \
	..//uHTTPThreadTests.cpp \
	..//uHTTPUriTests.cpp \
	..//uHTTPVectorTests.cpp

uhttpcctestunit_LDADD = ../../lib/unix/libuhttp++.a
