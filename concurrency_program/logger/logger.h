#include <condition_variable>
#include <mutex>
#include <queue>
#include <string>
#include <thread>

class Logger {
 public:
  // Starts a background thread writing log entries to a file
  Logger();
  ~Logger() {
    {
      std::unique_lock<std::mutex> ul(mMutex);
      mExit = true;
      mCondVar.notify_all();
    }
    mThread.join();
  }
  // prevent copy constructor and assignment
  Logger(const Logger& src) = delete;
  Logger& operator=(const Logger& rhs) = delete;
  // add log entry to the queue
  void log(std::string entry);

 private:
  // the function running in the background thread
  void processEntries();
  // Mutex and condition variable to protect access to the queue
  std::mutex mMutex;
  std::condition_variable mCondVar;
  std::queue<std::string> mQueue;
  std::thread mThread;
  bool mExit = false;
};
