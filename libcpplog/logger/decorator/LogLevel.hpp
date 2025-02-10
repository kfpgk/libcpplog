#ifndef LIBCPPLOG_LOGGER_DECORATOR_LOG_LEVEL_HPP
#define LIBCPPLOG_LOGGER_DECORATOR_LOG_LEVEL_HPP

#include <libcpplog/logger/decorator/Decorator.hpp>
#include <libcpplog/logger/decorator/Message.hpp>
#include <libcpplog/logger/LogLevel.hpp>

#include <memory>
#include <string>

namespace cpplog::logger::decorator {
    
    /**
	 * @brief Decorator for log messages that adds a log level
     * 
     * @details
     * Patterns:
     *  - Decorator
     */
    class LogLevel : public Decorator {

    public:
        /**
         * @brief Constructor
         *
         * @param[in] message The message to be decorated
		 * @param[in] logLevel The log level to be added
         */
        LogLevel(std::unique_ptr<Message> message, logger::LogLevel logLevel) noexcept;

        /**
         * @brief Get the decorated message as a string
         *
         * @return The decorated message
         */
        std::string getString() const override;

    private:
		logger::LogLevel logLevel; ///< The log level to be added

        /**
         * @brief Builds string from log level
         */
        std::string buildString() const;

    };

}

#endif