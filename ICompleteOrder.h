#pragma once

#include "pch.h"

class Order;

class ICompleteOrder {
public:
	virtual void CompleteOrder(Order*) = 0;
};