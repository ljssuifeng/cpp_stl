#include "logger.h"
#include <fstream>
#include <iostream>

Logger::Logger() {
  // Start background thread
  mThread = std::thread(&Logger::processEntries, this);
}

void Logger::log(std::string entry) {
  // Lock mutex and add entry to the queue
  std::lock_guard<std::mutex> lock(mMutex);
  mQueue.push(entry);
  mCondVar.notify_all();
}

void Logger::processEntries() {
  // Open a log file.
  std::ofstream logFile("log.txt");
  if (logFile.fail()) {
    std::cerr << "Failed to open logfile." << std::endl;
    return;
  }
  // Start processing loop
  std::unique_lock<std::mutex> ul(mMutex);
  while (true) {
    // Wait for a notification
    if (!mExit) {
      mCondVar.wait(ul);
    }
    // condition variable notified, something might be in the queue.
    // and/or we need to shutdown this thread
    //    ul.unlock();
    while (true) {
      //      ul.lock();
      if (mQueue.empty()) {
        break;
      } else {
        logFile << mQueue.front() << std::endl;
        mQueue.pop();
      }
      //      ul.unlock();
    }
    if (mExit) break;
  }
}
