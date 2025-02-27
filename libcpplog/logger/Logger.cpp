#include <libcpplog/logger/Logger.hpp>
#include <libcpplog/logger/LoggerImpl.hpp>
#include <libcpplog/logger/LogFormat.hpp>

#include <iostream>
#include <memory>
#include <ostream>
#include <source_location>
#include <string_view>

namespace cpplog::logger {

    Logger::Logger(std::ostream& outStream, LogFormat format) noexcept :
        pImpl{ std::make_unique<Logger::Impl>(outStream, format) } {

    }

    Logger::Logger(const Logger& rhs) noexcept {
        pImpl = std::make_unique<Logger::Impl>(
            rhs.pImpl->getOutput(), rhs.pImpl->getFormat());
    }

    Logger::Logger(Logger&& rhs) noexcept {
        pImpl = std::move(rhs.pImpl);
    }
    
    Logger& Logger::operator=(Logger rhs) noexcept {
        using std::swap;
        swap(*this, rhs);
        return *this;
    }

    void swap(Logger& lhs, Logger& rhs) noexcept {
        using std::swap;
        swap(lhs.pImpl, rhs.pImpl);
    }

    Logger::~Logger() = default;

    void Logger::setOutput(std::ostream& outStream) noexcept {
        pImpl->setOutput(outStream);
    }

    void Logger::setFormat(const LogFormat& format) noexcept {
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

    Logger& Logger::operator<<(const std::string_view string) {
        *pImpl << string;
        return *this;
    }

    Logger& Logger::operator<<(float value) {
        *pImpl << value;
        return *this;
    }

    Logger& Logger::operator<<(decltype(std::endl<char, std::char_traits<char>>) endl) {
        *pImpl << std::endl;
        return *this;
    }

    Logger& Logger::operator<<(const LogStream& stream) {
        *pImpl << stream;
        return *this;
    }

    Logger& Logger::operator<<(LogLevel level) {
        *pImpl << level;
        return *this;
    }

    Logger& Logger::operator<<(const LogStream::TimeStamp& timeStamp) {
        *pImpl << timeStamp;
        return *this;
    }

    Logger& Logger::operator<<(std::source_location location) {
        *pImpl << location;
        return *this;
    }

}