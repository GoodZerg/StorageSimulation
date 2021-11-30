#include "Shop.h"

void Shop::Update() {
	if (!randCreateOrder_(Mt_rnd))
		return;
	int productType = randProductType_(Mt_rnd);
	int packageCount = randPackageCount_(Mt_rnd);
	CreateOrder(productType, packageCount);
}

void Shop::TakePackages(Order* order) {
	delete order;
}

void Shop::CreateOrder(int productType, int packageCount) {
	Order* order = new Order();
	order->customer_ = this;
	order->contractor_ = storage_;
	order->productType = currentSimulationProducts[productType];
	order->packageCount = packageCount;
	storage_->TakeOrder(order);
}