#ifndef LIBCPPLOG_LOGGER_LOGGER_HPP
#define LIBCPPLOG_LOGGER_LOGGER_HPP

#include <libcpplog/logger/LogComponent.hpp>
#include <libcpplog/logger/LogFormat.hpp>
#include <libcpplog/logger/LogLevel.hpp>

#include <iostream>
#include <memory>
#include <ostream>
#include <source_location>
#include <string>
#include <string_view>

namespace cpplog::logger {

    /**
     * @brief Logger class for logging to a
     * user define output stream
     *        
     * This class involves runtime overhead
     * and thus is not intended for debug outputs.
     */
    class Logger {

    public:
        /**
         * @brief Constructor
         *
         * @param[in] outStream The stream onto which all
         * subsequent logs get written to.
         * @param[in] format The format of the log message
         * in a ordered sequence of LogComponent enums. Last
         * component will be at the beginning of the line.
         */
        Logger(
            std::ostream& outStream = std::cout,
            LogFormat format = LogFormat::defaultValue()) noexcept;

        /**
		 * @brief Destructor
         */        
        ~Logger();

        /**
		 * @brief Deleted copy constructor 
         */
        Logger(const Logger&) = delete;

        /**
         * @brief Deleted assignment operator
         */
        Logger& operator=(const Logger&) = delete;

        /**
         * @brief Configure output stream
         * 
         * @param[in] outStream The stream onto which all
         * subsequent logs get written to.
         */
        void setOutput(std::ostream& outStream) noexcept;

        /**
         * @brief Configure log format
         *
         * @param[in] format The format of the log message
         * in a ordered sequence of LogComponent enums. Last
         * component will be at the beginning of the line.
         */
        void setFormat(const LogFormat& format) noexcept;

        /**
         * @brief Logs \p message to configured output stream
         * using the configured log format.
         * 
         * @param[in] message The message to be logged
         * @param[in] location Gets filled automatically via
         * default values to represent the caller's context. 
         */
        void log(
            const std::string_view message,
            const std::source_location location = std::source_location::current()) const;

        /**
         * @brief Logs \p message to configured output stream
         * using the configured log format.
         *
         * @param[in] logLevel The log level of the message
         * @param[in] message The message to be logged
         * @param[in] location Location of the context that
         * shall be logged.
         */
        void log(
            LogLevel logLevel,
            const std::string_view message,
            const std::source_location location = std::source_location::current()) const;
        
        /**
         * @brief Logs \p message to configured output stream,
         * but only once.
         * 
         * If the same call to `logonce` is executed again, the 
         * message will not be logged again. 
         * 
         * @param[in] message The message to be logged
         * @param[in] location Gets filled automatically via
         * default values to represent the caller's context. 
         */
        void logOnce(
            const std::string_view message,
            const std::source_location location = std::source_location::current());

        /**
         * @brief Logs \p message to configured output stream,
         * but only once.
         *
         * If the same call to `logonce` is executed again, the
         * message will not be logged again.
         *
         * @param[in] logLevel The log level of the message
         * @param[in] message The message to be logged
         * @param[in] location Gets filled automatically via
         * default values to represent the caller's context.
         */
        void logOnce(
            LogLevel logLevel,
            const std::string_view message,
            const std::source_location location = std::source_location::current());

        /**
         * @brief Insertion operator for strings
         */
        Logger& operator<<(const std::string_view string);

        /**
         * @brief Insertion operator for floats
         */
        Logger& operator<<(float value);

        /**
         * @brief Insertion operator for `std::endl`
         */
        Logger& operator<<(decltype(std::endl<char, std::char_traits<char>>) endl);

        /**
         * @brief Insertion operator overload for `LogLevel`
         *
         * Log the corresponding log level
         */
        Logger& operator<<(LogLevel level);

        /**
         * @brief Insertion operator overload for `LogStreamComponent`
         *
         * Log the corresponding component
         */
        Logger& operator<<(LogStreamComponent component);

        /**
         * @brief Insertion operator overload for `source_location`
         *
         * Log the corresponding location
         */
        Logger& operator<<(std::source_location location);
    
    private:
		class Impl; ///< Pimpl idiom. Class forward declaration
		std::unique_ptr<Impl> pImpl; ///< Pimpl idiom. Pointer to implementation
    };

}

#endif