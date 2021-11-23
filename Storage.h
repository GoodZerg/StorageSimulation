#pragma once

#include "Shelf.h"
#include "Package.h"
#include "Product.h"
#include "Order.h"
#include "Manager.h"

class Storage : public ISimulate, public ICreateOrder, public ICompleteOrder {
public:
	Storage();
	~Storage();
	void Update();
	void TakeOrder(Order*);
private:
	void CreateOrder(int, int);
	void CompleteOrder(Order*);
	map<string, Shelf*> shelfs_;
	map<string, vector<Order*>> orders_;
	Manager manager_;
};
