#include "pch.h"

class Product : public ISimulate {
public:
	Product(string name, double weight, double price, double markdownPrice,
		size_t countInPackage, size_t lifetime, size_t markdownTime) :
		name_(name), weight_(weight), price_(price), markdownPrice_(markdownPrice), age_(lifetime),
		countInPackage_(countInPackage), lifeTime_(lifetime), markdownTime_(markdownTime) {}
	void Update();
	~Product() = default;
	bool isFresh();
	bool isRotting();

private:
	string name_;
	double weight_, price_, markdownPrice_;
	size_t countInPackage_, lifeTime_, markdownTime_;
	size_t age_;
};