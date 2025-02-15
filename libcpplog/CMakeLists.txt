add_library(libcpplog)

set_target_properties(libcpplog 
    PROPERTIES 
        PREFIX ""
)

if (WIN32)
    set_target_properties(libcpplog 
        PROPERTIES 
            DEBUG_POSTFIX "d"
    )
endif()

install(TARGETS libcpplog
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)

set(PUBLIC_INCLUDE_PREFIX include/libcpplog)
install(FILES debug/Debug.hpp DESTINATION ${PUBLIC_INCLUDE_PREFIX}/debug)
install(FILES logger/Log.hpp DESTINATION ${PUBLIC_INCLUDE_PREFIX}/logger)
install(FILES logger/Logger.hpp DESTINATION ${PUBLIC_INCLUDE_PREFIX}/logger)
install(FILES logger/LogComponent.hpp DESTINATION ${PUBLIC_INCLUDE_PREFIX}/logger)
install(FILES logger/LogFormat.hpp DESTINATION ${PUBLIC_INCLUDE_PREFIX}/logger)
install(FILES logger/LogLevel.hpp DESTINATION ${PUBLIC_INCLUDE_PREFIX}/logger)

install(FILES config/cpplogdConfig.cmake DESTINATION . CONFIGURATIONS Debug)
install(FILES config/cpplogConfig.cmake DESTINATION . CONFIGURATIONS Release)

target_include_directories(libcpplog
    PRIVATE
        ${CMAKE_SOURCE_DIR}
        ${CMAKE_BINARY_DIR}
)

if(BUILD_UNIT_TESTS)
    enable_testing()
endif()

add_subdirectory(debug)
add_subdirectory(logger)