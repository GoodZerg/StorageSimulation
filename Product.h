#include "pch.h"

class Product : public ISimulate {
public:
	Product();
	void Update();
	~Product() = default;
private:
	string name_;
	double weight_, price_;
	int countInPackage_, lifeTime_, markdownTime_;
	int age_;
};