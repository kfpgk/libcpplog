# Requires: libcpplog_TARGETS variable to be set in advance

include("${libcpplog_cmake_code_dir}/set-config-file-names.cmake")

include("${libcpplog_cmake_code_dir}/create-targets.cmake")
include("${libcpplog_cmake_code_dir}/create-config.cmake")
include("${libcpplog_cmake_code_dir}/create-config-version.cmake")