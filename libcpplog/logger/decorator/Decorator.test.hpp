#ifndef LIBCPPLOG_LOGGER_DECORATOR_DECORATOR_TEST_HPP
#define LIBCPPLOG_LOGGER_DECORATOR_DECORATOR_TEST_HPP

#include <string_view>

namespace cpplog::logger::decorator::unit_test {

	/**
	 * @brief Unit test for Decorator
	 */
	class DecoratorTest {

	public:
		///< The default separator including escape characters for use in regular expressions
		static constexpr std::string_view escapedDefaultSeparator{ " \\| " }; 

		/**
		 * @brief Test the static `setSeparator()` and `getSeparator()` methods 
		 */
		void testSetAndGetSeparator() const;
	};

}

#endif