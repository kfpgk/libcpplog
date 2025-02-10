cmake_minimum_required(VERSION 3.20)

project(libcpplog VERSION 0.1)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(BUILD_SHARED_LIBS "Build using shared libraries" OFF)
option(BUILD_UNIT_TESTS "Build unit tests" OFF)

if(CMAKE_BUILD_TYPE STREQUAL "DEBUG")
    add_compile_definitions(DEBUG_BUILD=1)
endif()

add_subdirectory(libcpplog)

if(BUILD_UNIT_TESTS)
    enable_testing()
endif()