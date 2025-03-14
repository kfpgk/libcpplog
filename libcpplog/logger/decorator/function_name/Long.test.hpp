#ifndef LIBCPPLOG_LOGGER_DECORATOR_FUNCTION_NAME_LONG_TEST_HPP
#define LIBCPPLOG_LOGGER_DECORATOR_FUNCTION_NAME_LONG_TEST_HPP

namespace cpplog::logger::decorator::function_name::unit_test {

	/**
	 * @brief Unit test for the function_name::Long decorator.
	 */
	class LongTest {

	public:
		/**
		 * @brief Test the `getString()` method
		 *
		 * Decorate a message with long context information and check the resulting string
		 */
		void testGetString() const;

	};

}

#endif