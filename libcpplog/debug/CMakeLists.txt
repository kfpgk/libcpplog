target_sources(libcpplog
    PRIVATE
        Debug.cpp
)

if(BUILD_UNIT_TESTS)
    enable_testing()

    add_executable(Debug_test
        Debug.test.cpp
    )
    target_include_directories(Debug_test 
        PRIVATE
            ${CMAKE_SOURCE_DIR}
            ${CMAKE_BINARY_DIR}
    )
    target_link_libraries(Debug_test
        PRIVATE
            libcpplog
    )
    add_test(
        NAME "UT debug::Debug"
        COMMAND Debug_test
    )

endif()