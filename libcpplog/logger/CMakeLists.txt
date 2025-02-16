target_sources(libcpplog
    PRIVATE
        Log.cpp
        LogComponentOps.cpp
        LogFormat.cpp
        Logger.cpp
        LoggerImpl.cpp
)

add_subdirectory(decorator)

if(BUILD_UNIT_TESTS)
    enable_testing()

    add_executable(Log_test
        Log.test.cpp
    )
    target_include_directories(Log_test 
        PRIVATE
            ${CMAKE_SOURCE_DIR}
            ${CMAKE_BINARY_DIR}
    )
    target_link_libraries(Log_test
        PRIVATE
            libcpplog
    )
    add_test(
        NAME "UT logger::Log"
        COMMAND Log_test
    )

    add_executable(LogFormat_test
        LogFormat.test.cpp
    )
    target_include_directories(LogFormat_test 
        PRIVATE
            ${CMAKE_SOURCE_DIR}
            ${CMAKE_BINARY_DIR}
    )
    target_link_libraries(LogFormat_test
        PRIVATE
            libcpplog
    )
    add_test(
        NAME "UT logger::LogFormat"
        COMMAND LogFormat_test
    )

    add_executable(Logger_test
        Logger.test.cpp
    )
    target_include_directories(Logger_test 
        PRIVATE
            ${CMAKE_SOURCE_DIR}
            ${CMAKE_BINARY_DIR}
    )
    target_link_libraries(Logger_test
        PRIVATE
            libcpplog
    )
    add_test(
        NAME "UT logger::Logger"
        COMMAND Logger_test
    )

endif()