#include "logger.h"

int main() {
  // Set log level to Debug
  Logger::instance().setLogLevel(Logger::LogLevel::Debug);

  // Log some messages
  Logger::instance().log("test message", Logger::LogLevel::Debug);
  std::vector<std::string> items = {"item1", "item2"};
  Logger::instance().log(items, Logger::LogLevel::Error);

  // set logLevel to Error
  Logger::instance().setLogLevel(Logger::LogLevel::Error);
  // Now that the log level is set to Error, logging a Debug message will be
  // ignored
  Logger::instance().log("A debug message.", Logger::LogLevel::Debug);
}
