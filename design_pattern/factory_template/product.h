#pragma once

#include <memory>

template <typename ProductType_t>
class IProductRegistrar {
  // base class, product registrar interface class
 public:
  virtual std::shared_ptr<ProductType_t> CreateProduct() = 0;

 protected:
  IProductRegistrar() = default;
  virtual ~IProductRegistrar() = default;
  IProductRegistrar(const IProductRegistrar&) = delete;
  IProductRegistrar& operator=(const IProductRegistrar&) = delete;
};
