noinst_PROGRAMS = fsserver

AM_CPPFLAGS = -I$(top_srcdir)/include -I../

fsserver_SOURCES = \
	../FileServer.cpp \
	../fsserver.cpp

fsserver_LDADD = ../../../lib/unix/libuhttp++.a
