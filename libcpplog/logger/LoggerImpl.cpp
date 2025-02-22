#include <libcpplog/logger/LoggerImpl.hpp>
#include <libcpplog/logger/LogComponent.hpp>
#include <libcpplog/logger/LogFormat.hpp>
#include <libcpplog/logger/decorator/LogLevel.hpp>
#include <libcpplog/logger/decorator/Message.hpp>
#include <libcpplog/logger/decorator/TimeStamp.hpp>
#include <libcpplog/logger/decorator/context/Short.hpp>
#include <libcpplog/logger/decorator/context/Long.hpp>
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

    Logger::Impl& Logger::Impl::operator<<(
        decltype(std::endl<char, std::char_traits<char>>) endl) {

        std::osyncstream(outStream.get()) << std::endl;
        return *this;
    }

    Logger::Impl& Logger::Impl::operator<<(const LogStream& stream) {
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

    Logger::Impl& Logger::Impl::operator<<(const LogStream::TimeStamp& timeStamp) {
        LogFormat format{ LogComponent::TimeStamp };
        // source_location and log level do not matter here, as they are not used with this format.
        std::osyncstream(outStream.get()) <<
            constructLogMessage(defaultLogLevel, "", std::source_location::current(), format);
        return *this;
    }

    Logger::Impl& Logger::Impl::operator<<(const std::source_location& location) {
        LogFormat format{ LogComponent::Context };
        std::osyncstream(outStream.get()) << 
            constructLogMessage(defaultLogLevel, "", location, format);
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
        LogFormat format) const {

        std::unique_ptr<decorator::Message> msg = std::make_unique<decorator::Message>(message);

        for (auto component : std::ranges::reverse_view{ format } ) {
            std::unique_ptr<decorator::Message> tmpMsg;
            switch (component) {
            case LogComponent::Context:
                tmpMsg = std::make_unique<decorator::context::Short>(
                    std::move(msg), location);
                msg = std::move(tmpMsg);
                break;
            case LogComponent::ContextLong:
                tmpMsg = std::make_unique<decorator::context::Long>(
                    std::move(msg), location);
                msg = std::move(tmpMsg);
                break;
            case LogComponent::LogLevel:
                tmpMsg = std::make_unique<decorator::LogLevel>(std::move(msg), logLevel);
                msg = std::move(tmpMsg);
                break;
            case LogComponent::TimeStamp:
                tmpMsg = std::make_unique<decorator::TimeStamp>(std::move(msg));
                msg = std::move(tmpMsg);
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