#include "log.hpp"

std::ostream &logger::operator<<(std::ostream &strm,
                                 logger::severity_level level) {
  static const char *strings[] = {
      "trace", "debug", "info", "warning", "error", "critical"};
  if (static_cast<std::size_t>(level) < sizeof(strings) / sizeof(*strings))
    strm << strings[level];
  else
    strm << static_cast<int>(level);

  return strm;
}

void logger::init() {
  boost::shared_ptr<logging::core> core = logging::core::get();

  auto env = std::getenv("LOG");
  if (env) {
    auto log_level_env = std::string(env);
    if (log_level_env == "debug") {
      core->set_filter(expr::attr<severity_level>("Severity") >= debug);
    }
    if (log_level_env == "info") {
      core->set_filter(expr::attr<severity_level>("Severity") >= info);
    }
    if (log_level_env == "warning") {
      core->set_filter(expr::attr<severity_level>("Severity") >= warning);
    }
    if (log_level_env == "error") {
      core->set_filter(expr::attr<severity_level>("Severity") >= error);
    }
    if (log_level_env == "critical") {
      core->set_filter(expr::attr<severity_level>("Severity") >= critical);
    }
  }

  std::string timestamp = "%Y-%m-%d %H:%M:%S ";

  logging::add_console_log(
      std::clog,
      keywords::filter = expr::attr<severity_level>("Severity") == trace,
      keywords::format = expr::stream
                         << expr::format_date_time<boost::posix_time::ptime>(
                                "TimeStamp", timestamp)
                         << "|" << std::left << std::setw(16)
                         << expr::attr<std::string>("Channel") << "|"
                         << ansiCode::green << std::left << std::setw(8)
                         << expr::attr<severity_level>("Severity")
                         << ansiCode::reset << "|" << expr::message);
  logging::add_console_log(
      std::clog,
      keywords::filter = expr::attr<severity_level>("Severity") == debug,
      keywords::format = expr::stream
                         << expr::format_date_time<boost::posix_time::ptime>(
                                "TimeStamp", timestamp)
                         << "|" << std::left << std::setw(16)
                         << expr::attr<std::string>("Channel") << "|"
                         << ansiCode::cyan << std::left << std::setw(8)
                         << expr::attr<severity_level>("Severity")
                         << ansiCode::reset << "|" << expr::message);
  logging::add_console_log(
      std::clog,
      keywords::filter = expr::attr<severity_level>("Severity") == info,
      keywords::format =
          expr::stream << expr::format_date_time<boost::posix_time::ptime>(
                              "TimeStamp", timestamp)
                       << "|" << std::left << std::setw(16)
                       << expr::attr<std::string>("Channel") << "|" << std::left
                       << std::setw(8) << expr::attr<severity_level>("Severity")
                       << ansiCode::reset << "|" << expr::message);
  logging::add_console_log(
      std::clog,
      keywords::filter = expr::attr<severity_level>("Severity") == warning,
      keywords::format = expr::stream
                         << expr::format_date_time<boost::posix_time::ptime>(
                                "TimeStamp", timestamp)
                         << "|" << std::left << std::setw(16)
                         << expr::attr<std::string>("Channel") << "|"
                         << ansiCode::yellow << std::left << std::setw(8)
                         << expr::attr<severity_level>("Severity")
                         << ansiCode::reset << "|" << expr::message);
  logging::add_console_log(
      std::clog,
      keywords::filter = expr::attr<severity_level>("Severity") == error ||
                         expr::attr<severity_level>("Severity") == critical,
      keywords::format = expr::stream
                         << expr::format_date_time<boost::posix_time::ptime>(
                                "TimeStamp", timestamp)
                         << "|" << std::left << std::setw(16)
                         << expr::attr<std::string>("Channel") << "|"
                         << ansiCode::red << std::left << std::setw(8)
                         << expr::attr<severity_level>("Severity")
                         << ansiCode::reset << "|" << expr::message);
  logging::add_common_attributes();
}
