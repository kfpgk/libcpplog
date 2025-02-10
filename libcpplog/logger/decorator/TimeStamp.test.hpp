#ifndef LIBCPPLOG_LOGGER_DECORATOR_TIME_STAMP_TEST_HPP
#define LIBCPPLOG_LOGGER_DECORATOR_TIME_STAMP_TEST_HPP

#include <string_view>

namespace cpplog::logger::decorator::unit_test {

	/**
	 * @brief Unit test for TimeStamp
	 */
	class TimeStampTest {

	public:
		///< The expected time stamp format including escape characters for use in regular expressions
		static constexpr std::string_view expectedFormat {
			"[0-9]{4}-[0-9]{2}-[0-9]{2}[0-9|:|\\.| ]* [A-Z]{3}[+|-][0-9]*" };

		/**
		 * @brief Test the `getString()` method
		 * 
		 * Decorate a message with a time stamp and check the resulting string
		 */
		void testGetString() const;

	};

}

#endif