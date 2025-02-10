#ifndef LIBCPPLOG_LOGGER_DECORATOR_DECORATOR_HPP
#define LIBCPPLOG_LOGGER_DECORATOR_DECORATOR_HPP

#include <libcpplog/logger/decorator/Message.hpp>

#include <memory>
#include <string>
#include <string_view>

namespace cpplog::logger::decorator {

    /**
     * @brief Decorator class for log messages
     *
     * This class is used to decorate log messages with additional information.
     * Derive from this class to add functionalities such as context information,
     * timestamps, etc.
     * 
     * @details 
     * Patterns
     *  - Decorator
     */
    class Decorator : public Message {

    public:
        /**
         * @brief Constructor
         *
         * @param[in] message The message to be decorated
         */
        Decorator(std::unique_ptr<Message> message) noexcept;

        /**
         * @brief Destructor
         */
        virtual ~Decorator() = default;

        /**
         * @brief Get the decorated message as a string
         *
         * @return The decorated message
         */
        std::string getString() const override;

        /**
         * @brief Set the separator for components in the decorated message
         *
         * @param[in] separator The separator to be used
         */
        static void setSeparator(std::string_view separator) noexcept;

        /**
         * @brief Get the separator for components in the decorated message
         *
		 * @return The separator
         */
        static std::string getSeparator() noexcept;

    protected:
		std::unique_ptr<Message> message; ///< Owning pointer to the message that is being decorated
        
    private:
        ///< The default separator for components in the decorated message
        static constexpr std::string_view defaultSeparator{ " | " };
        static std::string componentSeparator; ///< The separator for components in the decorated message

    };

}

#endif

