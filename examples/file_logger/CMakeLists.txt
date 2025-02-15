add_executable(file_logger
    main.cpp
)


find_package(LIBCPPLOG
    NAMES
        cpplog
        libcpplog
    REQUIRED
)

find_library(LIBCPPLOG
    NAMES
        cpplog
        libcpplog
    REQUIRED
    HINTS 
        "${LIBCPPLOG_LIBRARY_DIR}"
)

target_link_libraries(file_logger
    PRIVATE
        ${LIBCPPLOG}
)

target_include_directories(file_logger
    PRIVATE
        "${LIBCPPLOG_INCLUDE_DIRS}"
)