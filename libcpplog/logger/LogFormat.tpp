#include <libcpplog/logger/LogFormat.hpp>
#include <libcpplog/logger/LogComponent.hpp>

namespace cpplog::logger {

    LogFormat::LogFormat(std::convertible_to<LogComponent> auto ... components) noexcept :
        components { components... } {

    }

}