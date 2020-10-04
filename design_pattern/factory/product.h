#ifndef DESIGNPATTERN_PRODUCT_H
#define DESIGNPATTERN_PRODUCT_H

#include <string>

// 汽车接口
class ICar {
 public:
  virtual std::string Name() = 0;
};

// 自行车接口
class IBike {
 public:
  virtual std::string Name() = 0;
};

#endif  // DESIGNPATTERN_PRODUCT_H
