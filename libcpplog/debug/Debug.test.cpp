#include <libcpplog/debug/Debug.test.hpp>
#ifndef DEBUG_BUILD
#define DEBUG_BUILD
#endif
#include <libcpplog/debug/Debug.hpp>

#include <cassert>
#include <cstddef>
#include <iostream>
#include <source_location>
#include <sstream>

int main(int argc, char* argv[]) {

    cpplog::debug::unit_test::DebugTest test;

    test.debugOut();

    test.incrementIndent();
    test.decrementIndent();

    std::cout << "UT: debug::Debug passed." << std::endl;
    return 0;
}

namespace cpplog::debug::unit_test {

	void DebugTest::debugOut() const {
        std::cout << std::source_location::current().file_name()
            << "(" << std::source_location::current().line() << ")"
            << ": Running debugOut()" << std::endl;
        
		std::stringstream logStream;
        cpplog::debug::logger.setOutput(logStream);
        cpplog::debug::logger.setFormat({ });

        DEBUG("Debug output test");
        
        cpplog::debug::logger.setOutput(cpplog::logger::Logger::defaultOutput());
		cpplog::debug::logger.setFormat(cpplog::logger::LogFormat::defaultValue());
        
        std::string expected = "Debug output test\n";

        DEBUG("Expected: '" << expected << "'");
        DEBUG("Actual: '" << logStream.str() << "'");
        
        assert(logStream.str() == expected);
	}

    void DebugTest::incrementIndent() const {
        std::cout << std::source_location::current().file_name()
            << "(" << std::source_location::current().line() << ")"
            << ": Running incrementIndent()" << std::endl;

        std::size_t indent = cpplog::debug::debugIndent;
        DEBUG_ENTER();

        assert(cpplog::debug::debugIndent == indent + 1);
    
        DEBUG_EXIT();
    }

    void DebugTest::decrementIndent() const {
        std::cout << std::source_location::current().file_name()
            << "(" << std::source_location::current().line() << ")"
            << ": Running decrementIndent()" << std::endl;

        DEBUG_ENTER();
        std::size_t indent = cpplog::debug::debugIndent;
        DEBUG_EXIT();

        assert(cpplog::debug::debugIndent == indent - 1);
    }

}