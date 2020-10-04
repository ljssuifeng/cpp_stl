#pragma once

class IObserver;

class ISubject {
  virtual void Attach(IObserver *) = 0;
  virtual void Detach(IObserver *) = 0;
  virtual void Notify() = 0;
};
