#include "pch.h"

class Shop : public ISimulate, public ICreateOrder {
public:
	Shop(int productCount) : randCreateOrder_(0, 1), randProductType_(0, N),  { }
	void Update();
private:
	void CreateOrder();
	uniform_int_distribution<> randCreateOrder_, randProductType_, randPackageCount_;
};
