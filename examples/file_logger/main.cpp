#include <libcpplog/debug/Debug.hpp>
#include <libcpplog/logger/Log.hpp>
#include <libcpplog/logger/Logger.hpp>

using namespace cpplog::logger;

void countUp();

int main(int argc, char* argv[]) {

    DEBUG_ENTER();

    log("Start");

    DEBUG_EXIT();
    return 0;
}

void countUp() {
    DEBUG_ENTER();

    static int counter = 0;

    log(counter++, true);

    logger << counter++;
    
    DEBUG_EXIT();
}