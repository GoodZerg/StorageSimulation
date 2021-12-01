#include "Manager.h"

Manager::Manager() { 
  for (auto i : currentSimulationProducts) {
    money[i] = 0;
  }
}

void Manager::SetStorage(Storage* storage) {
  storage_ = storage;
}

void Manager::Update() {
  // complite orders
  for (auto i : storage_->orders_) {
    int countIType = 0;
    for (auto j : i.second) {
      countIType += j->packageCount;
    }
    if (storage_->shelfs_[i.first]->GetPackagesCount() >= countIType) {
      for (auto j : i.second) {
        storage_->sendProduct_.push_back(j);
      }
    } else {
      int middleCount = storage_->shelfs_[i.first]->GetPackagesCount() / i.second.size();
      for (auto j : i.second) {
        if (j->packageCount > middleCount) {
          j->packageCount = middleCount;
        }
        storage_->sendProduct_.push_back(j);
      }
    }
  }

  // create orders to factory

  for (auto i : storage_->shelfs_) {
    if (i.second->GetPackagesCount() < i.second->GetMaxSize() / 2) {
      int num = 0;
      for (auto j : currentSimulationProducts) {
        if (j == i.first) break;
        ++num;
      }
      storage_->CreateOrder(num, i.second->GetMaxSize() / 2 - i.second->GetPackagesCount());
    }
  }

}

void Manager::AddMoney(Product* product) {
  money[product->GetProductName()] += product->GetProductPrice();
}

void Manager::TakeMoney(Product* product) {
  money[product->GetProductName()] -= product->GetProductPrice();
}
