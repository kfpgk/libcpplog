#ifndef LIBCPPLOG_LOGGER_DECORATOR_FUNCTION_NAME_LONG_STORE_HPP
#define LIBCPPLOG_LOGGER_DECORATOR_FUNCTION_NAME_LONG_STORE_HPP

#include <source_location>
#include <string>

namespace cpplog::logger::decorator::function_name {

	/**
	 * @brief Stores a long function name
	 */
    class LongStore {

    public:
		/**
		 * @brief Constructor
		 *
		 * @param[in] location The location containing the function
		 */
        LongStore(const std::source_location location) noexcept;

		/**
		 * @brief Get the long function name
		 */
        std::string extract() const;

    private:
		std::source_location location; ///< The location containing the function

    };

}

#endif