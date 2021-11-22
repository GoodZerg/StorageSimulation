#include "pch.h"
#include "Order.h"
#include "Storage.h"

class Shop : public ISimulate, public ICreateOrder {
public:
	Shop(int productCount, Storage* storage) : randCreateOrder_(0, 1), storage_(storage),
		randProductType_(0, productCount - 1), randPackageCount_(1, 5) { }
	void Update();

private:
	void CreateOrder(int, int);
	uniform_int_distribution<> randCreateOrder_, randProductType_, randPackageCount_;
	Storage* storage_;
};
