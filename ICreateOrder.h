#pragma once

#include "pch.h"

class ICreateOrder {
public:
	virtual void CreateOrder(int, int) = 0;
};