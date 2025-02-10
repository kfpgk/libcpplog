#include <libcpplog/logger/Logger.hpp>
#include <libcpplog/logger/LoggerImpl.hpp>
#include <libcpplog/logger/LogFormat.hpp>

#include <iostream>
#include <ostream>
#include <source_location>
#include <string_view>

namespace cpplog::logger {

    Logger::Logger(std::ostream& outStream, LogFormat format) :
        pImpl{ std::make_unique<Logger::Impl>(outStream, format) } {

    }

    Logger::~Logger() = default;

    void Logger::setOutput(std::ostream& outStream) {
        pImpl->setOutput(outStream);
    }

    void Logger::setFormat(LogFormat format) {
        pImpl->setFormat(format);
    }

    void Logger::log(
        const std::string_view message,
        const std::source_location location) const {

        pImpl->log(message, location);
    }

    void Logger::log(
        LogLevel logLevel,
        const std::string_view message,
        const std::source_location location) const {

        pImpl->log(logLevel, message, location);
    }

    void Logger::logOnce(
        const std::string_view message,
        const std::source_location location) {

        pImpl->logOnce(message, location);   
    }

    void Logger::logOnce(
        LogLevel logLevel,
        const std::string_view message,
        const std::source_location location) {

        pImpl->logOnce(logLevel, message, location);
    }

    Logger& operator<<(Logger& logger, decltype(std::endl<char, std::char_traits<char>>) endl) {
        logger.pImpl << std::endl;
        return logger;
    }

}