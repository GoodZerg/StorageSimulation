#include "Product.h"

void Product::Update() {
	--age_;
}

bool Product::isFresh() {
	return age_;
}

bool Product::isRotting() {
	return age_ <= markdownTime_;
}

string Product::GetProductName() const {
	return name_;
}
