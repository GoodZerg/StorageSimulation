#pragma once

#include "Package.h"

class Shelf : public ISimulate {
public:
	Shelf(int maxSize) : maxSize_(maxSize), packages_() {}
	void Update();
	bool isFull() const;
	void PutPackage(Package*);
	Package* TakePackage();
	int GetPackagesCount() const;
	int GetMaxSize() const;
	~Shelf() = default;

private:
	struct comp {
		bool operator()(Package* left, Package* right) {
			return left->product_.GetAge() < right->product_.GetAge();
		}
	};
	priority_queue < Package*, vector<Package*>, comp > packages_;
	int maxSize_;
};