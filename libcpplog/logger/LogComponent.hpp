#ifndef LIBCPPLOG_LOGGER_LOG_COMPONENT_HPP
#define LIBCPPLOG_LOGGER_LOG_COMPONENT_HPP

namespace cpplog::logger {

    /**
     * @brief Log component
     * 
     * Type to define what information
     * shall be part of the log message.
     */
    enum class LogComponent {
        None, ///< Nothing to log
        LogLevel, ///< Logging level 
        Context, ///< Context including file, short function name and line
        ContextLong, ///< Context including file, long function name and line.
        TimeStamp ///< Time stamp 
    };

    /**
     * @brief Log stream component
     *
     * A log component that can be streamed into
     * the logger. Not all log components make
     * sense, hence this is subset of the
     * `LogComponent` enum class.
     */
    enum class LogStreamComponent {
        TimeStamp ///< Time stamp 
    };

    inline LogComponent streamComponentToLogComponent(LogStreamComponent streamComponent) {
        switch (streamComponent) {
        case LogStreamComponent::TimeStamp:
            return LogComponent::TimeStamp;
            break;
        default:
            return LogComponent::None;
        }
    }

}

#endif