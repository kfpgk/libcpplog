# Get access to helper functions for generating config files
include(CMakePackageConfigHelpers)

# Generate config file inside build tree
configure_package_config_file(
    cmake/config.cmake.in
    "${CMAKE_CURRENT_BINARY_DIR}/cmake/${libcpplog_config_file}"
    # cmake uses INSTALL_DESTINATION to determine and set $PACKAGE_PREFIX_DIR in the generated config 
    # file.
    # When this package is imported via find_package(libcpplog), $PACKAGE_PREFIX_DIR
    # will point to the install location (matching $CMAKE_INSTALL_PREFIX at install time).
    INSTALL_DESTINATION "${libcpplog_INSTALL_CMAKECONFIGDIR}"
)

# Install config file to install tree
install(
    FILES "${CMAKE_CURRENT_BINARY_DIR}/cmake/${libcpplog_config_file}"
    DESTINATION "${libcpplog_INSTALL_CMAKECONFIGDIR}"
    COMPONENT CMakeConfig
)