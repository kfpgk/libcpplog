#ifndef LIBCPPLOG_LOGGER_DECORATOR_TIME_STAMP_HPP
#define LIBCPPLOG_LOGGER_DECORATOR_TIME_STAMP_HPP

#include <libcpplog/logger/decorator/Decorator.hpp>
#include <libcpplog/logger/decorator/Message.hpp>

#include <memory>
#include <string>

namespace cpplog::logger::decorator {
    
	/**
	 * @brief Decorator for log messages that adds a timestamp
	 *
	 * @details
	 * Patterns:
     *  - Decorator
     */
    class TimeStamp : public Decorator {

    public:
		/**
		 * @brief Constructor
		 *
		 * @param[in] message The message to be decorated
		 */
        explicit TimeStamp(std::unique_ptr<Message> message) noexcept;

		/**
		 * @brief Get the decorated message as a string
		 *
		 * @return The decorated message
		 */
        std::string getString() const override;

    private:
		/**
		 * @brief Builds string from current time
		 */
        std::string buildString() const;

    };

}

#endif