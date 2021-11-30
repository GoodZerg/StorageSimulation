#include "Manager.h"

Manager::Manager() { }

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
        storage_->CompleteOrder(j);
      }
    } else {
      
    }
  }

  // create orders to factory
}
