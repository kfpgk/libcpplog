#ifndef LIBCPPLOG_LOGGER_LOG_FORMAT_HPP
#define LIBCPPLOG_LOGGER_LOG_FORMAT_HPP

#include <libcpplog/logger/LogComponent.hpp>

#include <vector>

namespace cpplog::logger {

    /**
     * @brief Log format definition class
     *
     * Class to define what components shall be part of the
     * log message. It is constructed from a vector of 
     * LogComponent enums. The first element will occur on the 
     * left.
     */
    class LogFormat {

    public:
        /**
         * @brief Constructor
         * 
         * @param[in] components The components to be logged in the 
         * corresponding order.
         */
        LogFormat(std::convertible_to<LogComponent> auto ... components) noexcept;

        /**
         * @brief Constructor
         * 
         * @param[in] components A vector of components to be logged in the 
         * corresponding order.
         */
        LogFormat(const std::vector<LogComponent>& components) noexcept;

        /**
         * @brief Returns iterator to the beginning of the components vector
         */
        std::vector<LogComponent>::iterator begin() noexcept;

        /**
         * @brief Returns iterator to the end of the components vector
         */
        std::vector<LogComponent>::iterator end() noexcept;

        /**
         * @brief Returns a reasonable default value for log format
         */
        static LogFormat defaultValue() noexcept;

    private:
        ///< data container to hold the log components. Order is important.
        std::vector<LogComponent> components; 

    };

}

#include <libcpplog/logger/LogFormat.tpp>

#endif