#include "pch.h"
#include "Package.h"

class Shelf : public ISimulate {
public:
	Shelf();
	void Update();
	bool isFull();
	void PutPackage(Package*);
	Package* TakePackage();
	~Shelf() = default;

private:
	priority_queue<Package*> content_;
	int maxSize_;
};