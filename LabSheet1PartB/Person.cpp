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