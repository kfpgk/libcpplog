#ifndef LIBCPPLOG_LOGGER_LOG_COMPONENT_HPP
#define LIBCPPLOG_LOGGER_LOG_COMPONENT_HPP

namespace cpplog::logger {

    /**
     * @brief Log component
     * 
     * Type to define what information
     * shall be part of the log message.
     * 
     */
    enum class LogComponent {
        LogLevel, ///< Logging level 
        Context, ///< Context including file, short function name and line
        ContextLong, ///< Context including file, long function name and line.
        TimeStamp ///< Time stamp 
    };

}

#endif