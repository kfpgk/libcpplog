#include <libcpplog/logger/decorator/function_name/ShortStore.hpp>

#include <algorithm>
#include <array>
#include <cstddef>
#include <source_location>
#include <string>
#include <string_view>

namespace cpplog::logger::decorator::function_name {

    ShortStore::ShortStore(const std::source_location location) noexcept :
        location{ location } {

    }

    std::string ShortStore::extract() const {
        std::string functionName{ location.function_name() };
		return extractLastPart(removeParameters(removeSpecifiersWithParentheses(functionName)));
    }

    std::string& ShortStore::removeSpecifiersWithParentheses(std::string& functionName) const {
		std::array<const std::string_view, 2> specifiers{ 
            " noexcept(true)", 
            " noexcept(false)" 
        };
		for (auto&& specifier : specifiers) {
			std::size_t pos = functionName.find(specifier);
			if (pos != std::string::npos) {
				functionName.erase(pos, specifier.size());
			}
		}
        return functionName;
	}

    std::string& ShortStore::removeParameters(std::string& functionName) const {
        std::size_t pos = functionName.find("(");
        if (pos != std::string::npos) {
            functionName.erase(pos);
        }
        return functionName;
    }

    std::string& ShortStore::extractLastPart(std::string& functionName) const {
        std::size_t posColon = functionName.rfind(":");
        std::size_t posSpace = functionName.rfind(" ");
        posColon = (posColon == std::string::npos) ? 0 : posColon;
        posSpace = (posSpace == std::string::npos) ? 0 : posSpace;
        functionName = functionName.substr(std::max(posColon, posSpace) + 1);
		return functionName;
    }

}