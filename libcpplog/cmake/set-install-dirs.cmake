include(GNUInstallDirs)

if(NOT DEFINED libcpplog_INSTALL_INCLUDEDIR)
  set(libcpplog_INSTALL_INCLUDEDIR "${CMAKE_INSTALL_INCLUDEDIR}")
endif()

if(NOT DEFINED libcpplog_INSTALL_BINDIR)
  set(libcpplog_INSTALL_BINDIR "${CMAKE_INSTALL_BINDIR}")
endif()

if(NOT DEFINED libcpplog_INSTALL_LIBDIR)
  set(libcpplog_INSTALL_LIBDIR "${CMAKE_INSTALL_LIBDIR}")
endif()

if(NOT DEFINED libcpplog_INSTALL_CONFIGDIR)
  set(libcpplog_INSTALL_CONFIGDIR "${CMAKE_INSTALL_PREFIX}/cmake")
endif()