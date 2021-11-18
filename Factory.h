#include "pch.h"

class Factory : public ISimulate, public ICompleteOrder {
public:
	Factory() = default;
	void Update();

private:
	void CompleteOrder();
};
