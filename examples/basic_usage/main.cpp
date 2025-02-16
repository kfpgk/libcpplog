#include <libcpplog/debug/Debug.hpp>
#include <libcpplog/logger/Log.hpp>
#include <libcpplog/logger/Logger.hpp>

#include <string>
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
    logger.setFormat( { log_format::defaultValue } );

    // Log again with new format
    log("Logging again with default format.");

    // We can also log using the global `logger` object. This is the same as calling `log`
    logger.log("Using the global logger object");

    // Log via stream insertion operator. This is unformatted.
    logger << "Stream logging" << std::endl;

    //Log via stream insertion operator and add logging meta data.
    logger << LogLevel::Warning << "This is a warning " << myF << std::endl;
}

void countUp() {

    static int counter = 0;

    Logger logger2(
        std::cout, 
        LogFormat{
            LogComponent::LogLevel,
            LogComponent::Context});

    logger.log("Test log");

    log("Global logger");

    logger << LogLevel::Warning << std::source_location::current() << "Counter: " << counter++ << std::endl;
    logger << LogLevel::Warning << std::source_location::current() << "Counter: " << counter++ << std::endl;

}