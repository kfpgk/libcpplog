#include <libcpplog/logger/LogRequest.hpp>

#include <source_location>

namespace cpplog::logger {

    LogRequest::LogRequest(LogLevel logLevel, const std::source_location location) noexcept :
        logLevelAttribute{ logLevel },
        location{ location } {

    }

    std::source_location LogRequest::getLocation() const noexcept {
        return location;
    }

    LogLevel LogRequest::getLogLevel() const noexcept {
        return logLevelAttribute;
    }

    LogLevel LogRequest::logLevel(LogLevel logLevel) noexcept {
        return logLevel;
    }

    LogRequest::Context LogRequest::context(
        const std::source_location& location) noexcept {

        return LogRequest::Context(location);
    }

    LogRequest::Context::Context(const std::source_location& location) noexcept
        : location{ location } {
    }

    std::source_location LogRequest::Context::getLocation() const noexcept {
        return location;
    }

    LogRequest::TimeStamp LogRequest::timeStamp() noexcept {
        return LogRequest::TimeStamp();
    }

	LogRequest::FunctionName::FunctionName(const std::source_location& location) noexcept
        : location{ location }{
    }

    std::source_location LogRequest::FunctionName::getLocation() const noexcept {
        return location;
    }

    LogRequest::FunctionName LogRequest::functionName(
        const std::source_location& location) noexcept {

        return LogRequest::FunctionName(location);
    }

}