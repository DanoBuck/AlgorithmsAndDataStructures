// Daniel Buckley X00109141

#pragma once

class Product {
protected:
	double netPrice;

public:
	Product();
	Product(double);
	double getGrossPrice();
	double getPrice();
	void setPrice(double);

};