#ifndef LIBCPPLOG_LOGGER_LOG_REQUEST_HPP
#define LIBCPPLOG_LOGGER_LOG_REQUEST_HPP

#include <libcpplog/logger/LogLevel.hpp>

#include <source_location>

namespace cpplog::logger {

    /**
     * @brief Log request class that can be passed to the logger
     * 
     * Use this class when you want to add log meta data when
     * streaming via the stream insertion operator.
     * Streaming an instance of `LogRequest()` will log the 
     * currently configured LogFormat.
     * 
     * Log component can also be streamed independently using the
     * static methods `logLevel()`, `context()`, `timeStamp()` &
	 * `functionName()`.
     * 
     * This object can also be used to log specific meta data such
     * as a function name.
     */
    class LogRequest {

    public:
        /**
         * @brief Constructor
         * 
         * @param[in] logLevel The log level of the message
         * @param[in] location Location of the context that
         * shall be logged. Do not pass and use default.
         */
        LogRequest(
            LogLevel logLevel = log_level::defaultValue,
            const std::source_location location = std::source_location::current()) noexcept;

        /**
         * @brief Returns the stored source location
         */
        std::source_location getLocation() const noexcept;

        /**
         * @brief Returns the stored log level
         */
        LogLevel getLogLevel() const noexcept;

        /**
         * @brief Returns a log level for streaming
         * 
         * @param[in] logLevel The log level to be streamed
         */
        static LogLevel logLevel(LogLevel logLevel = log_level::defaultValue) noexcept;

        /**
         * @brief Object to transport a function name request to the
         * logger.
         */
        class Context {
        public:
            /**
             * @brief Constructor
             *
             * @param[in] location The location containing the context
             */
            Context(const std::source_location& location) noexcept;

            /**
             * @brief Extracts the location
             */
            std::source_location getLocation() const noexcept;
        private:
            std::source_location location; ///< The location containing the context
        };

        /**
         * @brief Returns a context for streaming
         * 
         * @param[in] location Location of the context that
         * shall be logged. Do not pass and use default.
         */
        static Context context(
            const std::source_location& location = std::source_location::current()) noexcept;

        /**
         * @brief Object to transport a time stamp request to the
         * logger.
         */
        class TimeStamp {};

        /**
         * @brief Returns a time stamp request for streaming
         */
        static TimeStamp timeStamp() noexcept;

        /**
         * @brief Object to transport a function name request to the
         * logger.
         */
        class FunctionName {
        public:
			/**
			 * @brief Constructor
			 *
			 * @param[in] location The location containing the function
			 */
            FunctionName(const std::source_location& location) noexcept;

			/**
			 * @brief Extracts the location
			 */
            std::source_location getLocation() const noexcept;
		private:
			std::source_location location; ///< The location containing the function
        };

        /**
         * @brief Returns a function name request for streaming
         */
        static FunctionName functionName(
            const std::source_location& location = std::source_location::current()) noexcept;

    private:
        std::source_location location; ///< source location
        LogLevel logLevelAttribute; ///< log level

    };

}

#endif