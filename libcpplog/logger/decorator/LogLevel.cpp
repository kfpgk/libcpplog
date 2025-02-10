#include <libcpplog/logger/decorator/LogLevel.hpp>
#include <libcpplog/logger/decorator/Message.hpp>
#include <libcpplog/logger/LogLevel.hpp>

#include <chrono>
#include <format>
#include <memory>
#include <string>

namespace cpplog::logger::decorator {
    
    LogLevel::LogLevel(std::unique_ptr<Message> message, logger::LogLevel logLevel) noexcept :
        Decorator{ std::move(message) },
        logLevel{ logLevel } {

    }

    std::string LogLevel::getString() const {
        return buildString() + getSeparator() + message->getString();
    }

    /**
     * @brief Builds string from log level
     *
     * @details
     * credits: Marius Bancila
     */
    std::string LogLevel::buildString() const {
        return std::format("[{}]",
            static_cast<char>(logLevel));
    }

}