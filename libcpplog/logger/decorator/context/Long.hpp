#ifndef LIBCPPLOG_LOGGER_DECORATOR_CONTEXT_LONG_HPP
#define LIBCPPLOG_LOGGER_DECORATOR_CONTEXT_LONG_HPP

#include <libcpplog/logger/decorator/context/Context.hpp>
#include <libcpplog/logger/decorator/Message.hpp>

#include <memory>
#include <source_location>
#include <string>

namespace cpplog::logger::decorator::context {

	/**
	 * @brief Decorator for log messages that adds a long context
	 *
	 * @details
	 * Patterns:
	 *  - Decorator
	 */
    class Long : public Context {

    public:
		/**
		 * @brief Constructor
		 *
		 * @param[in] message The message to be decorated
		 * @param[in] location The location of the message
		 */
        Long(std::unique_ptr<Message> message,
            const std::source_location location) noexcept;

    private:
		/**
		 * @brief Get the long function name
		 */
        std::string getFunctionName() const override;

    };

}

#endif