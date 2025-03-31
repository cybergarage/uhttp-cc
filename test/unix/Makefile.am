############################################################
#
# uHTTP for C++
#
# Copyright (C) Satoshi Konno 2002
#
############################################################

TESTS = uhttpcctest
noinst_PROGRAMS = uhttpcctest

AM_CPPFLAGS = -I$(top_srcdir)/include -I../

uhttpcctest_SOURCES = \
	..//DateTests.cpp \
	..//HTTPTestMain.cpp \
	..//HTTPClientTests.cpp \
	..//MessageQueue.cpp \
	..//UriTests.cpp \
	..//HTTPPacketTests.cpp \
	..//RandomTests.cpp \
	..//SemaphoreTests.cpp \
	..//HTTPRequestTests.cpp \
	..//ThreadTests.cpp \
	..//MutexTests.cpp \
	..//ParameterTests.cpp \
	..//HTTPServerTests.cpp \
	..//SocketTests.cpp \
	..//StringTests.cpp \
	..//HTTPStatusTests.cpp \
	..//LoggerTests.cpp \
	..//NetworkInterfaceTests.cpp \
	..//VectorTests.cpp

uhttpcctest_LDADD = ../../lib/unix/libuhttp++.a
