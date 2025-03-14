#include <libcpplog/logger/decorator/function_name/Short.test.hpp>
#include <libcpplog/logger/decorator/function_name/Short.hpp>
#include <libcpplog/logger/decorator/Decorator.test.hpp>
#include <libcpplog/logger/decorator/Message.hpp>
#include <libcpplog/debug/Debug.hpp>

#include <cassert>
#include <iostream>
#include <memory>
#include <regex>
#include <source_location>

void test_without_class_or_namespace();
void const_test_without_class_or_namespace();

int main(int argc, char* argv[]) {

	cpplog::logger::decorator::function_name::unit_test::ShortTest test;

	test.testGetStringConst();
	test.testGetStringNonConst();
	test.testGetStringWithConstInNameconst();
	test.constTestGetStringWithConstInName();

	test.testGetStringNoexcept();

	test_without_class_or_namespace();
	const_test_without_class_or_namespace();

	std::cout << "UT: logger::decorator::function_name::Short passed." << std::endl;
	return 0;
}

void test_without_class_or_namespace() {
	std::cout << std::source_location::current().file_name()
		<< "(" << std::source_location::current().line() << ")"
		<< ": Running test_without_class_or_namespace()" << std::endl;
	
	using namespace cpplog::logger::decorator;

	std::unique_ptr<Message> message = std::make_unique<Message>(" message");

	std::unique_ptr<Message> messageWithShortName
		= std::make_unique<function_name::Short>(
			std::move(message), std::source_location::current(), false);

	std::regex expected(
		"test_without_class_or_namespace\\(\\) message",
		std::regex_constants::ECMAScript);
	DEBUG("Message: '" + messageWithShortName->getString() + "'");

	assert(std::regex_match(messageWithShortName->getString(), expected));
}

void const_test_without_class_or_namespace() {
	std::cout << std::source_location::current().file_name()
		<< "(" << std::source_location::current().line() << ")"
		<< ": Running const_test_without_class_or_namespace()" << std::endl;

	using namespace cpplog::logger::decorator;

	std::unique_ptr<Message> message = std::make_unique<Message>(" message");

	std::unique_ptr<Message> messageWithShortName
		= std::make_unique<function_name::Short>(
			std::move(message), std::source_location::current(), false);

	std::regex expected(
		"const_test_without_class_or_namespace\\(\\) message",
		std::regex_constants::ECMAScript);
	DEBUG("Message: '" + messageWithShortName->getString() + "'");

	assert(std::regex_match(messageWithShortName->getString(), expected));
}

namespace cpplog::logger::decorator::function_name::unit_test {

	void ShortTest::testGetStringConst() const {
		std::cout << std::source_location::current().file_name()
			<< "(" << std::source_location::current().line() << ")"
			<< ": Running testGetStringConst()" << std::endl;

		std::unique_ptr<Message> message = std::make_unique<Message>(" message");

		std::unique_ptr<Message> messageWithShortName
			= std::make_unique<Short>(std::move(message), std::source_location::current(), false);

		std::regex expected(
			"testGetStringConst\\(\\) message",
			std::regex_constants::ECMAScript);

		DEBUG("Message: '" + messageWithShortName->getString() + "'");

		assert(std::regex_match(messageWithShortName->getString(), expected));
	}

	void ShortTest::testGetStringNonConst() {
		std::cout << std::source_location::current().file_name()
			<< "(" << std::source_location::current().line() << ")"
			<< ": Running testGetStringNonConst()" << std::endl;

		std::unique_ptr<Message> message = std::make_unique<Message>(" message");

		std::unique_ptr<Message> messageWithShortName
			= std::make_unique<Short>(std::move(message), std::source_location::current(), false);

		std::regex expected(
			"testGetStringNonConst\\(\\) message",
			std::regex_constants::ECMAScript);
		DEBUG("Message: '" + messageWithShortName->getString() + "'");

		assert(std::regex_match(messageWithShortName->getString(), expected));
	}

	void ShortTest::testGetStringWithConstInNameconst() {
		std::cout << std::source_location::current().file_name()
			<< "(" << std::source_location::current().line() << ")"
			<< ": Running testGetStringWithConstInNameconst()" << std::endl;

		std::unique_ptr<Message> message = std::make_unique<Message>(" message");

		std::unique_ptr<Message> messageWithShortName
			= std::make_unique<Short>(std::move(message), std::source_location::current(), false);

		std::regex expected(
			"testGetStringWithConstInNameconst\\(\\) message",
			std::regex_constants::ECMAScript);
		DEBUG("Message: '" + messageWithShortName->getString() + "'");

		assert(std::regex_match(messageWithShortName->getString(), expected));
	}

	void ShortTest::constTestGetStringWithConstInName() {
		std::cout << std::source_location::current().file_name()
			<< "(" << std::source_location::current().line() << ")"
			<< ": Running constTestGetStringWithConstInName()" << std::endl;

		std::unique_ptr<Message> message = std::make_unique<Message>(" message");

		std::unique_ptr<Message> messageWithShortName
			= std::make_unique<Short>(std::move(message), std::source_location::current(), false);

		std::regex expected(
			"constTestGetStringWithConstInName\\(\\) message",
			std::regex_constants::ECMAScript);
		DEBUG("Message: '" + messageWithShortName->getString() + "'");

		assert(std::regex_match(messageWithShortName->getString(), expected));
	}

	void ShortTest::testGetStringNoexcept() noexcept(true) {
		std::cout << std::source_location::current().file_name()
			<< "(" << std::source_location::current().line() << ")"
			<< ": Running testGetStringNoexcept()" << std::endl;

		std::unique_ptr<Message> message = std::make_unique<Message>(" message");

		std::unique_ptr<Message> messageWithShortName
			= std::make_unique<Short>(std::move(message), std::source_location::current(), false);

		std::regex expected(
			"testGetStringNoexcept\\(\\) message",
			std::regex_constants::ECMAScript);
		DEBUG("Message: '" + messageWithShortName->getString() + "'");

		assert(std::regex_match(messageWithShortName->getString(), expected));
	}

}