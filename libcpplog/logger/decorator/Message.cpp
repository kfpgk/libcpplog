#include <libcpplog/logger/decorator/Message.hpp>

#include <string>
#include <string_view>

namespace cpplog::logger::decorator {
    
    Message::Message(const std::string_view message) noexcept :
        content{ message } {

    }

    std::string Message::getString() const {
        return content;
    }

}