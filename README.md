# Introduction

This repository holds the source code, documentation and tests for the `C++` logging library `libcpplog`.

This `README` gives you the steps to build the library, the unit tests and examples.
[Below](#directory-structure), you will find a description of the project structure.

Documentation is provided in terms of <em>UML</em> diagrams located in the `doc` sub directories.

Refer to the [examples](#examples) for guidance on the use of this library.

# Usage

Zero release build runtime overhead debug output.

```cpp
#include <libcpplog/debug/Debug.hpp>

void MyClass::method() {
    DEBUG_ENTER();

    DEBUG();

    DEBUG_EXIT();
}
```

Logging including context via `log()` calls or stream operator `<<`. Logging comes with runtime performance costs.

```cpp
#include <libcpplog/logger/Logger.hpp>

void MyClass::method() {
    using namespace cpplog::logger;

    // Simple log.
    Logger::get().log("Test passed.");

    // Including context (file, function, line).
    Logger::get().log("Test passed.", true);

    // C style context.
    Logger::get().log("Test passed.", __FILE__, __LINE__);

    // Log message only once.
    for (int i = 0; i < 10; i++) {
        Logger::get().logOnce("Only first iteration.", true);
    }

    // Stream operator.
    Logger::get() << "Test passed." << std::endl;
}
```

# Dependencies

- <em>C++23</em>.

# Build

## Library

Build the library:
```shell
cd libcpplog
mkdir build
cd build
cmake ..
cmake --build .
```

## Examples

Set the `BUILD_EXAMPLES` option to build example applications.

```shell
cd libcpplog
mkdir build
cd build
cmake -DBUILD_EXAMPLES=ON ..
cmake --build .
```

## Tests

Set the `BUILD_UNIT_TESTS` option to build unit tests.

```shell
cd libcpplog
mkdir build
cd build
cmake -DBUILD_UNIT_TESTS=ON ..
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
mkdir -p build
cd build
cmake -DCMAKE_BUILD_TYPE=DEBUG ..
cmake --build .
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