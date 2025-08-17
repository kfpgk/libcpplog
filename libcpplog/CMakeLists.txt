# Set path to subdirectory holding cmake scripts
set(libcpplog_cmake_code_dir "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Set global variables needed for installation and packaging
include("${libcpplog_cmake_code_dir}/set-install-dirs.cmake")
include("${libcpplog_cmake_code_dir}/set-targets-var.cmake")

add_library(libcpplog)

target_include_directories(libcpplog
    PUBLIC
        # Use source tree include directories during the build phase 
        # (for direct header access)
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>
        # Provide installed header path for downstream projects using this 
        # target via CMake's install interface
        $<INSTALL_INTERFACE:${libcpplog_INSTALL_INCLUDEDIR}>
)

# On Windows, install both release and debug builds of the library.
# Use postfix to ensure unique file names
if (WIN32)
    set_target_properties(libcpplog
        PROPERTIES 
            DEBUG_POSTFIX "d"
    )
endif()

include("${libcpplog_cmake_code_dir}/install.cmake")

include("${libcpplog_cmake_code_dir}/create-package.cmake")

if(BUILD_UNIT_TESTS)
    enable_testing()
endif()

add_subdirectory(debug)
add_subdirectory(external)
add_subdirectory(logger)
