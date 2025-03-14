#include <libcpplog/logger/decorator/function_name/Long.hpp>
#include <libcpplog/logger/decorator/function_name/LongStore.hpp>
#include <libcpplog/logger/decorator/Message.hpp>

#include <memory>
#include <source_location>
#include <string>

namespace cpplog::logger::decorator::function_name {

    Long::Long(
        std::unique_ptr<Message> message,
        const std::source_location location,
        bool useSeparator) noexcept :
            FunctionName{ std::move(message), useSeparator },
            functionNameStore{ location } {

    }

    std::string Long::getFunctionName() const {
        return functionNameStore.extract();
    }

}