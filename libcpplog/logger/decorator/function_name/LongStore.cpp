#include <libcpplog/logger/decorator/function_name/LongStore.hpp>

#include <source_location>
#include <string>

namespace cpplog::logger::decorator::function_name {

    LongStore::LongStore(const std::source_location location) noexcept :
        location{ location } {

    }

    std::string LongStore::extract() const {
        return location.function_name();
    }

}