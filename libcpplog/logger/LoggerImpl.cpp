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

namespace cpplog::logger {

    Logger::Impl::Impl(std::ostream& outStream, LogFormat format) :
        outStream{ outStream },
        format{ format } {

    }

    void Logger::Impl::setOutput(std::ostream& outStream) {
        this->outStream = outStream;
    }

    void Logger::Impl::setFormat(LogFormat format) {
        this->format = format;
    }

    void Logger::Impl::log(
        const std::string_view message,
        const std::source_location location) const {

        log(LogLevel::Info, message, location);
    }

    void Logger::Impl::log(
        LogLevel logLevel,
        const std::string_view message,
        const std::source_location location) const {

        std::scoped_lock lock(outMutex);
        outStream.get() << constructLogMessage(logLevel, message, location) << std::endl;
    }

    void Logger::Impl::logOnce(
        const std::string_view message,
        const std::source_location location) {

        logOnce(LogLevel::Info, message, location);   
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

    Logger::Impl& operator<<(
        Logger::Impl& impl,
        decltype(std::endl<char, std::char_traits<char>>) endl) {

        std::scoped_lock lock(impl.outMutex);
        impl.outStream.get() << std::endl;
        return impl;
    }

    Logger::Impl& operator<<(Logger::Impl& impl, LogLevel level) {
		LogFormat format{ LogComponent::LogLevel };
        std::scoped_lock lock(impl.outMutex);
		// source_location does not matter here, as it is not used with this format.
        impl.outStream.get() << impl.constructLogMessage(level, "", std::source_location::current(), format);
		return impl;
	}

    Logger::Impl& operator<<(Logger::Impl& impl, LogComponent component) {
		LogFormat format{ component };
		impl.constructLogMessage(LogLevel::Info, "", std::source_location::current(), format);
        return impl;
    }

    std::string Logger::Impl::constructLogMessage(
        LogLevel logLevel,
        const std::string_view message,
        const std::source_location location) const {

		return constructLogMessage(logLevel, message, location, format);
    }

    std::string Logger::Impl::constructLogMessage(
        LogLevel logLevel,
        const std::string_view message,
        const std::source_location location,
        LogFormat format) const {

        DEBUG_ENTER();
        std::unique_ptr<decorator::Message> msg = std::make_unique<decorator::Message>(message);

        for (auto component : std::ranges::reverse_view{ format } ) {
            std::unique_ptr<decorator::Message> tmpMsg;
            switch (component) {
            case LogComponent::Context:
                DEBUG("Decorate with context");
                tmpMsg = std::make_unique<decorator::context::Short>(
                    std::move(msg), location);
                msg = std::move(tmpMsg);
                break;
            case LogComponent::ContextLong:
                DEBUG("Decorate with long context");
                tmpMsg = std::make_unique<decorator::context::Long>(
                    std::move(msg), location);
                msg = std::move(tmpMsg);
                break;
            case LogComponent::LogLevel:
                DEBUG("Decorate with log level");
                tmpMsg = std::make_unique<decorator::LogLevel>(std::move(msg), logLevel);
                msg = std::move(tmpMsg);
                break;
            case LogComponent::TimeStamp:
                DEBUG("Decorate with time stamp");
                tmpMsg = std::make_unique<decorator::TimeStamp>(std::move(msg));
                msg = std::move(tmpMsg);
                break;
            }
        }
        DEBUG_EXIT();
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