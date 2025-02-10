#ifndef LIBCPPLOG_LOGGER_DECORATOR_CONTEXT_LONG_TEST_HPP
#define LIBCPPLOG_LOGGER_DECORATOR_CONTEXT_LONG_TEST_HPP

namespace cpplog::logger::decorator::context::unit_test {

	/**
	 * @brief Unit test for the context::Long decorator.
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