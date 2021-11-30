#pragma once

#include "ISimulate.h"

class Product : public ISimulate {
public:
	Product() = default;
	Product(string name, double weight, double price, double markdownPrice,
		size_t countInPackage, size_t lifetime, size_t markdownTime) :
		name_(name), weight_(weight), price_(price), markdownPrice_(markdownPrice), age_(lifetime),
		countInPackage_(countInPackage), lifeTime_(lifetime), markdownTime_(markdownTime) {}
	void Update();
	~Product() = default;
	bool isFresh();
	bool isRotting();
	string GetProductName() const;
private:
	string name_ = 0;
	double weight_ = 0, price_ = 0, markdownPrice_ = 0;
	size_t countInPackage_ = 0, lifeTime_ = 0, markdownTime_ = 0;
	size_t age_ = 0;
};

static map<string, Product> ProductsClass = {
	{"Говно", Product("Говно", 1.2, 10, 8, 10, 4, 2) },
	{"Моча",  Product("Моча", 1.2, 10, 8, 10, 4, 2) }
};


