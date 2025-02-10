#include <libcpplog/logger/decorator/TimeStamp.hpp>
#include <libcpplog/logger/decorator/Message.hpp>

#include <chrono>
#include <format>
#include <memory>
#include <string>

namespace cpplog::logger::decorator {
    
    TimeStamp::TimeStamp(std::unique_ptr<Message> message) noexcept :
        Decorator{ std::move(message) } {

    }

    std::string TimeStamp::getString() const {
        return buildString() + getSeparator() + message->getString();
    }

    /**
     * @brief Builds string from current time
     * 
     * @details
     * credits: Marius Bancila
     */
    std::string TimeStamp::buildString() const {
        return std::format("{:%F %T %Z}", 
            std::chrono::zoned_time{ 
                std::chrono::current_zone(),
                std::chrono::system_clock::now()});
    }

}