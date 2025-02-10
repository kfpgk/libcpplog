#ifndef LIBCPPLOG_LOGGER_DECORATOR_CONTEXT_SHORT_HPP
#define LIBCPPLOG_LOGGER_DECORATOR_CONTEXT_SHORT_HPP

#include <libcpplog/logger/decorator/context/Context.hpp>
#include <libcpplog/logger/decorator/Message.hpp>

#include <memory>
#include <source_location>
#include <string>

namespace cpplog::logger::decorator::context {

    /**
     * @brief Decorator for log messages that adds a short context
     *
     * @details
     * Patterns:
     *  - Decorator
     */
    class Short : public Context {

    public:
        /**
         * @brief Constructor
         *
         * @param[in] message The message to be decorated
         * @param[in] location The location of the message
         */
        explicit Short(std::unique_ptr<Message> message,
            const std::source_location location);

    private:
        /**
         * @brief Get the short function name
         */
        std::string getFunctionName() const override;

        /**
		 * @brief Remove function specifiers that contain parentheses from function name
         * 
		 * @param[in,out] functionName The function name which is being modified in place.
         * 
		 * This method removes specifiers that include parentheses e.g. `noexcept(true)`.
         */
        std::string& removeSpecifiersWithParentheses(std::string& functionName) const;

        /**
         * @brief Remove function parameters from function name
         *
         * @param[in,out] functionName The function name which is being modified in place.
         *
         * This method removes function parameters including parentheses from the end
         * of the string.
         */
        std::string& removeParameters(std::string& functionName) const;

        /**
         * @brief Extract last part of function name after colon or space 
         *
         * @param[in,out] functionName The function name which is being modified in place.
         *
		 * This method extracts the last part of a function name and cuts off 
         * everything before the last colon or space.
         */
        std::string& extractLastPart(std::string& functionName) const;

    };

}

#endif