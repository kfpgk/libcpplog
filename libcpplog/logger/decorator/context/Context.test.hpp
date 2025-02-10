#ifndef LIBCPPLOG_LOGGER_DECORATOR_CONTEXT_CONTEXT_TEST_HPP
#define LIBCPPLOG_LOGGER_DECORATOR_CONTEXT_CONTEXT_TEST_HPP

#include <string_view>

namespace cpplog::logger::decorator::context::unit_test {

	/**
	 * @brief Unit test for the Context decorator.
	 */
	class ContextTest {
	public:
		///< The default separator including escape characters for use in regular expressions
		static constexpr std::string_view expectedLineFormat{ "\\([0-9]+:[0-9]+\\)" };
	};
}

#endif