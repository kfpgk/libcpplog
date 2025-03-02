#include <libcpplog/logger/LogStream.hpp>

#include <source_location>

namespace cpplog::logger {

    LogStream::LogStream(LogLevel logLevel, const std::source_location location) noexcept :
        logLevelAttribute{ logLevel },
        location{ location } {

    }

    std::source_location LogStream::getLocation() const noexcept {
        return location;
    }

    LogLevel LogStream::getLogLevel() const noexcept {
        return logLevelAttribute;
    }

    LogLevel LogStream::logLevel(LogLevel logLevel) noexcept {
        return logLevel;
    }

    std::source_location LogStream::context(
        const std::source_location& location) noexcept {

        return location;
    }

    LogStream::TimeStamp LogStream::timeStamp() noexcept {
        return LogStream::TimeStamp();
    }

}