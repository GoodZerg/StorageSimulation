#include "pch.h"
#include "Package.h"

class Shelf : public ISimulate {
public:
	Shelf(int maxSize) : maxSize_(maxSize), packages_() {}
	void Update();
	bool isFull() const;
	void PutPackage(Package*);
	Package* TakePackage();
	int GetPackagesCount() const;
	~Shelf() = default;

private:
	priority_queue<Package*> packages_;
	int maxSize_;
};