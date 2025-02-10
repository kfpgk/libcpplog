#include <libcpplog/logger/decorator/context/Long.hpp>
#include <libcpplog/logger/decorator/Message.hpp>

#include <memory>
#include <source_location>
#include <string>

namespace cpplog::logger::decorator::context {

    Long::Long(std::unique_ptr<Message> message, const std::source_location location) :
        Context{ std::move(message), location } {

    }

    std::string Long::getFunctionName() const {
        return location.function_name();
    }

}