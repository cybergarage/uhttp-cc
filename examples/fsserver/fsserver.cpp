/******************************************************************
 *
 * uHTTP for C++
 *
 * Copyright (C) Satoshi Konno 2002-2013
 *
 * This is licensed under BSD-style license, see file COPYING.
 *
 ******************************************************************/

#include <iostream>
#include <map>
#include <string>

#include <histedit.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

#include "FileServer.h"

using namespace std;
using namespace uHTTP;

void usage(char* argv[])
{
  std::string programName = argv[0];
  size_t lastPathIndex = programName.find_last_of("/");
  if (lastPathIndex != std::string::npos)
    programName = programName.substr((lastPathIndex + 1));

  cout << "Usage: " << programName << " <root directory>" << endl;
  cout << " -f, Enable foreground  mode" << endl;
  cout << " -h, This help text" << endl;
  cout << " -p <port number>, Port number" << endl;
  cout << " -v, Enable verbose mode" << endl;
}

int main(int argc, char* argv[])
{
  bool deamonMode = true;
  bool verboseMode = false;
  int httpdPort = 80;

  int ch;
  while ((ch = getopt(argc, argv, "fhvp:")) != -1) {
    switch (ch) {
    case 'v': {
      verboseMode = true;
    } break;
    case 'f': {
      deamonMode = false;
    } break;
    case 'p': {
      httpdPort = atoi(optarg);
    } break;
    case 'h':
    case '?':
    default: {
      usage(argv);
      exit(EXIT_SUCCESS);
    }
    }
  }

  argc -= optind;
  argv += optind;

  if (argc < 1) {
    usage((argv - optind));
    return EXIT_FAILURE;
  }

  string roodDirectory = argv[0];
  if (roodDirectory.at(roodDirectory.length() - 1) == '/') {
    roodDirectory = roodDirectory.substr(0, roodDirectory.length() - 1);
  }

  if (deamonMode) {
    int pid = fork();
    if (pid < 0)
      exit(EXIT_FAILURE);

    if (0 < pid)
      exit(EXIT_SUCCESS);

    if (setsid() < 0)
      exit(EXIT_FAILURE);

    umask(0);

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
  }

  FileServer fileServer;
  fileServer.setRootDirectory(roodDirectory);
  fileServer.setPort(httpdPort);
  if (fileServer.start() == false) {
    exit(EXIT_FAILURE);
  }

  sigset_t sigSet;
  if (sigfillset(&sigSet) != 0)
    exit(EXIT_FAILURE);

  bool isRunnging = true;

  while (isRunnging) {
    int sigNo;
    if (sigwait(&sigSet, &sigNo) != 0)
      break;
    switch (sigNo) {
    case SIGTERM:
    case SIGINT:
    case SIGKILL: {
      fileServer.stop();
      isRunnging = false;
    } break;
    case SIGHUP: {
      if (fileServer.restart() == false) {
        exit(EXIT_FAILURE);
      }
    } break;
    }
  }

  return EXIT_SUCCESS;
}
