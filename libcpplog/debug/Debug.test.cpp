#include <libcpplog/debug/Debug.test.hpp>
#ifndef DEBUG_BUILD
#define DEBUG_BUILD
#endif
#include <libcpplog/debug/Debug.hpp>

#include <cassert>
#include <cstddef>
#include <iostream>

int main(int argc, char* argv[]) {

    cpplog::debug::unit_test::DebugTest test;

    test.incrementIndent();
    test.decrementIndent();

    std::cout << "UT: debug::Debug passed." << std::endl;
    return 0;
}

namespace cpplog::debug::unit_test {

    void DebugTest::incrementIndent() {
        std::cout << __FILE__ << "(" << __LINE__ << "): Running incrementIndent()" << std::endl;

        std::size_t indent = cpplog::debug::debugIndent;
        DEBUG_ENTER();

        assert(cpplog::debug::debugIndent == indent + 1);
    
        DEBUG_EXIT();
    }

    void DebugTest::decrementIndent() {
        std::cout << __FILE__ << "(" << __LINE__ << "): Running incrementIndent()" << std::endl;

        DEBUG_ENTER();
        std::size_t indent = cpplog::debug::debugIndent;
        DEBUG_EXIT();

        assert(cpplog::debug::debugIndent == indent - 1);
    }

}