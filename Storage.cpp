#include "Storage.h"

Storage::Storage(int productNum, int shelfMaxSize, Factory* fa, ISimulate* manager) {
	for (auto i : ProductsClass) {
		shelfs_[i.first] = new Shelf(shelfMaxSize);
		for (; !shelfs_[i.first]->isFull();) {
			shelfs_[i.first]->PutPackage(new Package(i.second));
		}
		orders_[i.first] = vector<Order*>();
	}

	for (auto i : shelfs_) {
		std::cout << i.first << ": " << i.second->GetPackagesCount() << "\n";
	}
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";

	manager_ = manager;
	factory_ = fa;
}

Storage::~Storage() {
	shelfs_.clear();
	orders_.clear();
}

void Storage::Update() {

	for (auto i : shelfs_) {
		std::cout << i.first << ": " << i.second->GetPackagesCount() << "\n";
	}
	std::cout << "\n";


	for (auto i: shelfs_) {
		i.second->Update();
	}
	manager_->Update();
	for (auto i : sendProduct_) {
		CompleteOrder(i);
	}
	sendProduct_.clear();



	for (auto i : orders_) {
		i.second.clear();
	}
	orders_.clear();
}

void Storage::TakeOrder(Order* order) {
	orders_[order->productType].push_back(order);
}

void Storage::TakePackages(Order* order) {
	for (int i = 0; i < order->packageCount; ++i) {
		auto pack = new Package(ProductsClass[order->productType]);
		dynamic_cast<IMoneyCount*>(manager_)->TakeMoney(&pack->product_);
		shelfs_[order->productType]->PutPackage(pack);
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
	for (int i = 0; i < order->packageCount; i++) {
		dynamic_cast<IMoneyCount*>(manager_)->AddMoney(&shelfs_[order->productType]->TakePackage()->product_);
	}
	dynamic_cast<ITakePackages*>(order->customer_)->TakePackages(order);
}
