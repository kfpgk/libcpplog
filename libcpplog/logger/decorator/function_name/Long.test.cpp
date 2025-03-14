#include <libcpplog/logger/decorator/function_name/Long.test.hpp>
#include <libcpplog/logger/decorator/function_name/Long.hpp>
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

	cpplog::logger::decorator::function_name::unit_test::LongTest test;

	test.testGetString();

	test_without_class_or_namespace();

	std::cout << "UT: logger::decorator::function_name::Long passed." << std::endl;
	return 0;
}

void test_without_class_or_namespace() {
	std::cout << std::source_location::current().file_name()
		<< "(" << std::source_location::current().line() << ")"
		<< ": Running test_without_class_or_namespace()" << std::endl;
	
	using namespace cpplog::logger::decorator;

	std::unique_ptr<Message> message = std::make_unique<Message>(" message");

	std::unique_ptr<Message> messageWithLongName
		= std::make_unique<
			function_name::Long>(std::move(message), std::source_location::current(), false);

	std::regex expected(
		"void( __cdecl | )test_without_class_or_namespace\\(void\\)" \
		" message",
		std::regex_constants::ECMAScript);

	DEBUG("Message: '" + messageWithLongName->getString() + "'");

	assert(std::regex_match(messageWithLongName->getString(), expected));
}

namespace cpplog::logger::decorator::function_name::unit_test {

	void LongTest::testGetString() const {
		std::cout << std::source_location::current().file_name()
			<< "(" << std::source_location::current().line() << ")"
			<< ": Running testGetString()" << std::endl;

		std::unique_ptr<Message> message = std::make_unique<Message>(" message");

		std::unique_ptr<Message> messageWithLongName
			= std::make_unique<Long>(std::move(message), std::source_location::current(), false);

		std::regex expected(
			"void( __cdecl | )cpplog::logger::decorator::function_name::unit_test::LongTest::testGetString" \
			"\\(void\\) const" \
			" message",
			std::regex_constants::ECMAScript);

		DEBUG("Message: '" + messageWithLongName->getString() + "'");

		assert(std::regex_match(messageWithLongName->getString(), expected));
	}

}