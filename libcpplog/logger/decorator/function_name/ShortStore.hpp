#ifndef LIBCPPLOG_LOGGER_DECORATOR_FUNCTION_NAME_SHORT_STORE_HPP
#define LIBCPPLOG_LOGGER_DECORATOR_FUNCTION_NAME_SHORT_STORE_HPP

#include <source_location>
#include <string>

namespace cpplog::logger::decorator::function_name {

	/**
	 * @brief Stores a short function name
	 */
    class ShortStore {

    public:
		/**
		 * @brief Constructor
		 *
		 * @param[in] location The location containing the function
		 */
        ShortStore(const std::source_location location) noexcept;

		/**
		 * @brief Extracts the short function name
		 */
        std::string extract() const;

    private:
		std::source_location location; ///< The location containing the function

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