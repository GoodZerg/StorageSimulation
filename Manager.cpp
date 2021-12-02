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

  storage_->excelEditor_->WriteText(1, L"Выполненные заказы (после обработки менеджером)");
  storage_->excelEditor_->NextRaw();
  storage_->excelEditor_->WriteText(1, L"Тип товара");
  storage_->excelEditor_->WriteText(2, L"Количество");
  storage_->excelEditor_->NextRaw();

  for (auto i : storage_->sendProduct_) {
    storage_->excelEditor_->WriteText(1, wstring(i->productType.begin(), i->productType.end()));
    storage_->excelEditor_->WriteText(2, std::to_wstring(i->packageCount));
    storage_->excelEditor_->NextRaw();
  }

  storage_->excelEditor_->NextRaw();
  storage_->excelEditor_->NextRaw();

  // create orders to factory

  storage_->excelEditor_->WriteText(1, L"Заказы к фабрике отправленные сегодня");
  storage_->excelEditor_->NextRaw();
  storage_->excelEditor_->WriteText(1, L"Тип товара");
  storage_->excelEditor_->WriteText(2, L"Количество");
  storage_->excelEditor_->NextRaw();

  for (auto i : storage_->shelfs_) {
    if (i.second->GetPackagesCount() < i.second->GetMaxSize() / 2) {
      int num = 0;
      for (auto j : currentSimulationProducts) {
        if (j == i.first) break;
        ++num;
      }
      if (storage_->waitingFromFactory_.count(currentSimulationProducts[num])) {
        break;
      }
      storage_->excelEditor_->WriteText(1, wstring(currentSimulationProducts[num].begin(), 
        currentSimulationProducts[num].end()));
      storage_->excelEditor_->WriteText(2, std::to_wstring(i.second->GetMaxSize() / 2 - 
        i.second->GetPackagesCount()));
      storage_->excelEditor_->NextRaw();
      for (int j = 0; j < i.second->GetMaxSize() / 2 - i.second->GetPackagesCount(); ++j) {
        TakeMoney(&ProductsClass[currentSimulationProducts[num]]);
      }
      storage_->waitingFromFactory_.insert(currentSimulationProducts[num]);
      storage_->CreateOrder(num, i.second->GetMaxSize() / 2 - i.second->GetPackagesCount());
    }
  }
  storage_->excelEditor_->NextRaw();
  storage_->excelEditor_->NextRaw();
}

void Manager::AddMoney(Product* product) {
  money[product->GetProductName()] += product->GetProductPrice();
}

void Manager::TakeMoney(Product* product) {
  money[product->GetProductName()] -= product->GetProductPrice();
}

void Manager::PrintMoney() {
  storage_->excelEditor_->WriteText(1, L"Прибль за сегодня");
  storage_->excelEditor_->NextRaw();
  storage_->excelEditor_->WriteText(1, L"Тип товара");
  storage_->excelEditor_->WriteText(2, L"Прибль");
  storage_->excelEditor_->NextRaw();

  for (auto i : money) {
    storage_->excelEditor_->WriteText(1, wstring(i.first.begin(), i.first.end()));
    storage_->excelEditor_->WriteText(2, std::to_wstring(i.second));
    storage_->excelEditor_->NextRaw();
  }

  storage_->excelEditor_->NextRaw();
  storage_->excelEditor_->NextRaw();

  for (auto i : currentSimulationProducts) {
    money[i] = 0;
  }
}
