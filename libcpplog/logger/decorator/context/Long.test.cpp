#include <libcpplog/logger/decorator/context/Long.test.hpp>
#include <libcpplog/logger/decorator/context/Long.hpp>
#include <libcpplog/logger/decorator/context/Context.test.hpp>
#include <libcpplog/logger/decorator/Decorator.test.hpp>
#include <libcpplog/logger/decorator/Message.hpp>
#include <libcpplog/debug/Debug.hpp>

#include <cassert>
#include <iostream>
#include <memory>
#include <regex>
#include <source_location>

void test_without_class_or_namespace();

int main(int argc, char* argv[]) {

	cpplog::logger::decorator::context::unit_test::LongTest test;

	test.testGetString();

	test_without_class_or_namespace();

	std::cout << "UT: logger::decorator::context::Long passed." << std::endl;
	return 0;
}

void test_without_class_or_namespace() {
	std::cout << std::source_location::current().file_name()
		<< "(" << std::source_location::current().line() << ")"
		<< ": Running test_without_class_or_namespace()" << std::endl;
	
	using namespace cpplog::logger::decorator;

	std::unique_ptr<Message> message = std::make_unique<Message>("Test message");

	std::unique_ptr<Message> messageWithLongContext
		= std::make_unique<context::Long>(std::move(message), std::source_location::current());

	using namespace cpplog::logger::decorator;
	std::regex expected(
		"Long\\.test\\.cpp:void( __cdecl | )" \
		"test_without_class_or_namespace" \
		"\\(void\\)" +
		std::string(context::unit_test::ContextTest::expectedLineFormat) +
		std::string(unit_test::DecoratorTest::escapedDefaultSeparator) +
		"Test message",
		std::regex_constants::ECMAScript);

	DEBUG("Message: '" + messageWithLongContext->getString() + "'");

	assert(std::regex_match(messageWithLongContext->getString(), expected));
}

namespace cpplog::logger::decorator::context::unit_test {

	void LongTest::testGetString() const {
		std::cout << std::source_location::current().file_name()
			<< "(" << std::source_location::current().line() << ")"
			<< ": Running testGetString()" << std::endl;

		std::unique_ptr<Message> message = std::make_unique<Message>("Test message");

		std::unique_ptr<Message> messageWithLongContext
			= std::make_unique<Long>(std::move(message), std::source_location::current());

		std::regex expected(
			"Long\\.test\\.cpp:void( __cdecl | )" \
			"cpplog::logger::decorator::context::unit_test::LongTest::testGetString" \
			"\\(void\\) const" +
			std::string(ContextTest::expectedLineFormat) +
			std::string(decorator::unit_test::DecoratorTest::escapedDefaultSeparator) +
			"Test message",
			std::regex_constants::ECMAScript);

		DEBUG("Message: '" + messageWithLongContext->getString() + "'");

		assert(std::regex_match(messageWithLongContext->getString(), expected));
	}

}