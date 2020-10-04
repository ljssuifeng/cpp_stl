#include <iostream>
#include <list>
#include "observer.h"
#include "subject.h"

class ConcreteSubject : public ISubject {
 public:
  ConcreteSubject() { m_fPrice = 10.0; }
  void SetPrice(float price) { m_fPrice = price; }
  void Attach(IObserver *observer) { m_Observers.push_back(observer); }
  void Detach(IObserver *observer) { m_Observers.remove(observer); }
  void Notify() {
    std::list<IObserver *>::iterator it = m_Observers.begin();
    while (it != m_Observers.end()) {
      (*it)->Update(m_fPrice);
      it++;
    }
  }

 private:
  std::list<IObserver *> m_Observers;
  float m_fPrice;
};
