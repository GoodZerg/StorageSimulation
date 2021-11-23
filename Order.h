#pragma once

#include "ICreateOrder.h"
#include "ICompleteOrder.h"

class Order {
public:
	ICreateOrder* customer_;
	ICompleteOrder* contractor_;
	string productType;
	int packageCount;
};
