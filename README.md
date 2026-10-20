# uHTTP for C++

![GitHub tag (latest SemVer)](https://img.shields.io/github/v/tag/cybergarage/uhttp-cc)
[![Build Status](https://github.com/cybergarage/uhttp-cc/actions/workflows/make.yml/badge.svg)](https://github.com/cybergarage/uhttp-cc/actions/workflows/make.yml)

uHTTP is a C++ library for building HTTP clients and servers. Extracted from [mUPnP for C++](https://github.com/cybergarage/mupnp-cc), it retains HTTP and supporting network utilities without the UPnP and SOAP layers.

## Features and structure

- HTTP request, response, header, status, and parameter abstractions.
- Client requests and a server request-listener API.
- Supporting URL, socket, network-interface, thread, and synchronization utilities.
- Small command-line examples for downloading a URL and serving a local directory.

Public headers live in [`include/uhttp/`](include/uhttp/), implementations in [`src/uhttp/`](src/uhttp/), and tests in [`test/`](test/). The Automake build produces `libuhttp++.a`.

## Build from source

The Unix build needs a C++ compiler, Make, and POSIX socket/thread support. Building examples also requires libedit development headers and libraries. Tests require the Boost unit-test framework, system, thread, and filesystem libraries.

```sh
git clone https://github.com/cybergarage/uhttp-cc.git
cd uhttp-cc
./configure --enable-examples
make
```

Generated `configure` files are included. If you change the Autotools inputs or need to regenerate them, install Autoconf and Automake and run `./bootstrap` before configuring.

To install into a user-owned prefix, configure it before building:

```sh
./configure --prefix="$HOME/.local" --enable-examples
make
make install
```

### Homebrew

The project also provides a [Homebrew tap](https://github.com/cybergarage/homebrew):

```sh
brew tap cybergarage/homebrew
brew install uhttp++
```

## Run the examples

After building with `--enable-examples`, serve a directory in the foreground on port 8080:

```sh
./examples/fsserver/unix/fsserver -f -p 8080 ./doc
```

From another terminal, make a request with the example client:

```sh
./examples/httpget/unix/httpget http://127.0.0.1:8080/
```

Use a path to a file under the served directory to retrieve its contents. Stop the foreground server with Ctrl-C. The server normally defaults to daemon mode and port 80; the explicit flags above make it easier to try locally.

- [`httpget`](examples/httpget/): URL parsing and HTTP GET requests.
- [`fsserver`](examples/fsserver/): file serving through the HTTP server API.

## Testing

With the Boost and libedit dependencies installed:

```sh
./configure --enable-test --enable-examples
make
make check
```

These are the build and test steps used by [CI](.github/workflows/make.yml). Network tests require permission to create local sockets.

## Scope and limitations

This is an HTTP library with a legacy Autotools build. Do not infer TLS support, HTTP/2 or HTTP/3 support, production hardening, or performance guarantees from the HTTP APIs. Check the implementation and test the behavior needed by your application. The file server is a usage example, not a deployment guide.

## Documentation and license

- [API reference (Doxygen)](https://cybergarage.github.io/uhttp-cc/)
- [BSD-style license](COPYING)
