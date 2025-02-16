#include <libcpplog/logger/Log.test.hpp>
#include <libcpplog/logger/Log.hpp>
#include <libcpplog/debug/Debug.hpp>

#include <cassert>
#include <cstddef>
#include <iostream>
#include <source_location>
#include <sstream>
#include <string>

int main(int argc, char* argv[]) {

    cpplog::logger::unit_test::LogTest test;

    test.testPlainLog();
    test.testPlainLogOnce();
    test.testSetOutput();

    std::cout << "UT: logger::log passed." << std::endl;
    return 0;
}

namespace cpplog::logger::unit_test {

    void LogTest::testPlainLog() const {
        std::cout << std::source_location::current().file_name()
            << "(" << std::source_location::current().line() << ")"
            << ": Running testPlainLog()" << std::endl;

        std::stringstream logStream;
        logger.setOutput(logStream);
        logger.setFormat({ });

        log("Test log");

        std::string expected = "Test log\n";

        DEBUG("Expected: '" << expected << "'");
        DEBUG("Actual: '" << logStream.str() << "'");

        assert(logStream.str() == expected);
    }

    void LogTest::testPlainLogOnce() const {
        std::cout << std::source_location::current().file_name()
            << "(" << std::source_location::current().line() << ")"
            << ": Running testPlainLogOnce()" << std::endl;
        
        std::stringstream logStream;
        logger.setOutput(logStream);
        logger.setFormat({ });

        for (int i = 0; i < 3; i++) {
            logOnce("Test log");
        }

        std::string expected = "Test log\n";

        DEBUG("Expected: '" << expected << "'");
        DEBUG("Actual: '" << logStream.str() << "'");

        assert(logStream.str() == expected);
    }

    void LogTest::testSetOutput() const {
        std::cout << std::source_location::current().file_name()
            << "(" << std::source_location::current().line() << ")"
            << ": Running testSetOutput()" << std::endl;

        std::stringstream firstLogStream;
        std::stringstream secondLogStream;
        logger.setFormat({ });
        
        logger.setOutput(firstLogStream);
        log("Test log");

        logger.setOutput(secondLogStream);
        log("Test log 2");

        std::string expected1 = "Test log\n";
        std::string expected2 = "Test log 2\n";

        DEBUG("Expected first stream: '" << expected1 << "'");
        DEBUG("Actual first stream: '" << firstLogStream.str() << "'");

        DEBUG("Expected second stream: '" << expected2 << "'");
        DEBUG("Actual second stream: '" << secondLogStream.str() << "'");

        assert(firstLogStream.str() == expected1);
        assert(secondLogStream.str() == expected2);
    }

}