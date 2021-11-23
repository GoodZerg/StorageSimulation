#include "Shelf.h"

void Shelf::Update() {
	Package* temp;
	priority_queue<Package*> newPackages;
	while (true) {
		temp = TakePackage();
		if (temp == nullptr)
			break;
		if (!temp->product_.isFresh()) {
			delete temp;
			continue;
		}
		newPackages.push(temp);
	}
	packages_ = newPackages;
}

bool Shelf::isFull() const {
	return packages_.size() < maxSize_;
}

void Shelf::PutPackage(Package* newPackage) {
	if(!isFull())
		packages_.push(newPackage);
}

Package* Shelf::TakePackage() {
	if (!packages_.size())
		return nullptr;
	Package* package = packages_.top();
	packages_.pop();
	return package;
}

int Shelf::GetPackagesCount() const {
	return packages_.size();
}
