# Create targets file inside build tree
export(EXPORT ${libcpplog_TARGETS}
    FILE
        "${CMAKE_CURRENT_BINARY_DIR}/cmake/${libcpplog_targets_file}"
    NAMESPACE 
        CPPLOG::
)

# Install the the targets file to the install tree
install(EXPORT ${libcpplog_TARGETS}
    FILE
        ${libcpplog_targets_file}
    DESTINATION 
        cmake
    NAMESPACE 
        CPPLOG::
)