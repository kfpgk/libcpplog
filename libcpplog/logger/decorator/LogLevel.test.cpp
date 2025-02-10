#include <libcpplog/logger/decorator/LogLevel.test.hpp>
#include <libcpplog/logger/decorator/LogLevel.hpp>
#include <libcpplog/logger/decorator/Message.hpp>
#include <libcpplog/logger/decorator/Decorator.test.hpp>
#include <libcpplog/logger/LogLevel.hpp>
#include <libcpplog/debug/Debug.hpp>

#include <cassert>
#include <iostream>
#include <memory>
#include <regex>
#include <string>
#include <source_location>

int main(int argc, char* argv[]) {

	cpplog::logger::decorator::unit_test::LogLevelTest test;

	test.testGetString();

	std::cout << "UT: logger::decorator::LogLevel passed." << std::endl;
	return 0;
}

namespace cpplog::logger::decorator::unit_test {

	void LogLevelTest::testGetString() const {
		std::cout << std::source_location::current().file_name()
			<< "(" << std::source_location::current().line() << ")"
			<< ": Running testGetString()" << std::endl;

		std::unique_ptr<Message> message = std::make_unique<Message>("Test message");

		std::unique_ptr<Message> messageInclLogLevel
			= std::make_unique<LogLevel>(std::move(message), logger::LogLevel::Info);

		std::regex expected(
			std::string(expectedFormat) +
			std::string(DecoratorTest::escapedDefaultSeparator) +
			"Test message",
			std::regex_constants::ECMAScript);

		DEBUG("Message: '" + messageInclLogLevel->getString() + "'");

		assert(std::regex_match(messageInclLogLevel->getString(), expected));
	}

}