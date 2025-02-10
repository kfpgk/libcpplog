#include <libcpplog/logger/LoggerImpl.hpp>

#include <mutex>

namespace cpplog::logger {

    template<typename T> 
    Logger::Impl& operator<<(Logger::Impl& impl, const T& data) {
        std::scoped_lock lock(impl.outMutex);
        impl.outStream.get() << data;
        return impl;                
    }
   
}