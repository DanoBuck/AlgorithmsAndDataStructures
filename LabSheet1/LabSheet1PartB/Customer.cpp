// Daniel Buckley X00109141

#include "Customer.h"
#include <iostream>

Customer::Customer() : Person("") {
	message = "";
}

Customer::Customer(string nameIn, string messageIn) : Person(nameIn) {
	message = messageIn;
}

string Customer::printname() const {
	return Person::printname() + " " + message;
}