#include <future>
#include <iostream>
#include <mutex>
#include <string>

std::mutex printMutex;  // enable synchronized output with print()

void print(const std::string& s) {
  std::lock_guard<std::mutex> lock(printMutex);
  for (char c : s) {
    std::cout.put(c);
  }
  std::cout << std::endl;
}

int main() {
  auto f1 = std::async(std::launch::async, print, "Hello from first thread.");
  auto f2 = std::async(std::launch::async, print, "Hello from second thread.");
  print("Hello from the main thread.");
}

////recursive_lock  允许递归调用，而不会发生死锁
// class DatabaseAccess {
// private:
//    std::recursive_mutex dbMutex;
// public:
//    void createTable() {
//        std::lock_guard<std::recursive_mutex> lg(dbMutex);
//        ...
//    }
//    void insertData() {
//        std::lock_guard<std::recursive_mutex> lg(dbMutex);
//        ...
//    }

//    void createTableAndInsertData() {
//        std::lock_guard<std::recursive_mutex> lg(dbMutex);
//        ...
//        createTable();  // ok, no deadlock
//    }
//};

////try_lock
// std::mutex m;
////try to acquire a lock and do other stuff while this isn't possible
// while(m.try_lock() == false) {
//    doSomethingStuff();
//}
// std::lock_guard<std::mutex> lg(m, std::adopt_lock);
//...

//// timed_mutex, try_lock_for/try_lock_until
// std::timed_mutex m;
//// try for one second to acquire a lock
// if (m.try_lock() _for(std::chrono::seconds(1))) {
//  std::lock_guard<std::timed_mutex> lg(m, std::adpot_lock);
//  ...
//} else {
//  couldNotGetTheLock();
//}

////lock multi mutexes
// std::mutex m1;
// std::mutex m2;
//...
//{
// std::lock(m1, m2); // lock both mutexes (or none if not possible)
// std::lock_guard<std::mutex> lockM1(m1, std::adopt_lock);
// std::lock_guard<std::mutex> lockM2(m2, std::adopt_lock);
//...
//} //automatically unlock all mutexes

//// try_lock()
// std::mutex m1;
// std::mutex m2;
// int idx = std::try_lock(m1, m2);  // try to lock both mutexes
// if (idx < 0) {                    // both locks succeded
//  std::lock_guard<std::mutex> lockM1(m1, std::adopt_lock);
//  std::lock_guard<std::mutex> lockM2(m2, std::adopt_lock);
//  ...
//}  // automatically unlock all mutexes
// else {
//  // idx has zero-based index of first failed lock
//  std::cerr << "could not lock mutex m" << idx + 1 << std::endl;
//}

////unique_lock
// std::unique_lock<std::mutex> lock(mutex, std::try_to_lock);
//...
// if(lock) { //if lock was successful
//    ...
//}

// std::unique_lock<std::timed_mutex> lock(mutex, std::chrono::seconds(1));

// std::mutex m1, m2;
// std::unique_lock<std::mutex> lockM1(m1, std::defer_lock);
// std::unique_lock<std::mutex> lockM2(m2, std::defer_lock); // init lock but
// not lock mutex now
//...
// std::lock(m1, m2); //lock both mutexes (or none if not possible)

////example for lock_guard, unique_lock

// bool readyFlag;
// std::mutex readyFlagMutex;

// void thread1() {
//    //do something thread2 needs as preparation
//    ...
//    std::lock_guard<std::mutex> lg(readyFlagMutex);
//    readyFlag = true;
//}

// void thread2() {
//    //wait until readyFlag is true (thread1 is done)
//    {
//        std::unique_lock<std::mutex> ul(readyFlagMutex);
//        while(!readyFlag) {
//            ul.unlock();
//            std::this_thread::yield(); // hint to  reschedule to the next
//            thread
//            std::this_thread::sleep_for(std::chrono::milliseconds(100));
//            ul.lock();
//        }
//    } //release lock
//    //do whatever shall happen after thread1 has prepared things
//    ...
//}
