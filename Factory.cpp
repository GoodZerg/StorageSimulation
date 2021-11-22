#include "Factory.h"

void Factory::AddOrder(Order* order) {
	int completionPeriod = randDayCount_(rand);
	orders_[completionPeriod].push_back(order);
}

void Factory::Update() {
	for (int i = 0; i < 5; ++i) {
		orders_[i] = orders_[i + 1];
	}
	orders_[5].clear();
	for (Order* i : orders_[0]) {

	}
}

void Factory::CompleteOrder(Order* order) {

}