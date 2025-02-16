#ifndef LIBCPPLOG_LOGGER_LOG_HPP
#define LIBCPPLOG_LOGGER_LOG_HPP

#include <libcpplog/logger/Logger.hpp>
#include <libcpplog/logger/LogFormat.hpp>
#include <libcpplog/logger/LogLevel.hpp>

#include <ostream>
#include <source_location>
#include <string>
#include <string_view>

namespace cpplog::logger {

    inline Logger logger;

    /**
     * @brief Configure output stream
     * 
     * @param[in] outStream The stream onto which all
     * subsequent logs get written to.
     * 
     */
    void setOutput(std::ostream& outStream);

    /**
     * @brief Configure log format
     *
     * @param[in] format The format of the log message
     * in a ordered sequence of LogComponent enums. Last
     * component will be at the beginning of the line.
     */
    void setFormat(const LogFormat& format);

    /**
     * @brief Logs \p message to configured output stream.
     * 
     * @param[in] message The message to be logged
     * @param[in] location Gets filled automatically via
     * default values to represent the caller's context. 
     */
    void log(
        const std::string_view message,
        const std::source_location location = std::source_location::current());

    /**
     * @brief Logs \p message to configured output stream
     * using the configured log format.
     *
     * @param[in] logLevel The log level of the message
     * @param[in] message The message to be logged
     * @param[in] location Location of the context that
     * shall be logged.
     */
    void log(
        LogLevel logLevel,
        const std::string_view message,
        const std::source_location location = std::source_location::current());

    /**
     * @brief Logs \p message to configured output stream,
     * but only once.
     * 
     * If the same calling code line is executed again, the 
     * message will not be logged again. 
     * 
     * @param[in] message The message to be logged
     * @param[in] location Gets filled automatically via
     * default values to represent the caller's context. 
     */
    void logOnce(
        const std::string_view message,
        const std::source_location location = std::source_location::current());

    /**
     * @brief Logs \p message to configured output stream,
     * but only once.
     *
     * If the same call to `logonce` is executed again, the
     * message will not be logged again.
     *
     * @param[in] logLevel The log level of the message
     * @param[in] message The message to be logged
     * @param[in] location Gets filled automatically via
     * default values to represent the caller's context.
     */
    void logOnce(
        LogLevel logLevel,
        const std::string_view message,
        const std::source_location location = std::source_location::current());

}

#endif