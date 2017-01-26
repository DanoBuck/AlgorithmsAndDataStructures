// Daniel Buckley X00109141

#include "Book.h"

Book::Book() {
	netPrice = 0;
}

Book::Book(double priceIn) {
	netPrice = priceIn;
}

// Books are free of VAT so gross price is the same as net price
double Book::getGrossPrice() {
	return netPrice;
}