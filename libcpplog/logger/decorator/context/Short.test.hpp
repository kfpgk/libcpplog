#ifndef LIBCPPLOG_LOGGER_DECORATOR_CONTEXT_SHORT_TEST_HPP
#define LIBCPPLOG_LOGGER_DECORATOR_CONTEXT_SHORT_TEST_HPP

namespace cpplog::logger::decorator::context::unit_test {

	/**
	 * @brief Unit test for the context::Short decorator.
	 */
	class ShortTest {

	public:
		/**
		 * @brief Test the `getString()` method with a `const` caller
		 *
		 * Decorate a message with short context information and check the resulting string
		 * The complete name and signature of the calling function is processed so `const`
		 * makes a difference.
		 */
		void testGetStringConst() const;

		/**
		 * @brief Test the `getString()` method with a non-`const` caller
		 *
		 * Decorate a message with short context information and check the resulting string
		 * The complete name and signature of the calling function is processed so `const`
		 * makes a difference.
		 */
		void testGetStringNonConst();

		/**
		 * @brief Test the `getString()` method called from a function with 'const' in name
		 *
		 * Decorate a message with short context information and check the resulting string
		 * `const` specifier gets remove but 'const' inside function name should be left 
		 * untouched.
		 */
		void testGetStringWithConstInNameconst();

		/**
		 * @brief Test the `getString()` method called from a function with name starting with 'const'
		 *
		 * Decorate a message with short context information and check the resulting string
		 * `const` specifier gets remove but 'const' inside function name should be left
		 * untouched.
		 */
		void constTestGetStringWithConstInName();

		/**
		 * @brief Test the `getString()` method with a `noexcept(true)` specifier
		 *
		 * Decorate a message with short context information and check the resulting string
		 * The complete name and signature of the calling function is processed so `const`
		 * makes a difference.
		 */
		void testGetStringNoexcept() noexcept(true);

	};

}

#endif