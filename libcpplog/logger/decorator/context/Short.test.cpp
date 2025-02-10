#include <libcpplog/logger/decorator/context/Short.test.hpp>
#include <libcpplog/logger/decorator/context/Short.hpp>
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
void const_test_without_class_or_namespace();

int main(int argc, char* argv[]) {

	cpplog::logger::decorator::context::unit_test::ShortTest test;

	test.testGetStringConst();
	test.testGetStringNonConst();
	test.testGetStringWithConstInNameconst();
	test.constTestGetStringWithConstInName();

	test.testGetStringNoexcept();

	test_without_class_or_namespace();
	const_test_without_class_or_namespace();

	std::cout << "UT: logger::decorator::context::Short passed." << std::endl;
	return 0;
}

void test_without_class_or_namespace() {
	std::cout << std::source_location::current().file_name()
		<< "(" << std::source_location::current().line() << ")"
		<< ": Running test_without_class_or_namespace()" << std::endl;
	
	using namespace cpplog::logger::decorator;

	std::unique_ptr<Message> message = std::make_unique<Message>("Test message");

	std::unique_ptr<Message> messageWithShortContext
		= std::make_unique<context::Short>(std::move(message), std::source_location::current());

	std::regex expected(
		"Short\\.test\\.cpp:test_without_class_or_namespace" +
		std::string(context::unit_test::ContextTest::expectedLineFormat) +
		std::string(unit_test::DecoratorTest::escapedDefaultSeparator) +
		"Test message",
		std::regex_constants::ECMAScript);
	DEBUG("Message: '" + messageWithShortContext->getString() + "'");

	assert(std::regex_match(messageWithShortContext->getString(), expected));
}

void const_test_without_class_or_namespace() {
	std::cout << std::source_location::current().file_name()
		<< "(" << std::source_location::current().line() << ")"
		<< ": Running const_test_without_class_or_namespace()" << std::endl;

	using namespace cpplog::logger::decorator;

	std::unique_ptr<Message> message = std::make_unique<Message>("Test message");

	std::unique_ptr<Message> messageWithShortContext
		= std::make_unique<context::Short>(std::move(message), std::source_location::current());

	std::regex expected(
		"Short\\.test\\.cpp:const_test_without_class_or_namespace" +
		std::string(context::unit_test::ContextTest::expectedLineFormat) +
		std::string(unit_test::DecoratorTest::escapedDefaultSeparator) +
		"Test message",
		std::regex_constants::ECMAScript);
	DEBUG("Message: '" + messageWithShortContext->getString() + "'");

	assert(std::regex_match(messageWithShortContext->getString(), expected));
}

namespace cpplog::logger::decorator::context::unit_test {

	void ShortTest::testGetStringConst() const {
		std::cout << std::source_location::current().file_name()
			<< "(" << std::source_location::current().line() << ")"
			<< ": Running testGetStringConst()" << std::endl;

		std::unique_ptr<Message> message = std::make_unique<Message>("Test message");

		std::unique_ptr<Message> messageWithShortContext
			= std::make_unique<Short>(std::move(message), std::source_location::current());

		std::regex expected(
			"Short\\.test\\.cpp:testGetStringConst" +
			std::string(ContextTest::expectedLineFormat) +
			std::string(decorator::unit_test::DecoratorTest::escapedDefaultSeparator) +
			"Test message",
			std::regex_constants::ECMAScript);

		DEBUG("Message: '" + messageWithShortContext->getString() + "'");

		assert(std::regex_match(messageWithShortContext->getString(), expected));
	}

	void ShortTest::testGetStringNonConst() {
		std::cout << std::source_location::current().file_name()
			<< "(" << std::source_location::current().line() << ")"
			<< ": Running testGetStringNonConst()" << std::endl;

		std::unique_ptr<Message> message = std::make_unique<Message>("Test message");

		std::unique_ptr<Message> messageWithShortContext
			= std::make_unique<Short>(std::move(message), std::source_location::current());

		std::regex expected(
			"Short\\.test\\.cpp:testGetStringNonConst" +
			std::string(ContextTest::expectedLineFormat) +
			std::string(decorator::unit_test::DecoratorTest::escapedDefaultSeparator) +
			"Test message",
			std::regex_constants::ECMAScript);
		DEBUG("Message: '" + messageWithShortContext->getString() + "'");

		assert(std::regex_match(messageWithShortContext->getString(), expected));
	}

	void ShortTest::testGetStringWithConstInNameconst() {
		std::cout << std::source_location::current().file_name()
			<< "(" << std::source_location::current().line() << ")"
			<< ": Running testGetStringWithConstInNameconst()" << std::endl;

		std::unique_ptr<Message> message = std::make_unique<Message>("Test message");

		std::unique_ptr<Message> messageWithShortContext
			= std::make_unique<Short>(std::move(message), std::source_location::current());

		std::regex expected(
			"Short\\.test\\.cpp:testGetStringWithConstInNameconst" +
			std::string(ContextTest::expectedLineFormat) +
			std::string(decorator::unit_test::DecoratorTest::escapedDefaultSeparator) +
			"Test message",
			std::regex_constants::ECMAScript);
		DEBUG("Message: '" + messageWithShortContext->getString() + "'");

		assert(std::regex_match(messageWithShortContext->getString(), expected));
	}

	void ShortTest::constTestGetStringWithConstInName() {
		std::cout << std::source_location::current().file_name()
			<< "(" << std::source_location::current().line() << ")"
			<< ": Running constTestGetStringWithConstInName()" << std::endl;

		std::unique_ptr<Message> message = std::make_unique<Message>("Test message");

		std::unique_ptr<Message> messageWithShortContext
			= std::make_unique<Short>(std::move(message), std::source_location::current());

		std::regex expected(
			"Short\\.test\\.cpp:constTestGetStringWithConstInName" +
			std::string(ContextTest::expectedLineFormat) +
			std::string(decorator::unit_test::DecoratorTest::escapedDefaultSeparator) +
			"Test message",
			std::regex_constants::ECMAScript);
		DEBUG("Message: '" + messageWithShortContext->getString() + "'");

		assert(std::regex_match(messageWithShortContext->getString(), expected));
	}

	void ShortTest::testGetStringNoexcept() noexcept(true) {
		std::cout << std::source_location::current().file_name()
			<< "(" << std::source_location::current().line() << ")"
			<< ": Running testGetStringNoexcept()" << std::endl;

		std::unique_ptr<Message> message = std::make_unique<Message>("Test message");

		std::unique_ptr<Message> messageWithShortContext
			= std::make_unique<Short>(std::move(message), std::source_location::current());

		std::regex expected(
			"Short\\.test\\.cpp:testGetStringNoexcept" +
			std::string(ContextTest::expectedLineFormat) +
			std::string(decorator::unit_test::DecoratorTest::escapedDefaultSeparator) +
			"Test message",
			std::regex_constants::ECMAScript);
		DEBUG("Message: '" + messageWithShortContext->getString() + "'");

		assert(std::regex_match(messageWithShortContext->getString(), expected));
	}

}