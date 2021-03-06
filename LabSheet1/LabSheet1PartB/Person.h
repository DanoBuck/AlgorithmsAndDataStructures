// Daniel Buckley X00109141

#pragma once
#include <string>
#include <iostream>
using namespace std;

// Non abstract Person class
/*class Person {
protected:
	string name;
public:
	Person();
	Person(string);
	// Virtual creates an extra field that we do not see. This field points to
	// a virtual function table which holds the location of the code which is needed to run for the
	// correct object
	virtual string printname();
};*/

// Abstract Person Class - Difference is that an object of type Person cannot be instantiated of type Person
class Person {
private:
	string name;
public:
	explicit
	Person();
	Person(string);
	virtual string printname() const = 0;
	string getName();
	bool operator >(Person*);
};