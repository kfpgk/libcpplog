#ifndef LIBCPPLOG_LOGGER_DECORATOR_CONTEXT_CONTEXT_HPP
#define LIBCPPLOG_LOGGER_DECORATOR_CONTEXT_CONTEXT_HPP

#include <libcpplog/logger/decorator/Decorator.hpp>
#include <libcpplog/logger/decorator/Message.hpp>

#include <memory>
#include <source_location>
#include <string>

namespace cpplog::logger::decorator::context {

	/**
	 * @brief Decorator for log messages that adds a context
	 *
	 * @details
	 * Patterns:
	 *  - Decorator
	 */
    class Context : public Decorator {

    public:
		/**
		 * @brief Constructor
		 *
		 * @param[in] message The message to be decorated
		 * @param[in] location The location of the message
		 */
        Context(std::unique_ptr<Message> message, 
            const std::source_location location) noexcept;

        /**
         * @brief Get the decorated message as a string
         *
         * @return The decorated message
         */
        std::string getString() const override;

    protected:
        ///> The location of the origin of the log message
        std::source_location location;

    private:
		/**
		 * @brief Pure virtual method to retrieve the function name
         * 
         * Override this method to specify the format (e.g. short or
		 * long) of the function name.
		 */
        virtual std::string getFunctionName() const = 0;

        /**
		 * @brief Builds a string from the context
         * 
		 * This method makes use of the overriden `getFunctionName()`
         * method.
         */
        std::string buildString() const;

    };

}

#endif