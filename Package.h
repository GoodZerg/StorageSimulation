#include "pch.h"
#include "Product.h"

class Package : ISimulate {
public:
	Package(Product product) : product_(product) {}

	void Update() {
		product_.Update();
	}

	~Package() = default;

	Product product_;
};