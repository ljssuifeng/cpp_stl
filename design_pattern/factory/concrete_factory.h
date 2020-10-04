#ifndef DESIGNPATTERN_CONCRETE_FACTORY_H
#define DESIGNPATTERN_CONCRETE_FACTORY_H

#include "concrete_product.h"
#include "factory.h"

// 奔驰工厂
class BenzFactory : public Factory {
 public:
  ICar* CreateCar() { return new BenzCar(); }
  IBike* CreateBike() { return new BenzBike(); }
};

// 宝马工厂
class BmwFactory : public Factory {
 public:
  ICar* CreateCar() { return new BmwCar(); }

  IBike* CreateBike() { return new BmwBike(); }
};

// 奥迪工厂
class AudiFactory : public Factory {
 public:
  ICar* CreateCar() { return new AudiCar(); }

  IBike* CreateBike() { return new AudiBike(); }
};

#endif  // DESIGNPATTERN_CONCRETE_FACTORY_H
