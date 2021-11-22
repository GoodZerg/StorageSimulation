#include "pch.h"

struct Order {
	ICreateOrder* customer_;
	ICompleteOrder* contractor_;
	string productType;
	int packageCount;
};
