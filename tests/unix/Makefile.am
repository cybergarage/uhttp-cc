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
	../ThreadTests.cpp \
	../RandomTests.cpp \
	../NetworkInterfaceTests.cpp \
	../SocketTests.cpp \
	../HTTPServerTests.cpp \
	../StringTests.cpp \
	../VectorTests.cpp \
	../UriTests.cpp \
	../LoggerTests.cpp \
	../HTTPPacketTests.cpp \
	../HTTPClientTests.cpp \
	../MessageQueue.cpp \
	../ParameterTests.cpp \
	../HTTPTestMain.cpp \
	../SemaphoreTests.cpp \
	../MutexTests.cpp \
	../HTTPRequestTests.cpp \
	../DateTests.cpp

uhttpcctestunit_LDADD = ../../lib/unix/libuhttp++.a
