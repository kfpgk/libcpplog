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

    LogRequest::RequestObject::RequestObject(Separator sep) noexcept :
        sep{ sep } {
    }

    bool LogRequest::RequestObject::userWantsSeparator() const noexcept {
        return sep == Separator::use;
    }

    bool LogRequest::RequestObject::userDisabledSeparator() const noexcept {
        return sep == Separator::none;
    }

    LogLevel LogRequest::logLevel(LogLevel logLevel) noexcept {
        return logLevel;
    }

    LogRequest::Context LogRequest::context(
        Separator sep, const std::source_location& location) noexcept {

        return LogRequest::Context(sep, location);
    }

    LogRequest::Context::Context(Separator sep, const std::source_location& location) noexcept :
		RequestObject{ sep },
        location{ location } {
    }

    std::source_location LogRequest::Context::getLocation() const noexcept {
        return location;
    }

    LogRequest::TimeStamp LogRequest::timeStamp(Separator sep) noexcept {
        return LogRequest::TimeStamp(sep);
    }

    LogRequest::TimeStamp::TimeStamp(Separator sep) noexcept :
        RequestObject{ sep } {
    }

	LogRequest::FunctionName::FunctionName(
        Separator sep, const std::source_location& location) noexcept :
		    RequestObject{ sep },
            location{ location } {
    }

    std::source_location LogRequest::FunctionName::getLocation() const noexcept {
        return location;
    }

    LogRequest::FunctionName LogRequest::functionName(
		Separator sep, const std::source_location& location) noexcept {

        return LogRequest::FunctionName(sep, location);
    }

}