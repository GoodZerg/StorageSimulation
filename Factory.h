#pragma once

#include "Order.h"
#include "ISimulate.h"
#include "ITakePackages.h"
	
static mt19937 Mt_rndd = mt19937(time(NULL));

class Factory : public ISimulate, public ICompleteOrder {
public:
	Factory() : orders_(6), randDayCount_(1, 5) {}
	void Update();
	void AddOrder(Order*);

private:
	void CompleteOrder(Order*);
	vector<vector<Order*>> orders_;
	uniform_int_distribution<> randDayCount_;
};
