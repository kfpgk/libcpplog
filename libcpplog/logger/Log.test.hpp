#ifndef LIBCPPLOG_LOGGER_LOG_TEST_HPP
#define LIBCPPLOG_LOGGER_LOG_TEST_HPP

namespace cpplog::logger::unit_test {

    /**
     * @brief Unit test for Log functions
     * 
     * These are basic tests to verify correct
     * forwarding of `log` functions to the
	 * `logger` object. For a more comprehensive
	 * test coverage refer to the `LoggerTest` class.
     */
    class LogTest {

    public:
		/**
		 * @brief Test the `log` function
         * 
         * Log a 'plain' message without
         * additional information.
		 */
        void testPlainLog() const;

        /**
         * @brief Test the `logOnce` function
         * 
		 * Call `logOnce` multiple times from the
         * same line and verify that the message 
         * is only logged once.
         */
        void testPlainLogOnce() const;

        /**
         * @brief Test the `setOutput` function
         * 
         * Set the output to a different stream
         * in between multiple calls to logging
         * functions.
         */
        void testSetOutput() const;

        /**
         * @brief Test the `log` function with
         * functionName argument.
         * 
         * This test case tests no functionality, since this
		 * is part of the `Logger` class and included in the
         * respective unit test.
		 * It only verifies that the call to the function
         * is accepted. 
         */
        void testLogFunctionName() const;

        /**
         * @brief Test the `log` function with
         * functionName and log level argument
         * 
         * This test case tests no functionality, since this
         * is part of the `Logger` class and included in the
         * respective unit test.
         * It only verifies that the call to the function
         * is accepted.
         */
        void testLogFunctionNameWithLogLevel() const;

        /**
         * @brief Test the `log` function with 
         * exception argument
         * 
         * This test case tests no functionality, since this
         * is part of the `Logger` class and included in the
         * respective unit test.
         * It only verifies that the call to the function
         * is accepted.
         */
        void testLogException() const;

        /**
         * @brief Test the `log` function with
         * exception and log level argument
         * 
         * This test case tests no functionality, since this
         * is part of the `Logger` class and included in the
         * respective unit test.
         * It only verifies that the call to the function
         * is accepted.
         */
        void testLogExceptionWithLogLevel() const;
    };

}

#endif