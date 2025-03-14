#include <libcpplog/logger/decorator/Decorator.hpp>
#include <libcpplog/logger/decorator/Message.hpp>

#include <memory>
#include <string>
#include <string_view>

namespace cpplog::logger::decorator {

    std::string Decorator::componentSeparator{ defaultSeparator };

    Decorator::Decorator(std::unique_ptr<Message> message, bool useSeparator) noexcept :
        Message{ message->getString() },
        message{ std::move(message) },
        useSeparator{ useSeparator } {

    }

    std::string Decorator::getString() const {
        return message->getString();
    }

	void Decorator::setSeparator(std::string_view separator) noexcept {
		componentSeparator = separator;
	}

    std::string Decorator::getSeparator() noexcept {
        return componentSeparator;
    }

    std::string Decorator::getSeparatorInternal() const noexcept {
        return useSeparator ? componentSeparator : "";
    }

}