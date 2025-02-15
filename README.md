# Introduction

This repository holds the source code, documentation and tests for the `C++` logging library `libcpplog`.

This `README` gives you the steps to build the library, the unit tests and examples.
[Below](#directory-structure), you will find a description of the project structure.

Documentation is provided in terms of <em>UML</em> diagrams located in the `doc` sub directories.

Refer to the [examples](#examples) for guidance on the use of this library.

# Credits

Credits to <em>Marius Bancila</em>. The default log format is based on his blog post 
[Writing a simple logging function in C++20](https://mariusbancila.ro/blog/2021/07/03/writing-a-simple-logging-function-in-c20/).

# Usage

Debug output that results in no runtime overhead for release builds.

```cpp
#include <libcpplog/debug/Debug.hpp>

void MyClass::method() {
    DEBUG_ENTER();

    int x = 5;
    DEBUG("x is " << 5);

    DEBUG_EXIT();
}
```

Logging including context via `log()` calls or stream operator `<<`. Logging comes with runtime performance costs.

```cpp
#include <libcpplog/logger/Log.hpp>

void MyClass::method() {
    using namespace cpplog::logger;

    // Simple log.
    log("Test passed.");

    // Including context (file, function, line).
    log("Test passed.");

    // Log message only once.
    for (int i = 0; i < 10; i++) {
        logOnce("Only first iteration.");
    }

    // Stream operator.
    logger << "Test passed." << std::endl;
}
```

# Dependencies

- <em>C++23</em>.

# Build

## Library

Build the library:
```shell
cd libcpplog
mkdir -p build/release
cd build/release
cmake ../..
cmake --build .
```

## Tests

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

## Debug build

Use the `CMAKE_BUILD_TYPE` option to enable debug build.

```shell
cd libcpplog
mkdir -p build/debug
cd build/debug
cmake -DCMAKE_BUILD_TYPE=DEBUG ../..
cmake --build .
```

# Installation

Building a static library is the default.
For building shared libraries use the <em>cmake</em> option `BUILD_SHARED_LIBS`. Examples see below.

## Windows

<b>MSVC</b> requires dependencies to be the same type of build as the actual target executable. 
This is why it makes sense to provide both a release build as well as a debug build library.
We achieve this by adding a `d` postfix to the library name (`libcpplogd.lib`), when performing a debug build.
This way we can install both versions of the library next to each other. The recommendation is to <b>install both</b>
[release](#windows-static-release-install) and [debug](#windows-static-debug-install) versions, so the client 
can link to whichever build it needs.

<a id="windows-static-release-install"></a>
### Static release version
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
cmake -P .\cmake_install.cmake
```

<a id="windows-static-debug-install"></a>
### Static debug version
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
cmake -P .\cmake_install.cmake
```

<a id="directory-structure"></a>
# Directory structure

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