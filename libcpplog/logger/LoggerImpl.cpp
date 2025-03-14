#include <libcpplog/logger/LoggerImpl.hpp>
#include <libcpplog/logger/LogComponent.hpp>
#include <libcpplog/logger/LogFormat.hpp>
#include <libcpplog/logger/decorator/Decorator.hpp>
#include <libcpplog/logger/decorator/LogLevel.hpp>
#include <libcpplog/logger/decorator/Message.hpp>
#include <libcpplog/logger/decorator/TimeStamp.hpp>
#include <libcpplog/logger/decorator/context/Short.hpp>
#include <libcpplog/logger/decorator/context/Long.hpp>
#include <libcpplog/logger/decorator/function_name/Short.hpp>
#include <libcpplog/logger/decorator/function_name/Long.hpp>
#include <libcpplog/logger/decorator/function_name/ShortStore.hpp>
#include <libcpplog/debug/Debug.hpp>

#include <memory>
#include <mutex>
#include <iostream>
#include <ostream>
#include <ranges>
#include <source_location>
#include <string>
#include <string_view>
#include <syncstream>

namespace cpplog::logger {

    Logger::Impl::Impl(std::ostream& outStream, LogFormat format) noexcept :
        outStream{ outStream },
        format{ format } {

    }

    void Logger::Impl::setOutput(std::ostream& outStream) noexcept {
        this->outStream = outStream;
    }

    void Logger::Impl::setFormat(const LogFormat& format) noexcept {
        this->format = format;
    }

    std::ostream& Logger::Impl::getOutput() const noexcept {
        return outStream;
    }

    LogFormat Logger::Impl::getFormat() const noexcept {
        return format;
    }

    void Logger::Impl::log(
        const std::string_view message,
        const std::source_location location) const {

        log(defaultLogLevel, message, location);
    }

    void Logger::Impl::log(
        LogLevel logLevel,
        const std::string_view message,
        const std::source_location location) const {

        std::osyncstream(outStream.get()) << constructLogMessage(logLevel, message, location) 
                                          << std::endl;
    }

    void Logger::Impl::logOnce(
        const std::string_view message,
        const std::source_location location) {

        logOnce(defaultLogLevel, message, location);
    }

    void Logger::Impl::logOnce(
        LogLevel logLevel,
        const std::string_view message,
        const std::source_location location) {

        std::string key = buildMessageKey(message, location);
        {
            std::scoped_lock lock(mutexForLoggedMsg);
            if (!loggedOnceMessages.contains(key)) {
                log(logLevel, message, location);
                loggedOnceMessages.insert(key);
            }
        }
    }

    void Logger::Impl::log(
        const std::string_view message,
        const LogRequest::FunctionName& functionName) const {

        log(defaultLogLevel, message, functionName);
    }

    void Logger::Impl::log(
		LogLevel logLevel,
        const std::string_view message,
        const LogRequest::FunctionName& functionName) const {

        decorator::function_name::ShortStore shortFunctionName(functionName.getLocation());
        std::string prefix = message.empty() ? "" : std::string(message) + " ";
		std::string suffix = functionName.userWantsSeparator() ? decorator::Decorator::getSeparator() : "";
		log(prefix + shortFunctionName.extract() + "()" + suffix, functionName.getLocation());
    }

    void Logger::Impl::log(
        const std::exception& exception,
        const std::source_location location) const {

		log(LogLevel::Error, exception, location);
    }

    void Logger::Impl::log(
        LogLevel logLevel,
        const std::exception& exception,
        const std::source_location location) const {

        log(logLevel, "", exception, location);
    }

    void Logger::Impl::log(
        LogLevel logLevel,
        const std::string_view indent,
        const std::exception& exception,
        const std::source_location location) const {

        log(logLevel, std::string(indent) + exception.what(), location);
        try {
            std::rethrow_if_nested(exception);
        }
        catch (const std::exception& e) {
            log(logLevel, std::string(indent) + "  ", e, location);
        }
    }

    Logger::Impl& Logger::Impl::operator<<(
        decltype(std::endl<char, std::char_traits<char>>) endl) {

        std::osyncstream(outStream.get()) << std::endl;
        return *this;
    }

    Logger::Impl& Logger::Impl::operator<<(const LogRequest& stream) {
        std::osyncstream(outStream.get()) <<
            constructLogMessage(stream.getLogLevel(), "", stream.getLocation(), format);
        return *this;
    }

    Logger::Impl& Logger::Impl::operator<<(LogLevel level) {
		LogFormat format{ LogComponent::LogLevel };
		// source_location does not matter here, as it is not used with this format.
        std::osyncstream(outStream.get()) <<
            constructLogMessage(level, "", std::source_location::current(), format);
		return *this;
	}

    Logger::Impl& Logger::Impl::operator<<(const LogRequest::Context& context) {
        LogFormat format{ LogComponent::Context };
        std::osyncstream(outStream.get()) <<
            constructLogMessage(
                defaultLogLevel,
                "",
                context.getLocation(),
                format,
                !context.userDisabledSeparator());
        return *this;
    }

    Logger::Impl& Logger::Impl::operator<<(const LogRequest::TimeStamp& timeStamp) {
        LogFormat format{ LogComponent::TimeStamp };
        // source_location and log level do not matter here, as they are not used with this format.
        std::osyncstream(outStream.get()) <<
            constructLogMessage(
                defaultLogLevel,
                "",
                std::source_location::current(),
                format,
                !timeStamp.userDisabledSeparator());
        return *this;
    }

    Logger::Impl& Logger::Impl::operator<<(const LogRequest::FunctionName& functionName) {
        LogFormat format{ LogComponent::Function };
        std::osyncstream(outStream.get()) <<
            constructLogMessage(
                defaultLogLevel,
                "",
                functionName.getLocation(),
                format,
                !functionName.userDisabledSeparator());
        return *this;
    }

    std::string Logger::Impl::constructLogMessage(
        LogLevel logLevel,
        const std::string_view message,
        const std::source_location& location) const {

		return constructLogMessage(logLevel, message, location, format);
    }

    std::string Logger::Impl::constructLogMessage(
        LogLevel logLevel,
        const std::string_view message,
        const std::source_location& location,
        LogFormat format,
        bool useSeparator) const {

        std::unique_ptr<decorator::Message> msg = std::make_unique<decorator::Message>(message);

        for (auto component : std::ranges::reverse_view{ format } ) {
            switch (component) {
            case LogComponent::Context:
                msg = std::move(
                    std::make_unique<decorator::context::Short>(
                        std::move(msg), location, useSeparator));
                break;
            case LogComponent::ContextLong:
                msg = std::move(
                    std::make_unique<decorator::context::Long>(
                        std::move(msg), location, useSeparator));
                break;
            case LogComponent::Function:
                msg = std::move(
                    std::make_unique<decorator::function_name::Short>(
                        std::move(msg), location, useSeparator));
                break;
            case LogComponent::FunctionLong:
                msg = std::move(
                    std::make_unique<decorator::function_name::Long>(
                        std::move(msg), location, useSeparator));
                break;
            case LogComponent::LogLevel:
                msg = std::move(std::make_unique<decorator::LogLevel>(
                    std::move(msg), logLevel, useSeparator));
                break;
            case LogComponent::TimeStamp:
                msg = std::move(std::make_unique<decorator::TimeStamp>(
                    std::move(msg), useSeparator));
                break;
            }
        }
        return msg->getString();
    }

    std::string Logger::Impl::buildMessageKey(
        const std::string_view message, const std::source_location& location) const {

        return
            std::string(location.file_name()) + ":" + 
            std::to_string(location.line()) + ":" +
            std::to_string(location.column()) + ":" + 
            std::string(message);
    }

}