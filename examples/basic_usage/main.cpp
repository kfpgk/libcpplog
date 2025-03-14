#include <libcpplog/debug/Debug.hpp>
#include <libcpplog/logger/Log.hpp>

#include <fstream>
#include <sstream>
#include <stdexcept>
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

    // There is a convenient overload taking a LogRequest::functionName() as second argument.
    // Suitable e.g. for logging during unit testing
    logger.log("Running ", LogRequest::functionName());

	// Log an exception. The logger will unwrap nested exceptions automatically.
    try {
		throw std::runtime_error("This is an exception");
	} catch (const std::exception& e) {
		logger.log(e);
	}

    // Log via stream insertion operator. This is unformatted.
    logger << "Plain streamed log message" << std::endl;

    // Log using the currently configured format using the LogRequest object and stream insertion operator.
    logger << LogRequest(LogLevel::Error) 
           << "This is a rich error log via stream operator" << std::endl;

    // Log only log level and message via stream insertion operator.
    logger << LogLevel::Warning << "This is a streamed warning " << myF << std::endl;

    // You can also do this via the LogRequest object in a way that is consistent with timestamp and context.
    logger << LogRequest::logLevel(LogLevel::Warning) << "This will do the same" << std::endl;

    // Log only time stamp and message via stream insertion operator.
    logger << LogRequest::timeStamp() 
           << "My time stamped streamed log message. Result: " 
           << myF << std::endl;

    // Log only context and message via stream insertion operator.
    logger << LogRequest::context() << "This is a streamed warning including context " << std::endl;

	// Log function name via stream insertion operator. Need to specify if we do not want a separator.
    logger << "Running " << LogRequest::functionName(Separator::none) << std::endl;

    // Log message only once.
    for (int i = 0; i < 10; i++) {
        logOnce("Only first iteration.");
    }

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

    // Log to file in append mode
    std::ofstream logFile("logFile.txt", std::ios_base::app);
    myLogger.setOutput(logFile);
    myLogger << LogRequest() << "Log to test file" << std::endl;

}
