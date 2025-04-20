if(BUILD_UNIT_TESTS)
    enable_testing()

    add_executable(IndirectIterator_test
        IndirectIterator.test.cpp
    )
    target_include_directories(IndirectIterator_test 
        PRIVATE
            ${CMAKE_SOURCE_DIR}
    )
    target_link_libraries(IndirectIterator_test
        PRIVATE
            libcpplog
    )
    add_test(
        NAME "UT utils::tree::search::IndirectIterator"
        COMMAND IndirectIterator_test
    )

endif()