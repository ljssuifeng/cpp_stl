#include "logger.h"
#include <iomanip>
#include <stdexcept>

const char* const Logger::kLogFileName = "log.out";

Logger& Logger::instance() {
  static Logger instance;
  return instance;
}

Logger::Logger() {
  mOutputStream.open(kLogFileName, std::ios_base::app);
  if (!mOutputStream.good()) {
    throw std::runtime_error("Unable to initialize the Logger!");
  }
}

Logger::~Logger() {
  mOutputStream << "Logger shutting down." << std::endl;
  mOutputStream.close();
}

void Logger::setLogLevel(LogLevel level) { mLogLevel = level; }

std::string Logger::getLogLevelString(LogLevel level) const {
  switch (level) {
    case LogLevel::Error:
      return "ERROR";
    case LogLevel::Info:
      return "INFO";
    case LogLevel::Debug:
      return "DEBUG";
  }
  throw std::runtime_error("Invalid log Level.");
}

void Logger::log(std::string message, LogLevel logLevel) {
  if (mLogLevel < logLevel) {
    return;
  }
  mOutputStream << getLogLevelString(logLevel) << ": " << message << std::endl;
}

void Logger::log(const std::vector<std::string>& messages, LogLevel logLevel) {
  if (mLogLevel < logLevel) {
    return;
  }
  for (const auto& message : messages) {
    log(message, logLevel);
  }
}
