#ifndef LIBCPPLOG_DEBUG_DEBUG_TEST_HPP
#define LIBCPPLOG_DEBUG_DEBUG_TEST_HPP

namespace cpplog::debug::unit_test {

    /**
	 * @brief Unit test for the DEBUG macros
	 */
    class DebugTest {

    public:
        /**
         * @brief Test indentation behavior
         * when `DEBUG_ENTER()` gets called
         */
        void incrementIndent();

        /**
         * @brief Test indentation behavior
         * when `DEBUG_EXIT()` gets called
         */
        void decrementIndent();

    };

}

#endif