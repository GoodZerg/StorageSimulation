#include "Order.h"

class ICompleteOrder {
public:
	virtual void CompleteOrder(Order*) = 0;
};