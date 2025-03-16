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
	../RandomTests.cpp \
	../ParameterTests.cpp \
	../HTTPStatusTests.cpp \
	../HTTPTestMain.cpp \
	../StringTests.cpp \
	../DateTests.cpp \
	../LoggerTests.cpp \
	../HTTPPacketTests.cpp \
	../ThreadTests.cpp \
	../HTTPServerTests.cpp \
	../SocketTests.cpp \
	../SemaphoreTests.cpp \
	../VectorTests.cpp \
	../HTTPClientTests.cpp \
	../MessageQueue.cpp \
	../NetworkInterfaceTests.cpp \
	../UriTests.cpp \
	../MutexTests.cpp \
	../HTTPRequestTests.cpp

uhttpcctest_LDADD = ../../lib/unix/libuhttp++.a
