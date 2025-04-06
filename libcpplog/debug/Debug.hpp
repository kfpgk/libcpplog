#ifndef LIBCPPLOG_DEBUG_DEBUG_HPP
#define LIBCPPLOG_DEBUG_DEBUG_HPP

#include <libcpplog/logger/Log.hpp>
#include <libcpplog/logger/Logger.hpp>
#include <libcpplog/logger/LogLevel.hpp>
#include <libcpplog/logger/LogRequest.hpp>

#include <cstddef>
#include <iostream>
#include <source_location>
#include <string>

namespace cpplog::debug {

    inline cpplog::logger::Logger logger; ///< global debug logger object

    inline thread_local std::size_t debugIndent; ///< level of indentation per thread
}

#ifdef DEBUG_BUILD
/**
 * @brief Debug output to global debug logger object.
 *
 * Enabled if `DEBUG_BUILD` is defined.
 * No runtime overhead if disabled.
 */
#   define DEBUG(x) do { \
                cpplog::debug::logger \
                       << cpplog::logger::LogRequest(cpplog::logger::LogLevel::Debug) \
                       << std::string(cpplog::debug::debugIndent, ' ' ) \
                       << x << "\n"; \
            } while (0)
/**
 * @brief Debug output information regarding a function being entered.
 *
 * Indentation for all `DEBUG...` macros is incremented by one.
 *
 * Use `DEBUG_ENTER` and `DEBUG_EXIT` symmetrically to ensure proper formatting.
 *
 * Enabled if `DEBUG_BUILD` is defined.
 * No runtime overhead if disabled.
 */
#   define DEBUG_ENTER() do { \
                std::cerr << std::string(cpplog::debug::debugIndent, ' ' ); \
                std::cerr << "Enter " << std::source_location::current().file_name() << ":" \
                          << __func__ << "(" \
                          << std::source_location::current().line() << ":" \
                          << std::source_location::current().column() << ")" << std::endl; \
                cpplog::debug::debugIndent++; \
            } while (0)
/**
 * @brief Debug output information regarding a function being exited.
 *
 * Indentation for all `DEBUG...` macros is decremented by one.
 *
 * Use `DEBUG_ENTER` and `DEBUG_EXIT` symmetrically to ensure proper formatting.
 *
 * Enabled if `DEBUG_BUILD` is defined.
 * No runtime overhead if disabled.
 */
#   define DEBUG_EXIT() do { \
                cpplog::debug::debugIndent--; \
                std::cerr << std::string(cpplog::debug::debugIndent, ' '); \
                std::cerr << "Exit " << std::source_location::current().file_name() << ":" \
                          << __func__ << "(" \
                          << std::source_location::current().line() << ":" \
                          << std::source_location::current().column() << ")" << std::endl; \
            } while (0)
/**
 * @brief Debug output information regarding a function being exited with a message.
 *
 * Indentation for all `DEBUG...` macros is decremented by one.
 *
 * Use `DEBUG_ENTER` and `DEBUG_EXIT_WITH_MSG` symmetrically to ensure proper formatting.
 *
 * Enabled if `DEBUG_BUILD` is defined.
 * No runtime overhead if disabled.
 */
#   define DEBUG_EXIT_WITH_MSG(msg) do { \
                cpplog::debug::debugIndent--; \
                std::cerr << std::string(cpplog::debug::debugIndent, ' '); \
                std::cerr << "Exit " << std::source_location::current().file_name() << ":" \
                          << __func__ << "(" \
                          << std::source_location::current().line() << ":" \
                          << std::source_location::current().column() << "() - " << msg << std::endl; \
            } while (0)
#else
/**
 * @brief Debug output to global debug logger object.
 *
 * Enabled if `DEBUG_BUILD` is defined.
 * No runtime overhead if disabled.
 */
#   define DEBUG(x) do {} while (0)
 /**
  * @brief Debug output information regarding a function being entered.
  *
  * Indentation for all `DEBUG...` macros is incremented by one.
  *
  * Use `DEBUG_ENTER` and `DEBUG_EXIT` symmetrically to ensure proper formatting.
  *
  * Enabled if `DEBUG_BUILD` is defined.
  * No runtime overhead if disabled.
  */
#   define DEBUG_ENTER() do {} while (0)
  /**
   * @brief Debug output information regarding a function being exited.
   *
   * Indentation for all `DEBUG...` macros is decremented by one.
   *
   * Use `DEBUG_ENTER` and `DEBUG_EXIT` symmetrically to ensure proper formatting.
   *
   * Enabled if `DEBUG_BUILD` is defined.
   * No runtime overhead if disabled.
   */
#   define DEBUG_EXIT() do {} while (0)
   /**
    * @brief Debug output information regarding a function being exited with a message.
    *
    * Indentation for all `DEBUG...` macros is decremented by one.
    *
    * Use `DEBUG_ENTER` and `DEBUG_EXIT_WITH_MSG` symmetrically to ensure proper formatting.
    *
    * Enabled if `DEBUG_BUILD` is defined.
    * No runtime overhead if disabled.
    */
#   define DEBUG_EXIT_WITH_MSG(msg) do {} while (0)
#endif

#endif

