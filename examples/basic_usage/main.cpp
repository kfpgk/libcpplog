#include <libcpplog/debug/Debug.hpp>
#include <libcpplog/logger/Log.hpp>
#include <libcpplog/logger/LogComponent.hpp>
#include <libcpplog/logger/LogFormat.hpp>
#include <libcpplog/logger/Logger.hpp>
#include <libcpplog/logger/LogStream.hpp>

#include <sstream>
#include <vector>

using namespace cpplog::logger;

void useDebugMacros();
void useLogger();

int main(int argc, char* argv[]) {

    DEBUG_ENTER();

    log("Start");

    useDebugMacros();

    useLogger();

    DEBUG_EXIT();
    return 0;
}

void useDebugMacros() {

    DEBUG_ENTER();

    std::vector<int> someData {1, 5, 23, 4, 5};

    for (auto i : someData) {
        DEBUG(i);
    }

    DEBUG_EXIT();
}

void useLogger() {

    // Arbitrary float variable for use in examples
    float myF = 40 / 2.1;

    // Use global logger via log function
    log("This is the default log format. Result: " + std::to_string(myF));

    // Specify log level explicitely
    log(LogLevel::Warning, "Result " + std::to_string(myF) + " could be too high.");

    // Use custom format LogLevel | Context | Message
    logger.setFormat( { LogComponent::LogLevel, LogComponent::Context } );

    // Log again with new format
    log("This is a log with custom log format without timestamp.");

    // Reset format to default
    logger.setFormat( { LogFormat::defaultValue() });

    // Log again with new format
    log("Logging again with default format.");

    // We can also log using the global `logger` object. This is the same as calling `log`
    logger.log("Using the global logger object");

    // Log via stream insertion operator. This is unformatted.
    logger << "Plain streamed log message" << std::endl;

    // Log using the currently configured format using the LogStream object and stream insertion operator.
    logger << LogStream(LogLevel::Error) 
           << "This is a rich error log via stream operator" << std::endl;

    // Log only log level and message via stream insertion operator.
    logger << LogLevel::Warning << "This is a streamed warning " << myF << std::endl;

    // Log only time stamp and message via stream insertion operator.
    logger << LogStream::timeStamp() 
           << "My time stamped streamed log message. Result: " 
           << myF << std::endl;

    // Log only context and message via stream insertion operator.
    logger << LogStream::context() << "This is a streamed warning including context " << std::endl;

    // Log to string stream instead.
    std::stringstream ss;
    logger.setOutput(ss);
    log("Log to string stream");
    std::cout << ss.str() << std::endl;

    // Create an own local logger object and use it instead of the global one
    Logger myLogger(
        std::cout,
        { LogComponent::TimeStamp, LogComponent::Context });
    myLogger.log("Custom logger");

}
