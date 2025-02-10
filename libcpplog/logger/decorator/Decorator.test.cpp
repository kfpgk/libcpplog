#include <libcpplog/logger/decorator/Decorator.test.hpp>
#include <libcpplog/logger/decorator/Decorator.hpp>
#include <libcpplog/logger/decorator/Message.hpp>

#include <cassert>
#include <iostream>
#include <source_location>

int main(int argc, char* argv[]) {

	cpplog::logger::decorator::unit_test::DecoratorTest test;

	test.testSetAndGetSeparator();

	std::cout << "UT: logger::decorator::Decorator passed." << std::endl;
	return 0;
}

namespace cpplog::logger::decorator::unit_test {

	void DecoratorTest::testSetAndGetSeparator() const {
		std::cout << std::source_location::current().file_name()
			<< "(" << std::source_location::current().line() << ")"
			<< ": Running testSetAndGetSeparator()" << std::endl;

		Decorator::setSeparator(";");

		assert(Decorator::getSeparator() == ";");
	}

}