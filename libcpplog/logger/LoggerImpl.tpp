#include <libcpplog/logger/LoggerImpl.hpp>

#include <mutex>

namespace cpplog::logger {

    template<typename T> 
    Logger::Impl& Logger::Impl::operator<<(const T& data) {
        std::scoped_lock lock(outMutex);
        outStream.get() << data;
        return *this;                
    }
   
}