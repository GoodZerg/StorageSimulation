#pragma once

#include "Product.h"

class IMoneyCount {
public:
  virtual void AddMoney(Product* product) = 0;
  virtual void TakeMoney(Product* product) = 0;
};
