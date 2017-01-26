// Daniel Buckley X00109141

#include "Product.h"

Product::Product() {
	netPrice = 0;
}

Product::Product(double priceIn) {
	netPrice = priceIn;
}

double Product::getGrossPrice() {
	return netPrice * 1.21;
}

double Product::getPrice() {
	return netPrice;
}

void Product::setPrice(double priceIn) {
	netPrice = priceIn;
}