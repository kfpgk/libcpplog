#ifndef LIBCPPLOG_LOGGER_DECORATOR_FUNCTION_NAME_FUNCTION_NAME_HPP
#define LIBCPPLOG_LOGGER_DECORATOR_FUNCTION_NAME_FUNCTION_NAME_HPP

#include <libcpplog/logger/decorator/Decorator.hpp>
#include <libcpplog/logger/decorator/Message.hpp>

#include <memory>
#include <string>

namespace cpplog::logger::decorator::function_name {

	/**
	 * @brief Decorator for log messages that adds the current
     * function name without a separator
	 *
	 * @details
	 * Patterns:
	 *  - Decorator
     *  - Template
	 */
    class FunctionName : public Decorator {

    public:
		/**
		 * @brief Constructor
		 *
		 * @param[in] message The message to be decorated
		 * @param[in] useSeparator Flag indicating whether separator shall be used
		 */
        FunctionName(std::unique_ptr<Message> message, bool useSeparator) noexcept;

        /**
         * @brief Get the decorated message as a string
         *
         * @return The decorated message
         */
        std::string getString() const override;

    private:
		/**
		 * @brief Pure virtual method to retrieve the function name
         * 
         * Override this method to specify the format (e.g. short or
		 * long) of the function name.
		 */
        virtual std::string getFunctionName() const = 0;

    };

}

#endif