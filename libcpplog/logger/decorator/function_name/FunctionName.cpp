#include <libcpplog/logger/decorator/function_name/FunctionName.hpp>
#include <libcpplog/logger/decorator/Message.hpp>

#include <memory>
#include <string>

namespace cpplog::logger::decorator::function_name {

    FunctionName::FunctionName(std::unique_ptr<Message> message, bool useSeparator) noexcept :
        Decorator{ std::move(message), useSeparator } {

    }

    std::string FunctionName::getString() const {
        return getFunctionName() + getSeparatorInternal() + message->getString();
    }

}