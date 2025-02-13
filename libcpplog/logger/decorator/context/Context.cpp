#include <libcpplog/logger/decorator/context/Context.hpp>
#include <libcpplog/logger/decorator/Message.hpp>

#include <filesystem>
#include <format>
#include <memory>
#include <source_location>
#include <string>

namespace cpplog::logger::decorator::context {

    Context::Context(
        std::unique_ptr<Message> message, const std::source_location location) noexcept :
            Decorator{ std::move(message) },
            location{ location } {

    }

    std::string Context::getString() const {
        return buildString() + getSeparator() + message->getString();
    }

    /**
     * @brief Builds a string from the context
     *
     * credits: Marius Bancila
     *
     */
    std::string Context::buildString() const {
        return std::format("{}:{}({}:{})",
            std::filesystem::path(location.file_name()).filename().string(),
            getFunctionName(),
            location.line(),
            location.column());
    }

}