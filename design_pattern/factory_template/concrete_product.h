#pragma once

#include <memory>
#include <string>
#include "factory.h"
#include "product.h"

template <typename ProductType_t, typename ProductImpl_t>
class ProductRegistrar : public IProductRegistrar<ProductType_t> {
 public:
  std::shared_ptr<ProductType_t> CreateProduct() {
    return std::make_shared<ProductImpl_t>();
  }
};
