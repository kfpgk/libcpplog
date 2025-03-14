#ifndef LIBCPPLOG_LOGGER_DECORATOR_FUNCTION_NAME_SHORT_HPP
#define LIBCPPLOG_LOGGER_DECORATOR_FUNCTION_NAME_SHORT_HPP

#include <libcpplog/logger/decorator/function_name/FunctionName.hpp>
#include <libcpplog/logger/decorator/function_name/ShortStore.hpp>
#include <libcpplog/logger/decorator/Message.hpp>

#include <memory>
#include <source_location>
#include <string>

namespace cpplog::logger::decorator::function_name {

    /**
     * @brief Decorator for log messages that adds a short function_name
     *
     * @details
     * Patterns:
     *  - Decorator
     *  - Template
     */
    class Short : public FunctionName {

    public:
        /**
         * @brief Constructor
         *
         * @param[in] message The message to be decorated
         * @param[in] location The location of the message
         * @param[in] useSeparator Flag indicating whether separator shall be used
         */
        Short(std::unique_ptr<Message> message,
            const std::source_location location,
            bool useSeparator) noexcept;

    private:
        function_name::ShortStore functionNameStore; ///< Object to retrieve the function name

        /**
         * @brief Get the short function name
         */
        std::string getFunctionName() const override;

    };

}

#endif