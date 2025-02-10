add_executable(file_logger
    main.cpp
)

message("${CMAKE_PREFIX_PATH}")

find_package(LIBCPPLOG
    NAMES
        cpplog
        libcpplog
    REQUIRED
)

message("${LIBCPPLOG_DIR}")
message("${LIBCPPLOG_INCLUDE_DIRS}")
message("${LIBCPPLOG_LIBRARY_DIR}")

find_library(LIBCPPLOG
    NAMES
        cpplog
        libcpplog
    REQUIRED
    HINTS 
        "${LIBCPPLOG_LIBRARY_DIR}"
)

message("libcpplog found: ${LIBCPPLOG_FOUND}")
message("libcpplog include directories: ${LIBCPPLOG_INCLUDE_DIRS}")
message("libcpplog libraries: ${LIBCPPLOG_LIBRARY_DIR}")

target_link_libraries(file_logger
    PRIVATE
        cpplog
)

target_include_directories(file_logger
    PRIVATE
        "${LIBCPPLOG_INCLUDE_DIRS}"
)