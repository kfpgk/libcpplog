#include <libcpplog/logger/LogFormat.hpp>

#include <vector>

namespace cpplog::logger {

    LogFormat::LogFormat(const std::vector<LogComponent>& components) noexcept :
        components { components } {

    }

    std::vector<LogComponent>::iterator LogFormat::begin() noexcept {
        return components.begin();
    }

    std::vector<LogComponent>::iterator LogFormat::end() noexcept {
        return components.end();
    }

    LogFormat LogFormat::defaultValue() noexcept {
        return { {
            LogComponent::LogLevel,
            LogComponent::TimeStamp,
            LogComponent::Context } };
    }

}