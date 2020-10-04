#include <string>
#include <vector>
#include <fstream>

// Definition of a singleton logger class
class Logger final {
 public:
  enum class LogLevel { Error, Info, Debug };

  // Returns a reference to the singleton Logger object
  static Logger& instance();

  // Prevent copy/move construction
  Logger(const Logger&) = delete;
  Logger(const Logger&&) = delete;

  // Prevent copy/move assignment operations
  Logger& operator=(const Logger&) = delete;
  Logger& operator=(const Logger&&) = delete;

  // Sets the log level
  void setLogLevel(LogLevel level);

  // Logs a single message at the given log level
  void log(std::string message, LogLevel logLevel);

  // Logs a vector of message at the given log level
  void log(const std::vector<std::string>& messages, LogLevel logLevel);

 private:
  // Private constructor and destructor
  Logger();
  ~Logger();

  // Converts a log level to human readable string
  std::string getLogLevelString(LogLevel level) const;

  static const char* const kLogFileName;
  std::ofstream mOutputStream;
  LogLevel mLogLevel = LogLevel::Error;
};
