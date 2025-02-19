#ifndef LIBCPPLOG_LOGGER_LOG_STREAM_HPP
#define LIBCPPLOG_LOGGER_LOG_STREAM_HPP

#include <libcpplog/logger/LogLevel.hpp>

#include <source_location>

namespace cpplog::logger {

    /**
     * @brief Log stream class to created formatted streams
     */
    class LogStream {

    public:
        /**
         * @brief Constructor
         * 
         * @param[in] logLevel The log level of the message
         * @param[in] location Location of the context that
         * shall be logged. Do not pass and use default.
         */
        LogStream(
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
         * @brief Returns a context for streaming
         * 
         * @param[in] location Location of the context that
         * shall be logged. Do not pass and use default.
         */
        static std::source_location context(
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

    private:
        ///< source location
        std::source_location location;

        ///< log level
        LogLevel logLevel;

    };

}

#endif