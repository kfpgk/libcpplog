# Get access to helper functions for generating config files
include(CMakePackageConfigHelpers)

# Generate the file inside the build tree
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/cmake/${libcpplog_config_version_file}"
    VERSION ${libcpplog_VERSION}
    COMPATIBILITY AnyNewerVersion
)

# Install the file to the install tree
install(
    FILES "${CMAKE_CURRENT_BINARY_DIR}/cmake/${libcpplog_config_version_file}"
    DESTINATION "${libcpplog_INSTALL_CMAKECONFIGDIR}"
    COMPONENT CMakeConfig
)