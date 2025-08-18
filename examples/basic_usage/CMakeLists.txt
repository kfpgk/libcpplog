add_executable(basic_usage
    main.cpp
)

find_package(libcpplog 
    REQUIRED
    CONFIG
)

target_link_libraries(basic_usage
    PRIVATE
        CPPLOG::libcpplog
)

