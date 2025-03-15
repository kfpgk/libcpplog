#include <libcpplog/logger/Log.hpp>
#include <libcpplog/logger/LogLevel.hpp>

#include <ostream>
#include <source_location>
#include <string_view>

namespace cpplog::logger {

    void setOutput(std::ostream& outStream) {
        logger.setOutput(outStream);
    }

    void setFormat(const LogFormat& format) {
        logger.setFormat(format);
    }

    void log(
        const std::string_view message,
        const std::source_location location) {

        logger.log(message, location);
    }

    void log(
		LogLevel logLevel,
        const std::string_view message,
        const std::source_location location) {

        logger.log(logLevel, message, location);
    }

    void logOnce(
        const std::string_view message,
        const std::source_location location) {

        logger.logOnce(message, location);
    }

    void logOnce(
        LogLevel logLevel,
        const std::string_view message,
        const std::source_location location) {

        logger.logOnce(logLevel, message, location);
    }

    void log(
        const std::string_view message,
        const LogRequest::FunctionName& functionName) {

		logger.log(message, functionName);
    }

    void log(
        LogLevel logLevel,
        const std::string_view message,
        const LogRequest::FunctionName& functionName) {

		logger.log(logLevel, message, functionName);    
    }

    void log(
        const std::exception& exception,
        const std::source_location location) {

		logger.log(exception, location);
    }

    void log(
        LogLevel logLevel,
        const std::exception& exception,
        const std::source_location location) {

		logger.log(logLevel, exception, location);
    }

}