#include <libcpplog/logger/Logger.test.hpp>
#include <libcpplog/logger/Logger.hpp>
#include <libcpplog/logger/LogStream.hpp>
#include <libcpplog/logger/decorator/context/Context.test.hpp>
#include <libcpplog/logger/decorator/Decorator.test.hpp>
#include <libcpplog/logger/decorator/LogLevel.test.hpp>
#include <libcpplog/logger/decorator/TimeStamp.test.hpp>
#include <libcpplog/debug/Debug.hpp>

#include <cassert>
#include <cstddef>
#include <iostream>
#include <regex>
#include <source_location>
#include <sstream>
#include <string>
#include <string_view>

int main(int argc, char* argv[]) {

    cpplog::logger::unit_test::LoggerTest test;

    test.testPlainLog();
    test.testPlainLogTwice();

    test.testPlainLogOnce();
    test.testLogOnceInTwoLines();

    test.switchOutput();

    test.testDefaultLog();

    test.testLogWithContextLogLevelTimeStamp();
    test.testLogWithTimeStampLogLevel();
    test.testLogWithLogLevelContextLogLevel();
    test.testLogWithLogLevelContextLong();

	test.testStreamString();
    test.testStreamInt();
    test.testStreamFloat();

    test.testStreamStdEndl();

    test.testStreamLogLevelRaw();

    test.testStreamLogLevel();
    test.testStreamTimeStamp();
    test.testStreamContext();
    test.testStreamLogLevelTimeStampContext();

    test.testCopyConstructor();
    test.testMoveConstructor();
    test.testCopyAssignment();
    test.testMoveAssignment();

    std::cout << "UT: logger::logger passed." << std::endl;
    return 0;
}

namespace cpplog::logger::unit_test {

	namespace exptected_format {
		const std::string logLevel{ decorator::unit_test::LogLevelTest::expectedFormat };
		const std::string timeStamp{ decorator::unit_test::TimeStampTest::expectedFormat };
		const std::string separator{ decorator::unit_test::DecoratorTest::escapedDefaultSeparator };
		const std::string lineNo{ decorator::context::unit_test::ContextTest::expectedLineFormat };
	}

    void LoggerTest::testPlainLog() const {
        std::cout << std::source_location::current().file_name()
            << "(" << std::source_location::current().line() << ")"
            << ": Running testPlainLog()" << std::endl;

        std::stringstream logStream;
        Logger logger(logStream, { });

        logger.log("Test log");

        std::string expected = "Test log\n";

        DEBUG("Expected: '" << expected << "'");
        DEBUG("Actual: '" << logStream.str() << "'");

        assert(logStream.str() == expected);
    }

    void LoggerTest::testPlainLogTwice() const {
        std::cout << std::source_location::current().file_name()
            << "(" << std::source_location::current().line() << ")"
            << ": Running testPlainLogTwice()" << std::endl;

        std::stringstream logStream;
        Logger logger(logStream, { });

        for (int i = 0; i < 2; i++) {
            logger.log("Test log");
        }

        std::string expected = "Test log\nTest log\n";

        DEBUG("Expected: '" << expected << "'");
        DEBUG("Actual: '" << logStream.str() << "'");

        assert(logStream.str() == expected);
    }

    void LoggerTest::testPlainLogOnce() const {
        std::cout << std::source_location::current().file_name()
            << "(" << std::source_location::current().line() << ")"
            << ": Running testPlainLogOnce()" << std::endl;

        std::stringstream logStream;
        Logger logger(logStream, { });

        for (int i = 0; i < 3; i++) {
            logger.logOnce("Test log");
        }

        std::string expected = "Test log\n";

        DEBUG("Expected: '" << expected << "'");
        DEBUG("Actual: '" << logStream.str() << "'");

        assert(logStream.str() == expected);
    }

    void LoggerTest::testLogOnceInTwoLines() const {
        std::cout << std::source_location::current().file_name()
            << "(" << std::source_location::current().line() << ")"
            << ": Running testLogOnceInTwoLines()" << std::endl;

        std::stringstream logStream;
        Logger logger(logStream, { });

        logger.logOnce("Test log");
        logger.logOnce("Test log");

        std::string expected = "Test log\nTest log\n";

        DEBUG("Expected: '" << expected << "'");
        DEBUG("Actual: '" << logStream.str() << "'");

        assert(logStream.str() == expected);
    }

    void LoggerTest::switchOutput() const {
        std::cout << std::source_location::current().file_name()
            << "(" << std::source_location::current().line() << ")"
            << ": Running switchOutput()" << std::endl;

        std::stringstream firstLogStream;
        std::stringstream secondLogStream;
        Logger logger;
        logger.setFormat({ });

        logger.setOutput(firstLogStream);
        logger.log("Test log");

        logger.setOutput(secondLogStream);
        logger.log("Test log 2");

        std::string expected1 = "Test log\n";
        std::string expected2 = "Test log 2\n";

        DEBUG("Expected first stream: '" << expected1 << "'");
        DEBUG("Actual first stream: '" << firstLogStream.str() << "'");

        DEBUG("Expected second stream: '" << expected2 << "'");
        DEBUG("Actual second stream: '" << secondLogStream.str() << "'");

        assert(firstLogStream.str() == expected1);
        assert(secondLogStream.str() == expected2);
    }

    void LoggerTest::testDefaultLog() const {
        std::cout << std::source_location::current().file_name()
            << "(" << std::source_location::current().line() << ")"
            << ": Running testDefaultLog()" << std::endl;

        std::stringstream logStream;
        Logger logger(logStream);

        logger.log("Test log");

        std::regex expected(
			exptected_format::logLevel + exptected_format::separator + 
            exptected_format::timeStamp + exptected_format::separator +
            "Logger\\.test\\.cpp:testDefaultLog" + 
            exptected_format::lineNo + exptected_format::separator +
            "Test log\n",
            std::regex_constants::ECMAScript);

        DEBUG("Actual: '" << logStream.str() << "'");

        assert(std::regex_match(logStream.str(), expected));
    }

    void LoggerTest::testLogWithContextLogLevelTimeStamp() const {
        std::cout << std::source_location::current().file_name()
            << "(" << std::source_location::current().line() << ")"
            << ": Running testLogWithContextLogLevelTimeStamp()" << std::endl;

        std::stringstream logStream;
        Logger logger(
            logStream,
            LogFormat {
				LogComponent::Context,
				LogComponent::LogLevel,
				LogComponent::TimeStamp });

        logger.log("Test log");

        std::regex expected(
            "Logger\\.test\\.cpp:testLogWithContextLogLevelTimeStamp" +
            exptected_format::lineNo + exptected_format::separator +
            exptected_format::logLevel + exptected_format::separator +
            exptected_format::timeStamp + exptected_format::separator +
            "Test log\n",
            std::regex_constants::ECMAScript);

        DEBUG("Actual: '" << logStream.str() << "'");

        assert(std::regex_match(logStream.str(), expected));
    }

    void LoggerTest::testLogWithTimeStampLogLevel() const {
        std::cout << std::source_location::current().file_name()
            << "(" << std::source_location::current().line() << ")"
            << ": Running testLogWithTimeStampLogLevel()" << std::endl;

        std::stringstream logStream;
        Logger logger(
            logStream,
            LogFormat{
                LogComponent::TimeStamp,
                LogComponent::LogLevel });

        logger.log("Test log");

        std::regex expected(
            exptected_format::timeStamp + exptected_format::separator +
            exptected_format::logLevel + exptected_format::separator +
            "Test log\n",
            std::regex_constants::ECMAScript);

        DEBUG("Actual: '" << logStream.str() << "'");

        assert(std::regex_match(logStream.str(), expected));
    }

    void LoggerTest::testLogWithLogLevelContextLogLevel() const {
        std::cout << std::source_location::current().file_name()
            << "(" << std::source_location::current().line() << ")"
            << ": Running testLogWithLogLevelContextLogLevel()" << std::endl;

        std::stringstream logStream;
        Logger logger(
            logStream,
            LogFormat{
                LogComponent::LogLevel,
                LogComponent::Context,
                LogComponent::LogLevel });

        logger.log("Test log");

        std::regex expected(
            exptected_format::logLevel + exptected_format::separator +
            "Logger\\.test\\.cpp:testLogWithLogLevelContextLogLevel" +
            exptected_format::lineNo + exptected_format::separator +
            exptected_format::logLevel + exptected_format::separator +
            "Test log\n",
            std::regex_constants::ECMAScript);

        DEBUG("Actual: '" << logStream.str() << "'");

        assert(std::regex_match(logStream.str(), expected));
    }

    void LoggerTest::testLogWithLogLevelContextLong() const {
        std::cout << std::source_location::current().file_name()
            << "(" << std::source_location::current().line() << ")"
            << ": Running testLogWithLogLevelContextLong()" << std::endl;

        std::stringstream logStream;
        Logger logger(
            logStream,
            LogFormat{
                LogComponent::LogLevel,
                LogComponent::ContextLong });

        logger.log("Test log");

        std::regex expected(
            exptected_format::logLevel + exptected_format::separator +
            "Logger\\.test\\.cpp:void( __cdecl | )" \
            "cpplog::logger::unit_test::LoggerTest::testLogWithLogLevelContextLong" \
            "\\(void\\) const" +
            exptected_format::lineNo + exptected_format::separator +
            "Test log\n",
            std::regex_constants::ECMAScript);

        DEBUG("Actual: '" << logStream.str() << "'");

        assert(std::regex_match(logStream.str(), expected));
    }

    void LoggerTest::testStreamString() const {
        std::cout << std::source_location::current().file_name()
            << "(" << std::source_location::current().line() << ")"
            << ": Running testStreamString()" << std::endl;

        std::stringstream logStream;
        std::string testString{ "'Test string'" };
        Logger logger(logStream);

        logger << "This is some test string: "
               << testString;

        std::string expected = "This is some test string: 'Test string'";

        DEBUG("Expected: '" << expected << "'");
        DEBUG("Actual: '" << logStream.str() << "'");

        assert(logStream.str() == expected);
    }

    void LoggerTest::testStreamInt() const {
        std::cout << std::source_location::current().file_name()
            << "(" << std::source_location::current().line() << ")"
            << ": Running testStreamInt()" << std::endl;

        std::stringstream logStream;
        Logger logger(logStream);

        logger << 53;

        std::string expected = "53";

        DEBUG("Expected: '" << expected << "'");
        DEBUG("Actual: '" << logStream.str() << "'");

        assert(logStream.str() == expected);
    }

    void LoggerTest::testStreamFloat() const {
        std::cout << std::source_location::current().file_name()
            << "(" << std::source_location::current().line() << ")"
            << ": Running testStreamFloat()" << std::endl;

        std::stringstream logStream;
        Logger logger(logStream);

        logger << 12.2;

        std::string expected = "12.2";

        DEBUG("Expected: '" << expected << "'");
        DEBUG("Actual: '" << logStream.str() << "'");

        assert(logStream.str() == expected);
    }

    void LoggerTest::testStreamStdEndl() const {
        std::cout << std::source_location::current().file_name()
            << "(" << std::source_location::current().line() << ")"
            << ": Running testStreamStdEndl()" << std::endl;

        std::stringstream logStream;
        Logger logger(logStream);

        logger << "Hello" << std::endl;

        std::string expected = "Hello\n";

        DEBUG("Expected: '" << expected << "'");
        DEBUG("Actual: '" << logStream.str() << "'");

        assert(logStream.str() == expected);
    }

    void LoggerTest::testStreamLogLevelRaw() const {
        std::cout << std::source_location::current().file_name()
            << "(" << std::source_location::current().line() << ")"
            << ": Running testStreamLogLevelRaw()" << std::endl;

        std::stringstream logStream;
        Logger logger(logStream);

        logger << LogLevel::Error;

        std::regex expected(exptected_format::logLevel + exptected_format::separator);

        DEBUG("Actual: '" << logStream.str() << "'");

        assert(std::regex_match(logStream.str(), expected));
    }

    void LoggerTest::testStreamLogLevel() const {
        std::cout << std::source_location::current().file_name()
            << "(" << std::source_location::current().line() << ")"
            << ": Running testStreamLogLevel()" << std::endl;

        std::stringstream logStream;
        Logger logger(logStream);

        logger << LogStream::logLevel(LogLevel::Error);

        std::regex expected(exptected_format::logLevel + exptected_format::separator);

        DEBUG("Actual: '" << logStream.str() << "'");

        assert(std::regex_match(logStream.str(), expected));
    }

    void LoggerTest::testStreamTimeStamp() const {
        std::cout << std::source_location::current().file_name()
            << "(" << std::source_location::current().line() << ")"
            << ": Running testStreamTimeStamp()" << std::endl;

        std::stringstream logStream;
        Logger logger(logStream);

        logger << LogStream::timeStamp();

        std::regex expected(exptected_format::timeStamp + exptected_format::separator);

        DEBUG("Actual: '" << logStream.str() << "'");

        assert(std::regex_match(logStream.str(), expected));
    }

    void LoggerTest::testStreamContext() const {
        std::cout << std::source_location::current().file_name()
            << "(" << std::source_location::current().line() << ")"
            << ": Running testStreamContext()" << std::endl;

        std::stringstream logStream;
        Logger logger(logStream);

        logger << std::source_location::current();

        std::regex expected(
            "Logger\\.test\\.cpp:testStreamContext" +
            exptected_format::lineNo + exptected_format::separator);

        DEBUG("Actual: '" << logStream.str() << "'");

        assert(std::regex_match(logStream.str(), expected));
    }

    void LoggerTest::testStreamLogLevelTimeStampContext() const {
        std::cout << std::source_location::current().file_name()
            << "(" << std::source_location::current().line() << ")"
            << ": Running testStreamLogLevelTimeStampContext()" << std::endl;

        std::stringstream logStream;
        Logger logger(logStream);

        logger << LogLevel::Error 
               << LogStream::timeStamp()
               << LogStream::context()
               << "Rich error log message";

        std::regex expected(
            exptected_format::logLevel + exptected_format::separator +
            exptected_format::timeStamp + exptected_format::separator + 
            "Logger\\.test\\.cpp:testStreamLogLevelTimeStampContext" +
            exptected_format::lineNo + exptected_format::separator +
            "Rich error log message");

        DEBUG("Actual: '" << logStream.str() << "'");

        assert(std::regex_match(logStream.str(), expected));
    }

    void LoggerTest::testStreamLogStream() const {
        std::cout << std::source_location::current().file_name()
            << "(" << std::source_location::current().line() << ")"
            << ": Running testStreamLogStream()" << std::endl;

        std::stringstream logStream;
        Logger logger(logStream);

        logger << LogStream(LogLevel::Error)
               << "Rich error log message";

        std::regex expected(
            exptected_format::logLevel + exptected_format::separator +
            exptected_format::timeStamp + exptected_format::separator +
            "Logger\\.test\\.cpp:testStreamLogLevelTimeStampContext" +
            exptected_format::lineNo + exptected_format::separator +
            "Rich error log message");

        DEBUG("Actual: '" << logStream.str() << "'");

        assert(std::regex_match(logStream.str(), expected));
    }

    void LoggerTest::testCopyConstructor() const {
        std::cout << std::source_location::current().file_name()
            << "(" << std::source_location::current().line() << ")"
            << ": Running testCopyConstructor()" << std::endl;

        std::stringstream logStream;
        Logger logger(
            logStream,
            LogFormat{ LogComponent::LogLevel });

        Logger secondLogger(logger);

        secondLogger.log("Test log");
        logger.logOnce("Another log");

        std::regex expected(
            exptected_format::logLevel + exptected_format::separator +
            "Test log\n" +
            exptected_format::logLevel + exptected_format::separator +
            "Another log\n",
            std::regex_constants::ECMAScript);

        DEBUG("Actual: '" << logStream.str() << "'");

        assert(std::regex_match(logStream.str(), expected));
    }

    void LoggerTest::testMoveConstructor() const {
        std::cout << std::source_location::current().file_name()
            << "(" << std::source_location::current().line() << ")"
            << ": Running testMoveConstructor()" << std::endl;

        std::stringstream logStream;
        Logger logger(
            logStream,
            LogFormat{ LogComponent::LogLevel });

        Logger secondLogger(std::move(logger));

        secondLogger.log("Test log");

        std::regex expected(
            exptected_format::logLevel + exptected_format::separator +
            "Test log\n",
            std::regex_constants::ECMAScript);

        DEBUG("Actual: '" << logStream.str() << "'");

        assert(std::regex_match(logStream.str(), expected));
    }

    void LoggerTest::testCopyAssignment() const {
        std::cout << std::source_location::current().file_name()
            << "(" << std::source_location::current().line() << ")"
            << ": Running testCopyAssignment()" << std::endl;

        std::stringstream logStream;
        Logger logger(
            logStream,
            LogFormat{ LogComponent::LogLevel });

        Logger secondLogger = logger;

        secondLogger.log("Test log");
        logger.logOnce("Another log");

        std::regex expected(
            exptected_format::logLevel + exptected_format::separator +
            "Test log\n" +
            exptected_format::logLevel + exptected_format::separator +
            "Another log\n",
            std::regex_constants::ECMAScript);

        DEBUG("Actual: '" << logStream.str() << "'");

        assert(std::regex_match(logStream.str(), expected));
    }

    void LoggerTest::testMoveAssignment() const {
        std::cout << std::source_location::current().file_name()
            << "(" << std::source_location::current().line() << ")"
            << ": Running testMoveAssignment()" << std::endl;

        std::stringstream logStream;
        Logger logger(
            logStream,
            LogFormat{ LogComponent::LogLevel });

        Logger secondLogger = std::move(logger);

        secondLogger.log("Test log");

        std::regex expected(
            exptected_format::logLevel + exptected_format::separator +
            "Test log\n",
            std::regex_constants::ECMAScript);

        DEBUG("Actual: '" << logStream.str() << "'");

        assert(std::regex_match(logStream.str(), expected));
    }

}