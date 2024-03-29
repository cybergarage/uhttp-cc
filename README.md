# µHTTP for C++

![GitHub tag (latest SemVer)](https://img.shields.io/github/v/tag/cybergarage/uhttp-cc)
[![Build Status](https://github.com/cybergarage/uhttp-cc/actions/workflows/make.yml/badge.svg)](https://github.com/cybergarage/uhttp-cc/actions/workflows/make.yml)

µHTTP for C++ is a developer framework for HTTP client and server applications. The framework was forked from [mUPnP for C++](https://github.com/cybergarage/mupnp-cc) v1.7.2 except the UPnP and SOAP functions.

[mUPnP for C++](https://github.com/cybergarage/mupnp-cc) was developing for embedded platforms, but I will improve the framework for enterprise platforms in the future.

## Building and Installation

µHTTP for C++ for C is distributed as an Automake project, and so you can install the library from the source codes with the following commands:

```
./boostrap
./configure
make install
```

### macOS

For macOS platforms, you can easily install using Homebrew with the following `brew` commands:

```
brew tap cybergarage/homebrew
brew install uhttp++
```
## References

- [Doxygen](http://cybergarage.github.io/uhttp-cc/)

## Examples

- [httpget](https://github.com/cybergarage/uhttp-cc/tree/master/examples/httpget) 
  - Simple HTTP client application like curl utility. 
- [fsserver](https://github.com/cybergarage/uhttp-cc/tree/master/examples/fsserver)
  - Simple HTTP server application to return file contents in the specified local directory.
