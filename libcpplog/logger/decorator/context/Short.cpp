#include <libcpplog/logger/decorator/context/Short.hpp>
#include <libcpplog/logger/decorator/Message.hpp>
#include <libcpplog/debug/Debug.hpp>

#include <algorithm>
#include <array>
#include <cstddef>
#include <memory>
#include <source_location>
#include <string>
#include <string_view>

namespace cpplog::logger::decorator::context {

    Short::Short(
        std::unique_ptr<Message> message, const std::source_location location) noexcept  :
            Context{ std::move(message), location } {

    }

    std::string Short::getFunctionName() const {
        std::string functionName{ location.function_name() };
		return extractLastPart(removeParameters(removeSpecifiersWithParentheses(functionName)));
    }

    std::string& Short::removeSpecifiersWithParentheses(std::string& functionName) const {
		std::array<std::string_view, 4> specifiers{ 
            " noexcept(true)", 
            " noexcept(false)" 
        };
		for (auto specifier : specifiers) {
			std::size_t pos = functionName.find(specifier);
			if (pos != std::string::npos) {
				functionName.erase(pos, specifier.size());
			}
		}
        return functionName;
	}

    std::string& Short::removeParameters(std::string& functionName) const {
        std::size_t pos = functionName.find("(");
        if (pos != std::string::npos) {
            functionName.erase(pos);
        }
        return functionName;
    }

    std::string& Short::extractLastPart(std::string& functionName) const {
        std::size_t posColon = functionName.rfind(":");
        std::size_t posSpace = functionName.rfind(" ");
        posColon = (posColon == std::string::npos) ? 0 : posColon;
        posSpace = (posSpace == std::string::npos) ? 0 : posSpace;
        functionName = functionName.substr(std::max(posColon, posSpace) + 1);
		return functionName;
    }

}