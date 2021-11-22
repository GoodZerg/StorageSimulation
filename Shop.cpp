#include "Shop.h"

void Shop::Update() {
	if (!randCreateOrder_(rand))
		return;
	int productType = randProductType_(rand);
	int packageCount = randPackageCount_(rand);
	CreateOrder(productType, packageCount);
}

void Shop::CreateOrder(int productType, int packageCount) {
	Order* order = new Order();
	order->customer_ = this;
	order->contractor_ = storage_;
	order->productType = currentSimulationProducts[productType];
	order->packageCount = packageCount;
	storage_->TakeOrder(order);
}