#include "Product.h"

void Product::Update() {
	--age_;
}

bool Product::isFresh() const {
	return age_;
}

bool Product::isRotting() const {
	return age_ <= markdownTime_;
}

string Product::GetProductName() const {
	return name_;
}

double Product::GetProductPrice() const {
	return isRotting() ? price_ : markdownPrice_;
}

size_t Product::GetAge() const {
	return age_;
}
