target_sources(libcpplog
    PRIVATE
        Decorator.cpp
        LogLevel.cpp
        Message.cpp
        TimeStamp.cpp
)

add_subdirectory(context)

if(BUILD_UNIT_TESTS)
    enable_testing()

        add_executable(Decorator_test
        Decorator.test.cpp
    )
    target_include_directories(Decorator_test 
        PRIVATE
            ${CMAKE_SOURCE_DIR}
            ${CMAKE_BINARY_DIR}
    )
    target_link_libraries(Decorator_test
        PRIVATE
            libcpplog
    )
    add_test(
        NAME "UT logger::decorator::Decorator"
        COMMAND Decorator_test
    )

    add_executable(LogLevel_test
        LogLevel.test.cpp
    )
    target_include_directories(LogLevel_test 
        PRIVATE
            ${CMAKE_SOURCE_DIR}
            ${CMAKE_BINARY_DIR}
    )
    target_link_libraries(LogLevel_test
        PRIVATE
            libcpplog
    )
    add_test(
        NAME "UT logger::decorator::LogLevel"
        COMMAND LogLevel_test
    )

    add_executable(TimeStamp_test
        TimeStamp.test.cpp
    )
    target_include_directories(TimeStamp_test 
        PRIVATE
            ${CMAKE_SOURCE_DIR}
            ${CMAKE_BINARY_DIR}
    )
    target_link_libraries(TimeStamp_test
        PRIVATE
            libcpplog
    )
    add_test(
        NAME "UT logger::decorator::TimeStamp"
        COMMAND TimeStamp_test
    )

endif()