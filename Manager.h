#pragma once

#include "Storage.h"
#include "IMoneyCount.h"

class Manager : public ISimulate, public IMoneyCount {
public:
	Manager();
	void SetStorage(Storage* storage);
	void Update();
	void AddMoney(Product*);
	void TakeMoney(Product*);
	void PrintMoney();
private:
	Storage* storage_ = nullptr;
	map<string, int> money;
};