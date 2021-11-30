#pragma once

#include "Order.h"

class ITakePackages {
public:
	virtual void TakePackages(Order*) = 0;
};