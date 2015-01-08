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
	../VectorTests.cpp \
	../MessageQueue.cpp \
	../RandomTests.cpp \
	../HTTPPacketTests.cpp \
	../NetworkInterfaceTests.cpp \
	../ParameterTests.cpp \
	../UriTests.cpp \
	../ThreadTests.cpp \
	../SocketTests.cpp \
	../SemaphoreTests.cpp \
	../HTTPStatusTests.cpp \
	../DateTests.cpp \
	../LoggerTests.cpp \
	../HTTPClientTests.cpp \
	../StringTests.cpp \
	../MutexTests.cpp \
	../HTTPServerTests.cpp \
	../HTTPTestMain.cpp \
	../HTTPRequestTests.cpp

uhttpcctestunit_LDADD = ../../lib/unix/libuhttp++.a
