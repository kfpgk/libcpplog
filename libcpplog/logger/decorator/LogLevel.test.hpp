#ifndef LIBCPPLOG_LOGGER_DECORATOR_LOG_LEVEL_TEST_HPP
#define LIBCPPLOG_LOGGER_DECORATOR_LOG_LEVEL_TEST_HPP

#include <string_view>

namespace cpplog::logger::decorator::unit_test {

	/**
	 * @brief Unit test for LogLevel
	 */
	class LogLevelTest {

	public:
		///< The expected log level format including escape characters for use in regular expressions
		static constexpr std::string_view expectedFormat{
			"\\[[A-Z]\\]" };

		/**
		 * @brief Test the `getString()` method
		 *
		 * Decorate a message with a log level and check the resulting string
		 */
		void testGetString() const;

	};

}

#endif