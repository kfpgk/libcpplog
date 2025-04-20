# Set path to subdirectory holding cmake scripts
set(libcpplog_cmake_code_dir "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include("${libcpplog_cmake_code_dir}/set-install-dirs.cmake")

add_library(libcpplog)

# We want to install both release and debug build on Windows
# Use postfix for unique file names
if (WIN32)
    set_target_properties(libcpplog
        PROPERTIES 
            DEBUG_POSTFIX "d"
    )
endif()

target_include_directories(libcpplog
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>
        $<INSTALL_INTERFACE:${libcpplog_INSTALL_INCLUDEDIR}>
)

include("${libcpplog_cmake_code_dir}/install.cmake")

include("${libcpplog_cmake_code_dir}/create-package.cmake")

if(BUILD_UNIT_TESTS)
    enable_testing()
endif()

add_subdirectory(debug)
add_subdirectory(logger)
add_subdirectory(utils)