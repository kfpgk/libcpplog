#ifndef LIBCPPLOG_LOGGER_DECORATOR_MESSAGE_HPP
#define LIBCPPLOG_LOGGER_DECORATOR_MESSAGE_HPP

#include <string>
#include <string_view>

namespace cpplog::logger::decorator {
    
    /**
     * @brief Base class for log messages
     * 
     * @details
     * Patterns:
	 *  - Decorator
     */
    class Message {

    public:
		/**
		 * @brief Constructor
		 *
		 * @param[in] message The message to be logged
		 */
        explicit Message(const std::string_view message) noexcept;

        /**
		 * @brief Destructor
         */
        virtual ~Message() = default;

        /**
         * @brief Get the content of the message as a string 
         */
        virtual std::string getString() const;

    private:
        std::string content; ///< The content of the message

    };

}

#endif