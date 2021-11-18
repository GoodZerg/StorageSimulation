#include "pch.h"
#include "Product.h"

class Package : ISimulate {
public:
	Package();
	void Update();
	~Package() {
		delete product_;
	}

private:
	Product* product_;
};