#ifndef LIBCPPLOG_LOGGER_LOGGER_IMPL_HPP
#define LIBCPPLOG_LOGGER_LOGGER_IMPL_HPP

#include <libcpplog/logger/Logger.hpp>
#include <libcpplog/logger/LogComponent.hpp>
#include <libcpplog/logger/LogFormat.hpp>
#include <libcpplog/logger/LogLevel.hpp>

#include <functional>
#include <mutex>
#include <ostream>
#include <source_location>
#include <string>
#include <string_view>
#include <unordered_set>

namespace cpplog::logger {

    /**
     * @brief Logger class implementation
     * 
     * Patterns:
     *  - Pimpl idiom
     */
    class Logger::Impl {

    public:
		/**
		 * @brief Constructor
		 *
		 * @param[in] outStream The stream onto which all
		 * subsequent logs get written to.
		 * @param[in] format The format of the log message
		 */
        Impl(std::ostream& outStream, LogFormat) noexcept;

        /**
		 * @brief Deleted copy constructor
         */
        Impl(const Impl&) = delete;

        /**
		 * @brief Deleted copy assignment operator
         */
        Impl& operator=(const Impl&) = delete;

        /**
		 * @brief Destructor
         */
        ~Impl() = default;

        /**
         * @brief Configure output stream
         *
         * @param[in] outStream The stream onto which all
         * subsequent logs get written to.
         */
        void setOutput(std::ostream& outStream) noexcept;

		/**
		 * @brief Set the format of the log message
		 *
		 * @param[in] format The format of the log message
		 */
        void setFormat(const LogFormat& format) noexcept;

		/**
         * @brief Logs \p message to configured output stream
         * using the configured log format.
		 *
		 * @param[in] message The message to be logged
		 * @param[in] location Location of the context that
         * shall be logged.
		 */
        void log(
            const std::string_view message,
            const std::source_location location) const;

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
            const std::source_location location) const;

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
            const std::source_location location);

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
            const std::source_location location);

        /**
         * @brief Insertion operator overload for `std::endl`
         *
         * `std::endl` is a templated function, hence
         * we cannot pass it to the function template.
         */
        Impl& operator<<(decltype(std::endl<char, std::char_traits<char>>) endl);

        /**
         * @brief Insertion operator overload for `LogLevel`
         *
         * Log the corresponding log level
         */
        Impl& operator<<(LogLevel level);

        /**
         * @brief Insertion operator overload for `LogStreamComponent`
         *
         * Log the corresponding component
         */
        Impl& operator<<(LogStreamComponent component);

        /**
         * @brief Insertion operator overload for `source_location`
         *
         * Log the corresponding location
         */
        Impl& operator<<(const std::source_location& location);

        /**
         * @brief Insertion operator
         */
        template<typename T> 
        Impl& operator<<(const T& data);
    
    private:
        ///< The stream onto which all logs get written to
		std::reference_wrapper<std::ostream> outStream;
        
		mutable std::mutex outMutex; ///< Mutex for the output stream

		///< The format of the log message
        LogFormat format;

        ///< Log level if used does not specify log level
        LogLevel defaultLogLevel = log_level::defaultValue;

		///< The set of messages that have been logged once
        std::unordered_set<std::string> loggedOnceMessages;

		mutable std::mutex mutexForLoggedMsg; ///< Mutex for the set of logged once messages

		/**
		 * @brief Constructs a log message according to the
		 * configured log format and returns it as string
		 *
		 * @param[in] logLevel The log level of the message
		 * @param[in] message The message to be logged
		 * @param[in] location Location of the context that
		 * shall be logged.
         * 
		 * @return The constructed log message
		 */
        std::string constructLogMessage(
            LogLevel logLevel,
            const std::string_view message,
            const std::source_location& location) const;

        /**
         * @brief Constructs a log message according to a
         * log format specified in \p format and returns it as string
         *
         * @param[in] logLevel The log level of the message
         * @param[in] message The message to be logged
         * @param[in] location Location of the context that
         * shall be logged.
		 * @param[in] format The format of the log message
         *
         * @return The constructed log message
         */
        std::string constructLogMessage(
            LogLevel logLevel,
            const std::string_view message,
            const std::source_location& location,
            LogFormat format) const;

        /**
		 * @brief Builds the key for a message that has been logged once
         */
        std::string buildMessageKey(
            const std::string_view message, const std::source_location& location) const;
                    
    };

}

#include <libcpplog/logger/LoggerImpl.tpp>

#endif