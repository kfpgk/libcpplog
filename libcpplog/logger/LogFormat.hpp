#ifndef LIBCPPLOG_LOGGER_LOG_FORMAT_HPP
#define LIBCPPLOG_LOGGER_LOG_FORMAT_HPP

#include <libcpplog/logger/LogComponent.hpp>

#include <vector>

namespace cpplog::logger {

    /**
     * @brief Log format
     *
     * Type to define what components
     * shall be part of the log message.
     * It is a vector of LogComponent enums.
     * First element will occur on the left.
     */
    using LogFormat = std::vector<LogComponent>;

    namespace log_format {

        /**
		 * @brief Reasonable default value for log format
         *
         * Default value for log format, including log level
         * time stamp, and context information.
         */
        const LogFormat defaultValue{
            LogComponent::LogLevel,
            LogComponent::TimeStamp,
            LogComponent::Context
        };

    }

}

#endif