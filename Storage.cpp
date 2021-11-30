#include "Storage.h"

Storage::Storage(int productNum, int shelfMaxSize, Factory* fa, ISimulate* manager) {
	for (auto i : ProductsClass) {
		shelfs_[i.first] = new Shelf(shelfMaxSize);
		orders_[i.first] = vector<Order*>();
	}
	manager_ = manager;
	factory_ = fa;
}

Storage::~Storage() {
	shelfs_.clear();
	orders_.clear();
}

void Storage::Update() {
	for (auto i: shelfs_) {
		i.second->Update();
	}
	manager_->Update();
	for (auto i : orders_) {
		i.second.clear();
	}
}

void Storage::TakeOrder(Order* order) {
	orders_[order->productType].push_back(order);
}

void Storage::TakePackages(Order* order) {
	for (int i = 0; i < order->packageCount; ++i) {
		shelfs_[order->productType]->PutPackage(new Package(ProductsClass[order->productType]));
	}
	delete order;
}

void Storage::CreateOrder(int productType, int packageCount) {
	Order* order = new Order();
	order->customer_ = this;
	order->contractor_ = factory_;
	order->productType = currentSimulationProducts[productType];
	order->packageCount = packageCount;
	factory_->AddOrder(order);
}

void Storage::CompleteOrder(Order* order) {
	dynamic_cast<ITakePackages*>(order->customer_)->TakePackages(order);
}
