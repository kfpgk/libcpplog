#ifndef LIBCPPLOG_LOGGER_LOG_LEVEL_HPP
#define LIBCPPLOG_LOGGER_LOG_LEVEL_HPP

namespace cpplog::logger {

    /**
     * @brief Log level type
     * 
     * credits: Marius Bancila
     */
    enum class LogLevel : char
    {
        Error = 'E',
        Info = 'I',
        Result = 'R',
        Warning = 'W'
        
    };

    namespace log_level {

        /**
         * @brief Reasonable default value for log format
         *
         * Default value for log format, including log level
         * time stamp, and context information.
         */
        const LogLevel defaultValue{ LogLevel::Info };

    }

}

#endif