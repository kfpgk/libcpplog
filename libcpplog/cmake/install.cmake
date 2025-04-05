set(libcpplog_TARGETS libcpplog-targets)

set(PUBLIC_HEADERS
    debug/Debug.hpp
    logger/Log.hpp
    logger/Logger.hpp
    logger/LogComponent.hpp
    logger/LogFormat.hpp
    logger/LogLevel.hpp
    logger/LogRequest.hpp
)

install(TARGETS libcpplog 
    EXPORT ${libcpplog_TARGETS}
    RUNTIME DESTINATION "${libcpplog_INSTALL_BINDIR}"
    LIBRARY DESTINATION "${libcpplog_INSTALL_LIBDIR}"
    ARCHIVE DESTINATION "${libcpplog_INSTALL_LIBDIR}"
    INCLUDES DESTINATION "${libcpplog_INSTALL_INCLUDEDIR}"
)

foreach(header_file ${PUBLIC_HEADERS})
    get_filename_component(header_dir ${header_file} DIRECTORY)
    install(
        FILES 
            ${header_file} 
        DESTINATION 
            "${libcpplog_INSTALL_INCLUDEDIR}/libcpplog/${header_dir}"
        COMPONENT
            Devel)
endforeach()