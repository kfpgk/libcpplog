#include <libcpplog/logger/LogFormat.test.hpp>
#include <libcpplog/logger/LogFormat.hpp>
#include <libcpplog/logger/LogComponent.hpp>

#include <cassert>
#include <iostream>
#include <source_location>
#include <vector>

int main(int argc, char* argv[]) {

    cpplog::logger::unit_test::LogFormatTest test;

    test.testVarTemplConstructor();
    test.testVectorConstructor();

    test.testRangeBasedForLoop();

    std::cout << "UT: logger::LogFormat passed." << std::endl;
    return 0;
}

namespace cpplog::logger::unit_test {

    void LogFormatTest::testVarTemplConstructor() const {
        std::cout << std::source_location::current().file_name()
            << "(" << std::source_location::current().line() << ")"
            << ": Running testVarTemplConstructor()" << std::endl;

        LogFormat logFormat(LogComponent::Context, LogComponent::TimeStamp);

    }

    void LogFormatTest::testVectorConstructor() const {
        std::cout << std::source_location::current().file_name()
            << "(" << std::source_location::current().line() << ")"
            << ": Running testVectorConstructor()" << std::endl;
        
        LogFormat logFormat(
            std::vector<LogComponent> {
                LogComponent::Context, 
                LogComponent::TimeStamp});

    }

    void LogFormatTest::testRangeBasedForLoop() const {
        std::cout << std::source_location::current().file_name()
            << "(" << std::source_location::current().line() << ")"
            << ": Running testRangeBasedForLoop()" << std::endl;

        LogFormat logFormat(LogComponent::Context, LogComponent::TimeStamp);

        std::vector<LogComponent> components;
        for (auto i : logFormat) {
            components.push_back(i);
        }

        assert(components.at(0) == LogComponent::Context);
        assert(components.at(1) == LogComponent::TimeStamp);
    }

}