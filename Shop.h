#pragma once

#include "Order.h"
#include "Storage.h"
#include "ITakePackages.h"

class Shop : public ISimulate, public ICreateOrder, public ITakePackages {
public:
	Shop(int productCount, int maxOrderSize, Storage* storage) : randCreateOrder_(0, 1), storage_(storage),
		randProductType_(0, productCount - 1), randPackageCount_(1, maxOrderSize) { }
	void Update();
	void TakePackages(Order* r);
private:
	inline static mt19937 Mt_rnd;
	void CreateOrder(int, int);
	uniform_int_distribution<> randCreateOrder_, randProductType_, randPackageCount_;
	Storage* storage_;
};
