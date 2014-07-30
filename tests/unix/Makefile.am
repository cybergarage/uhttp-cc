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
	..//DateTests.cpp \
	..//HTTPClientTests.cpp \
	..//HTTPPacketTests.cpp \
	..//HTTPRequestTests.cpp \
	..//HTTPServerTests.cpp \
	..//HTTPTestMain.cpp \
	..//LoggerTests.cpp \
	..//MutexTests.cpp \
	..//NetworkInterfaceTests.cpp \
	..//RandomTests.cpp \
	..//SemaphoreTests.cpp \
	..//SocketTests.cpp \
	..//StringTests.cpp \
	..//ThreadTests.cpp \
	..//UriTests.cpp \
	..//VectorTests.cpp

uhttpcctestunit_LDADD = ../../lib/unix/libuhttp++.a
