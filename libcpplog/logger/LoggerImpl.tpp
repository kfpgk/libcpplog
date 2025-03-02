#include <libcpplog/logger/LoggerImpl.hpp>

#include <mutex>
#include <syncstream>

namespace cpplog::logger {

    template<typename T> 
    Logger::Impl& Logger::Impl::operator<<(const T& data) {
        std::osyncstream(outStream.get()) << data;
        return *this;                
    }
   
}