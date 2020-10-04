#pragma once

#include <map>
#include <memory>
#include <string>
#include "product.h"

template <typename ProductType_t>
class ProductFactory {
 public:
  static ProductFactory<ProductType_t>& Instance() {
    static ProductFactory<ProductType_t> instance;
    return instance;
  }
  // product register
  void RegisterProduct(IProductRegistrar<ProductType_t>* registrar,
                       std::string name) {
    m_ProductRegistrar[name] = registrar;
  }
  std::shared_ptr<ProductType_t> GetProduct(std::string name) {
    if (m_ProductRegistrar.find(name) != m_ProductRegistrar.end()) {
      return m_ProductRegistrar[name]->CreateProduct();
    } else {
      return nullptr;
    }
  }

 protected:
  ProductFactory() = default;
  virtual ~ProductFactory() = default;
  ProductFactory(const ProductFactory&) = delete;
  ProductFactory& operator=(const ProductFactory&) = delete;

  std::map<std::string, IProductRegistrar<ProductType_t>*> m_ProductRegistrar;
};
