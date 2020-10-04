#include "factory.h"
#include "concrete_product.h"
#include "product.h"

#include <iostream>

class Shoes {
 public:
  Shoes() { std::cout << "shoes construct" << std::endl; }
  ~Shoes() { std::cout << "shoes destructed" << std::endl; }
  virtual void Show() = 0;
};
class NikeShoes : public Shoes {
 public:
  void Show() { std::cout << "nike shoes, just do it." << std::endl; }
  NikeShoes() { std::cout << "Nike shoes construct" << std::endl; }
  ~NikeShoes() { std::cout << "Nike shoes destruct" << std::endl; }
};

class Clothe {
 public:
  Clothe() { std::cout << "clothe construct" << std::endl; }
  ~Clothe() { std::cout << "clothe destruct" << std::endl; }

  virtual void Show() = 0;
};

class UniqloClothe : public Clothe {
 public:
  void Show() { std::cout << "UniqloClothe , i'am uniqlo" << std::endl; }
  UniqloClothe() { std::cout << "UniqloCloth construct" << std::endl; }
  ~UniqloClothe() { std::cout << "UniqloCloth destruct" << std::endl; }
};

int main() {
  ProductRegistrar<Shoes, NikeShoes> nikeShoes;
  ProductFactory<Shoes>::Instance().RegisterProduct(&nikeShoes, "nike");
  auto pNikeShoes = ProductFactory<Shoes>::Instance().GetProduct("nike");
  pNikeShoes->Show();

  ProductRegistrar<Clothe, UniqloClothe> uniqloClothe;
  ProductFactory<Clothe>::Instance().RegisterProduct(&uniqloClothe, "uniqlo");
  auto pUniqloClothe = ProductFactory<Clothe>::Instance().GetProduct("uniqlo");
  pUniqloClothe->Show();
}
