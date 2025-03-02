add_executable(basic_usage
    main.cpp
)

find_package(LIBCPPLOG
    NAMES
        cpplog
        libcpplog
    REQUIRED
)

target_link_libraries(basic_usage
    PRIVATE
        ${LIBCPPLOG}
)

target_include_directories(basic_usage
    PRIVATE
        "${LIBCPPLOG_INCLUDE_DIRS}"
)