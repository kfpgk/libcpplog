
# libcpplog

A modern C++ logging library.

## Table of Contents

- [libcpplog](#libcpplog)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Features](#features)
  - [Usage](#usage)
    - [Logging](#logging)
    - [Debug](#debug)
  - [Dependencies](#dependencies)
  - [Build](#build)
    - [Library](#library)
    - [Tests](#tests)
    - [Debug build](#debug-build)
  - [Installation](#installation)
    - [Windows](#windows)
      - [Static release version](#static-release-version)
      - [Static debug version](#static-debug-version)
  - [Directory structure](#directory-structure)
  - [Credits](#credits)
  - [License](#license)

## Introduction

This repository holds the source code, documentation and tests for the `C++` logging library `libcpplog`.

## Features

- Simple and flexible logging interface
- Configurable log output and format
- Support for different log levels
- Stream-based logging
- No runtime overhead for debug output in release builds

## Usage

The library consists of a `logger` package and a `debug` package.

### Logging

The library provides a global `logger` object of type `Logger` in namespace `cpplog::logger`.

There are convenient functions `log` and `logOnce` inside the same namespace, that forward the calls to this global object. The following two calls are equivalent:
 - `logger.log("Some log");`
 - `log("Some log");` 

The log format can be configured via `logger.setFormat(LogFormat)`.
The log output can be configured via `logger.setOutput(std::ostream&)`.

> Important: Make sure the `ostream` that has been passed to the `Logger` (either via constructor or via `setOutput()`) does not go out of scope while the logger is using it. This would result in <b>undefined behavior</b>.

As an alternative to logging via `log()`, one can stream into the `logger` object using the stream insertion operator `<<`.

If desired, create your own logger instance using the `Logger` class.

Check below code snippets or the `examples` sub directory for examples.

```cpp
#include <libcpplog/logger/Log.hpp>

#include <sstream>
#include <string>

int main(int argc, char* argv[]) {

    using namespace cpplog::logger;

    // Arbitrary float variable for use in examples
    float myF = 40 / 2.1;

    // Use global logger via log function
    log("This is the default log format. Result: " + std::to_string(myF));

    // Specify log level explicitely
    log(LogLevel::Warning, "Result " + std::to_string(myF) + " could be too high.");

    // Use custom format LogLevel | Context | Message
    logger.setFormat( { LogComponent::LogLevel, LogComponent::Context } );

    // Log again with new format
    log("This is a log with custom log format without timestamp.");

    // Reset format to default
    logger.setFormat( { LogFormat::defaultValue() });

    // Log again with new format
    log("Logging again with default format.");

    // We can also log using the global `logger` object. This is the same as calling `log`
    logger.log("Using the global logger object");

    // Log via stream insertion operator. This is unformatted.
    logger << "Plain streamed log message" << std::endl;

    // Log using the currently configured format using the LogStream object and stream insertion operator.
    logger << LogStream(LogLevel::Error) 
           << "This is a rich error log via stream operator" << std::endl;

    // Log only log level and message via stream insertion operator.
    logger << LogLevel::Warning << "This is a streamed warning " << myF << std::endl;

    // Log only time stamp and message via stream insertion operator.
    logger << LogStream::timeStamp() 
           << "My time stamped streamed log message. Result: " 
           << myF << std::endl;

    // Log only context and message via stream insertion operator.
    logger << LogStream::context() << "This is a streamed warning including context " << std::endl;

    // Log message only once.
    for (int i = 0; i < 10; i++) {
        logOnce("Only first iteration.");
    }

    // Log to string stream instead.
    std::stringstream ss;
    logger.setOutput(ss);
    log("Log to string stream");
    std::cout << ss.str() << std::endl;

    // Create an own local logger object and use it instead of the global one
    Logger myLogger(
        std::cout,
        { LogComponent::TimeStamp, LogComponent::Context });
    myLogger.log("Custom logger");

    return 0;

}
```

### Debug

Debug output that results in no runtime overhead for release builds.

```cpp
#include <libcpplog/debug/Debug.hpp>

int main(int argc, char* argv[]) {
    DEBUG_ENTER();

    int x = 5;
    DEBUG("x is " << 5);

    DEBUG_EXIT();
    
    return 0;
}
```

## Dependencies

- <em>C++23</em>.

## Build

### Library

Build the library:
```shell
cd libcpplog
mkdir -p build/release
cd build/release
cmake ../..
cmake --build .
```

### Tests

Set the `BUILD_UNIT_TESTS` option to build unit tests.

```shell
cd libcpplog
mkdir -p build/release
cd build/release
cmake -DBUILD_UNIT_TESTS=ON ../..
cmake --build .
```

Run the tests using `ctest`
```shell
make test
```

Unit test names are preceded by `UT` in the result view.

### Debug build

Use the `CMAKE_BUILD_TYPE` option to enable debug build.

```shell
cd libcpplog
mkdir -p build/debug
cd build/debug
cmake -DCMAKE_BUILD_TYPE=DEBUG ../..
cmake --build .
```

## Installation

To install the library, follow these steps:

Building a static library is the default.
For building shared libraries use the <em>cmake</em> option `BUILD_SHARED_LIBS`. Examples see below.

### Windows

<b>MSVC</b> requires dependencies to be the same type of build as the actual target executable. 
This is why it makes sense to provide both a release build as well as a debug build library.
We achieve this by adding a `d` postfix to the library name (`libcpplogd.lib`), when performing a debug build.
This way we can install both versions of the library next to each other. The recommendation is to <b>install both</b>
[release](#windows-static-release-install) and [debug](#windows-static-debug-install) versions, so the client 
can link to whichever build it needs.

<a id="windows-static-release-install"></a>
#### Static release version
Install instructions for the static release version using `powershell`.
Use `-DCMAKE_INSTALL_PREFIX` only if you do not want to install to the default location.

```powershell
Set-Location -path libcpplog
New-Item -name build\release -ItemType Directory -Force
Set-Location build\release
cmake ..\.. -DCMAKE_INSTALL_PREFIX=<absolute-path-to-installation-dir>
cmake --build . --config Release
```
Installation may require admin privileges depending on install location. If so use a <em>administrator</em> `powershell` or `cmd` for the install command.

```powershell
cmake --build . --target install --config Release
```

<a id="windows-static-debug-install"></a>
#### Static debug version
Install instructions for the static debug version using `powershell`.
Use `-DCMAKE_INSTALL_PREFIX` only if you do not want to install to the default location.

```powershell
Set-Location -path libcpplog
New-Item -name build\debug -ItemType Directory -Force
Set-Location build\debug
cmake ..\.. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=<absolute-path-to-installation-dir>
cmake --build . --config Debug
```
Installation may require admin privileges depending on install location. If so use a <em>administrator</em> `powershell` or `cmd` for the install command.

```powershell
cmake --build . --target install --config Debug
```

<a id="directory-structure"></a>
## Directory structure

<pre>
(root)
+- examples                 # Examples using libcpplog
|   +- <em>example1</em>
|       +- CMakeLists.txt
|       +- *.cpp
+- libcpplog                # C++ log library
|   +- doc
|       +- *.puml           # UML diagram 
|   +- CMakeLists.txt
|   +- *.cpp
|   +- *.hpp
|   +- <em>component1</em>                       # C++ log library component sub directory
|       +- doc
|           +- *.puml                   # UML diagram
|       +- CMakeLists.txt
|       +- *.cpp                        # Library source file
|       +- *.hpp                        # Library header file
|       +- *.tpp                        # Library template implementation file
|       +- *.test.cpp                   # Unit tests source file
|       +- *.test.hpp                   # Unit test header file
|   +- <em>component2</em>                       # C++ log library component sub directory
|       +- doc
|           +- *.puml                   
|       +- CMakeLists.txt
|       +- *.cpp
|       +- *.hpp
|       +- *.test.cpp
|       +- *.test.hpp
+- CMakeLists.txt
</pre>

## Credits

Credits to <em>Marius Bancila</em>. The default log format is based on his blog post 
[Writing a simple logging function in C++20](https://mariusbancila.ro/blog/2021/07/03/writing-a-simple-logging-function-in-c20/).


## License

This project is licensed under the GNU GENERAL PUBLIC LICENSE - see the [LICENSE](LICENSE) file for details.