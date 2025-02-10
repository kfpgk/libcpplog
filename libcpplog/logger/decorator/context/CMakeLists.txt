target_sources(libcpplog
    PRIVATE
        Context.cpp
        Long.cpp
        Short.cpp
)

if(BUILD_UNIT_TESTS)
    enable_testing()

    add_executable(ShortContext_test
        Short.test.cpp
    )
    target_include_directories(ShortContext_test 
        PRIVATE
            ${CMAKE_SOURCE_DIR}
            ${CMAKE_BINARY_DIR}
    )
    target_link_libraries(ShortContext_test
        PRIVATE
            libcpplog
    )
    add_test(
        NAME "UT logger::decorator::context::Short"
        COMMAND ShortContext_test
    )

    add_executable(LongContext_test
        Long.test.cpp
    )
    target_include_directories(LongContext_test 
        PRIVATE
            ${CMAKE_SOURCE_DIR}
            ${CMAKE_BINARY_DIR}
    )
    target_link_libraries(LongContext_test
        PRIVATE
            libcpplog
    )
    add_test(
        NAME "UT logger::decorator::context::Long"
        COMMAND LongContext_test
    )

endif()