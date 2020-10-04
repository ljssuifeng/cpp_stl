#include <iostream>
#include <string>
#include "observer.h"

class ConcreteObserver : public IObserver {
 public:
  ConcreteObserver(std::string name) : m_strName(name) {}
  void Update(float price) {
    std::cout << m_strName << " -price: " << price << std::endl;
  }

 private:
  std::string m_strName;
};
