add_executable(basic_usage
    main.cpp
)

find_package(libcpplog
    NAMES
        cpplog
        libcpplog
    REQUIRED
)

get_target_property(libcpplog_INCLUDE_DIR CPPLOG::libcpplog INTERFACE_INCLUDE_DIRECTORIES)

target_include_directories(basic_usage
    PRIVATE
        "${libcpplog_INCLUDE_DIR}"
)

target_link_libraries(basic_usage
    PRIVATE
        CPPLOG::libcpplog
)

