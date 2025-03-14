target_sources(libcpplog
    PRIVATE
        FunctionName.cpp
        Long.cpp
        LongStore.cpp
        Short.cpp
        ShortStore.cpp
)

if(BUILD_UNIT_TESTS)
    enable_testing()

    add_executable(ShortFunctionName_test
        Short.test.cpp
    )
    target_include_directories(ShortFunctionName_test 
        PRIVATE
            ${CMAKE_SOURCE_DIR}
    )
    target_link_libraries(ShortFunctionName_test
        PRIVATE
            libcpplog
    )
    add_test(
        NAME "UT logger::decorator::function_name::Short"
        COMMAND ShortFunctionName_test
    )

    add_executable(LongFunctionName_test
        Long.test.cpp
    )
    target_include_directories(LongFunctionName_test 
        PRIVATE
            ${CMAKE_SOURCE_DIR}
    )
    target_link_libraries(LongFunctionName_test
        PRIVATE
            libcpplog
    )
    add_test(
        NAME "UT logger::decorator::function_name::Long"
        COMMAND LongFunctionName_test
    )

endif()