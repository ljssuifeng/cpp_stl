#ifndef DESIGNPATTERN_SINGLETON_H
#define DESIGNPATTERN_SINGLETON_H

// 单例模式
class Singleton {
 private:
  Singleton() {}
  ~Singleton() {}
  Singleton(const Singleton &);
  Singleton &operator=(const Singleton &);

 public:
  static Singleton &GetInstance() {
    static Singleton instance;
    return instance;
  }
  void DoSomething();
};

//// 懒汉式单例模式
// class Singleton {
// private:
//  Singleton() {}
//  static Singleton *pInstance;

// public:
//  static Singleton *GetInstance() {
//    if (pInstance == nullptr) pInstance = new Singleton();
//    return pInstance;
//  }
//};

#endif  // DESIGNPATTERN_SINGLETON_H
