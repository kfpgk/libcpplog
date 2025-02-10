#ifndef LIBCPPLOG_LOGGER_LOG_LEVEL_HPP
#define LIBCPPLOG_LOGGER_LOG_LEVEL_HPP

namespace cpplog::logger {

    /**
     * @brief Log level type
     * 
     * credits: Marius Bancila
     * 
     */
    enum class LogLevel : char
    {
        Info = 'I',
        Warning = 'W',
        Error = 'E'
    };

}

#endif