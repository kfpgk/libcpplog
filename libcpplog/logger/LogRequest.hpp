#ifndef LIBCPPLOG_LOGGER_LOG_REQUEST_HPP
#define LIBCPPLOG_LOGGER_LOG_REQUEST_HPP

#include <libcpplog/logger/LogLevel.hpp>

#include <source_location>

namespace cpplog::logger {

    /**
	 * @brief Enum to define whether separator shall be used between log components
     */
    enum class Separator {
		def, ///< Default, let the library decide
        none, ///< No separator
        use ///< Use configured separator
    };

    /**
     * @brief Log request class that can be passed to the logger
     * 
     * Use this class when you want to add log meta data when
     * streaming via the stream insertion operator.
     * Streaming an instance of `LogRequest()` will log the 
     * currently configured LogFormat.
     * 
     * Log component can also be streamed independently using the
     * static methods `logLevel()`, `context()`, `timeStamp()` &
	 * `functionName()`.
     * 
	 * Per default, when streaming, a separator is appended to the
	 * requested log component. Use `Separator::none` to disable 
     * the separator.
     */
    class LogRequest {

    private:
        /**
         * @brief Base object to transport a request to the logger.
         */
        class RequestObject {
        public:
            /**
             * @brief Constructor
             *
             * @param[in] sep Flag to enable/disable separator
             */
            RequestObject(Separator sep) noexcept;

            /**
			 * @brief Returns true if user requested separator
             */
            bool userWantsSeparator() const noexcept;

            /**
             * @brief Returns true if user requested to not use separator
             */
            bool userDisabledSeparator() const noexcept;
        private:
            Separator sep; ///< Separator used or not
        };

    public:
        /**
         * @brief Constructor
         * 
         * @param[in] logLevel The log level of the message
         * @param[in] location Location of the context that
         * shall be logged. Do not pass and use default.
         */
        LogRequest(
            LogLevel logLevel = log_level::defaultValue,
            const std::source_location location = std::source_location::current()) noexcept;

        /**
         * @brief Returns the stored source location
         */
        std::source_location getLocation() const noexcept;

        /**
         * @brief Returns the stored log level
         */
        LogLevel getLogLevel() const noexcept;

        /**
         * @brief Returns a log level for streaming
         * 
         * @param[in] logLevel The log level to be streamed
         */
        static LogLevel logLevel(LogLevel logLevel = log_level::defaultValue) noexcept;

        /**
         * @brief Object to transport a function name request to the
         * logger.
         */
        class Context : public RequestObject {
        public:
            /**
             * @brief Constructor
             *
             * @param[in] sep Flag to enable/disable separator
             * @param[in] location The location containing the context
             */
            Context(Separator sep, const std::source_location& location) noexcept;

            /**
             * @brief Extracts the location
             */
            std::source_location getLocation() const noexcept;

        private:
            std::source_location location; ///< The location containing the context
        };

        /**
         * @brief Returns a context for streaming
         * 
         * @param[in] sep Defines whether a separator shall be used
         * @param[in] location Location of the context that
         * shall be logged. Do not pass and use default.
         */
        static Context context(
            Separator sep = Separator::def,
            const std::source_location& location = std::source_location::current()) noexcept;

        /**
         * @brief Object to transport a time stamp request to the
         * logger.
         */
        class TimeStamp : public RequestObject {
        public:
			/**
			 * @brief Constructor
			 *
			 * @param[in] sep Flag to enable/disable separator
			 */
			TimeStamp(Separator sep) noexcept;
        };

        /**
         * @brief Returns a time stamp request for streaming
         */
        static TimeStamp timeStamp(Separator sep = Separator::def) noexcept;

        /**
         * @brief Object to transport a function name request to the
         * logger.
         */
        class FunctionName : public RequestObject {
        public:
			/**
			 * @brief Constructor
			 *
             * @param[in] sep Flag to enable/disable separator
			 * @param[in] location The location containing the function
			 */
            FunctionName(Separator sep, const std::source_location& location) noexcept;

			/**
			 * @brief Extracts the location
			 */
            std::source_location getLocation() const noexcept;

		private:
			std::source_location location; ///< The location containing the function
        };

        /**
         * @brief Returns a function name request for streaming
         */
        static FunctionName functionName(
			Separator sep = Separator::def,
            const std::source_location& location = std::source_location::current()) noexcept;

    private:
        ///< source location
        std::source_location location;

        ///< log level
        LogLevel logLevelAttribute;

    };

}

#endif