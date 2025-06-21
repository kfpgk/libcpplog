add_subdirectory(search)

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
        NAME "UT utils::tree::IndirectIterator"
        COMMAND IndirectIterator_test
    )

    add_executable(TreeNode_test
        Node.test.cpp
    )
    target_include_directories(TreeNode_test 
        PRIVATE
            ${CMAKE_SOURCE_DIR}
    )
    target_link_libraries(TreeNode_test
        PRIVATE
            libcpplog
    )
    add_test(
        NAME "UT utils::tree::Node"
        COMMAND TreeNode_test
    )

endif()