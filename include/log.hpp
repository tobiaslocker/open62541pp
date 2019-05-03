#ifndef OPCUA_CLIENT_LOG_H
#define OPCUA_CLIENT_LOG_H

#include <boost/log/attributes/named_scope.hpp>
#include <boost/log/attributes/timer.hpp>
#include <boost/log/common.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/support/date_time.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/utility/setup/file.hpp>

namespace logging = boost::log;
namespace sinks = boost::log::sinks;
namespace attrs = boost::log::attributes;
namespace src = boost::log::sources;
namespace expr = boost::log::expressions;
namespace keywords = boost::log::keywords;

namespace ansiCode {
const std::string red("\033[0;31m");
const std::string reset("\x1b[0m");
const std::string bold("\u001b[1m");
const std::string underline("\u001b[4m");
const std::string reversed("\u001b[7m");
const std::string black("\u001b[30m");
const std::string green("\u001b[32m");
const std::string yellow("\u001b[33m");
const std::string blue("\u001b[34m");
const std::string magenta("\u001b[35m");
const std::string cyan("\u001b[36m");
const std::string white("\u001b[37m");
const std::string backgroundBlack("\u000b[40m");
const std::string backgroundRed("\u001b[41m");
const std::string backgroundGreen("\u001b[42m");
const std::string backgroundYellow("\u001b[43m");
const std::string backgroundBlue("\u001b[44m");
const std::string backgroundMagenta("\u001b[45m");
const std::string backgroundCyan("\u001b[46m");
const std::string backgroundWhite("\u001b[47m");
const std::string backgroundBrightBlack("\u001b[40;1m");
const std::string backgroundBrightRed("\u001b[41;1m");
const std::string backgroundBrightGreen("\u001b[42;1m");
const std::string backgroundBrightYellow("\u001b[43;1m");
const std::string backgroundBrightBlue("\u001b[44;1m");
const std::string backgroundBrightMagenta("\u001b[45;1m");
const std::string backgroundBrightCyan("\u001b[46;1m");
const std::string backgroundBrightWhite("\u001b[47;1m");
}  // namespace ansiCode

using boost::shared_ptr;

namespace logger {

enum severity_level { trace, debug, info, warning, error, critical };

extern std::ostream& operator<<(std::ostream& strm, severity_level level);

extern void init();

}  // namespace logger

#endif  // OPCUA_CLIENT_LOG_H
