#ifndef LIBCPPLOG_LOGGER_LOG_FORMAT_TEST_HPP
#define LIBCPPLOG_LOGGER_LOG_FORMAT_TEST_HPP

namespace cpplog::logger::unit_test {

    /**
     * @brief Unit test for the LogFormat class
     * 
     * These are basic tests to verify correct
     * forwarding of `log` functions to the
	 * `logger` object. For a more comprehensive
	 * test coverage refer to the `LoggerTest` class.
     */
    class LogFormatTest {

    public:
		/**
		 * @brief Test construction via LogComponent elements
		 */
        void testVarTemplConstructor() const;

        /**
         * @brief Test construction via vector of LogComponents
         */
        void testVectorConstructor() const;

        /**
         * @brief Test that the class can be iterated over
         * in a range based for loop
         */
        void testRangeBasedForLoop() const;
    };

}

#endif