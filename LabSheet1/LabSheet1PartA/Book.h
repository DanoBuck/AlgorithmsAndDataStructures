// Daniel Buckley X00109141

#pragma once
#include "Product.h"

class Book : public Product {
public:
	Book();
	Book(double);
	double getGrossPrice();
};
