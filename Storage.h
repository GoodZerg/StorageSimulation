#pragma once

#include "Shelf.h"
#include "Package.h"
#include "Product.h"
#include "Order.h"
#include "Factory.h"
#include "ITakePackages.h"
#include "IMoneyCount.h"

class Storage : public ISimulate, public ICreateOrder, public ICompleteOrder, public ITakePackages {
public:
	friend class Manager;
	Storage(int productNum, int shelfMaxSize, Factory* fa, ISimulate* manager);
	~Storage();
	void Update();
	void TakeOrder(Order*);
	void TakePackages(Order*);
private:
	void CreateOrder(int productType, int packageCount);
	void CompleteOrder(Order*);
	map<string, Shelf*> shelfs_;
	map<string, vector<Order*>> orders_;
	vector<Order*> sendProduct_;
	ISimulate* manager_;
	Factory* factory_;
};
