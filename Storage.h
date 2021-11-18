#include "pch.h"

#include "Shelf.h"
#include "Package.h"
#include "Product.h"

class Storage : public ISimulate, public ICreateOrder, public ICompleteOrder {
public:
	Storage();
	void Update();
private:
	void CreateOrder();
	void CompleteOrder();
	map<Product*, Shelf*> shelfs_;

};
