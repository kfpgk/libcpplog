#include <libcpplog/logger/LogComponentOps.hpp>
#include <libcpplog/logger/LogComponent.hpp>

namespace cpplog::logger {

    LogComponent streamComponentToLogComponent(LogStreamComponent streamComponent) {
        switch (streamComponent) {
        case LogStreamComponent::TimeStamp:
            return LogComponent::TimeStamp;
            break;
        default:
            return LogComponent::None;
        }
    }

}