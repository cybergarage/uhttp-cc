# uHTTP for C++

![GitHub tag (latest SemVer)](https://img.shields.io/github/v/tag/cybergarage/uhttp-cc)
[![Build Status](https://github.com/cybergarage/uhttp-cc/actions/workflows/make.yml/badge.svg)](https://github.com/cybergarage/uhttp-cc/actions/workflows/make.yml)

uHTTP for C++ is a developer framework for HTTP client and server applications. The framework was forked from [mUPnP for C++](https://github.com/cybergarage/mupnp-cc) v1.7.2 except the UPnP and SOAP functions.

[mUPnP for C++](https://github.com/cybergarage/mupnp-cc) was developed for embedded platforms, but I will improve the framework for enterprise platforms in the future.

uHTTP for C++ aims to provide a lightweight and efficient solution for building HTTP-based applications. It supports both client and server functionalities, making it versatile for various use cases. The framework is designed to be easy to integrate and use, with a focus on performance and scalability.

## Building and Installation

uHTTP for C++ is distributed as an Automake project, and so you can install the library from the source codes with the following commands:

```
./bootstrap
./configure
make install
```

These commands will configure the build environment, compile the source code, and install the library on your system. Ensure that you have the necessary build tools and dependencies installed before running these commands.

### macOS

For macOS platforms, you can easily install using Homebrew with the following `brew` commands:

```
brew tap cybergarage/homebrew
brew install uhttp++
```

This will add the cybergarage tap to Homebrew and install the uHTTP++ library. Homebrew simplifies the installation process by managing dependencies and configurations automatically.

## References

- [Doxygen](http://cybergarage.github.io/uhttp-cc/)

The Doxygen documentation provides detailed information about the API and usage of the uHTTP for C++ framework. It is a valuable resource for developers looking to understand the internals and capabilities of the library.

## Examples

- [httpget](https://github.com/cybergarage/uhttp-cc/tree/master/examples/httpget) 
  - A simple HTTP client application similar to the curl utility. This example demonstrates how to perform HTTP GET requests using the uHTTP for C++ framework.
- [fsserver](https://github.com/cybergarage/uhttp-cc/tree/master/examples/fsserver)
  - A simple HTTP server application that returns file contents from a specified local directory. This example shows how to set up a basic HTTP server using the framework.

These examples provide practical demonstrations of how to use the uHTTP for C++ framework to build real-world applications. They serve as a good starting point for developers to learn and experiment with the library.
