#pragma once

#include "Storage.h"

class Manager : public ISimulate {
public:
	Manager();
	void SetStorage(Storage* storage);
	void Update();
private:
	Storage* storage_ = nullptr;
	int money = 0;
};