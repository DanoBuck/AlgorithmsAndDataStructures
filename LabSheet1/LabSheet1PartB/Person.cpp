// Daniel Buckley X00109141

#include "Person.h"
#include <iostream>

Person::Person() {
	name = "";
}

Person::Person(string nameIn) {
	name = nameIn;
}

string Person::printname() const {
	return "My name is " + name;
}

string Person::getName() {
	return name;
}

bool Person::operator>(Person *rhs) {
	return name > rhs->name;
}