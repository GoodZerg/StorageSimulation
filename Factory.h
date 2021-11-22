#include "pch.h"
#include "Order.h"
#include "Storage.h"

class Factory : public ISimulate, public ICompleteOrder {
public:
	Factory(Storage* storage) : storage_(storage), orders_(6), randDayCount_(1, 5) {}
	void Update();
	void AddOrder(Order*);

private:
	void CompleteOrder(Order*);
	vector<vector<Order*>> orders_;
	Storage* storage_;
	uniform_int_distribution<> randDayCount_;
};
