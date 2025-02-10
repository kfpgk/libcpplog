#ifndef LIBCPPLOG_LOGGER_LOGGER_TEST_HPP
#define LIBCPPLOG_LOGGER_LOGGER_TEST_HPP

namespace cpplog::logger::unit_test {

    /**
     * @brief Unit test Logger including Logger::Impl
     */
    class LoggerTest {

    public:
        /**
         * @brief Test the `log` function
         *
         * Log a 'plain' message without
         * additional information.
         */
        void testPlainLog() const;

        /**
		 * @brief Test calling `log` twice
         *
         * Log a 'plain' message twice from same line
         * and verify it is being logged twice (in
		 * contrast to `logOnce`).
         */
        void testPlainLogTwice() const;

        /**
         * @brief Test `logOnce` in one line
         * 
         * Call `logOnce` multiple times from the
         * same line and verify that the message 
         * is only logged once.
         */
        void testPlainLogOnce() const;

        /**
         * @brief Test `logOnce` in different lines
         *
         * Call `logOnce` multiple times from different
         * lines and verify that the message is logged 
         * multiple times.
         */
        void testLogOnceInTwoLines() const;

        /**
         * @brief Test the `setOutput` function
         *
         * Set the output to a different stream
         * in between multiple calls to logging
         * functions.
         */
        void switchOutput() const;

        /**
         * @brief Test logging with the default log format
         */
        void testDefaultLog() const;

        /**
         * @brief Test logging with custom log format
         * 
         * Test custom log format:
         *  - Context
         *  - LogLevel
         *  - TimeStamp
         */
        void testLogWithContextLogLevelTimeStamp() const;

        /**
         * @brief Test logging with custom log format
         *
         * Test custom log format:
         *  - TimeStamp
         *  - LogLevel
         */
        void testLogWithTimeStampLogLevel() const;

        /**
         * @brief Test logging with custom log format
         *
         * Test custom log format:
         *  - LogLevel
         *  - Context
         *  - LogLevel
         */
        void testLogWithLogLevelContextLogLevel() const;

        /**
         * @brief Test logging with custom log format
         *
         * Test custom log format:
         *  - LogLevel
         *  - ContextLong
         */
        void testLogWithLogLevelContextLong() const;

        /**
         * @brief Test basic log via stream insertion 
         * operator 
         */
		void testStreamInsertionOperator() const;
    };

}

#endif