// Daniel Buckley X00109141

#include "Customer.h"
#include "Employee.h"
#include <iostream>

void printArray(Person*[]);

int main() {
	// ********* 1st Version of Program When Person is not Abstract *********
	/*Person *personPtr = new Person("Mark");
	cout << personPtr->printname() << "\n";

	personPtr = new Employee("Tom", 34000.00);
	cout << personPtr->printname() << "\n";

	personPtr = new Customer("Ed", "and I want to make a complaint\n");
	cout << personPtr->printname() << "\n";*/

	// ********* 2nd Version of Program When Person is Abstract *********
	Employee *employee = new Employee("Tom", 34000.00);
	cout << employee->printname() << "\n";

	Customer *customer = new Customer("Ed", "and I want to make a complaint");
	cout << customer->printname() << "\n";

	Person *peopleArray[6];
	peopleArray[0] = employee;
	peopleArray[1] = customer;
	peopleArray[2] = new Employee("Alison", 20000);
	peopleArray[3] = new Employee("Albert", 5000);
	peopleArray[4] = new Customer("Donal", "and I want to make a complaint");
	peopleArray[5] = new Customer("Daniel", "and I want to make a complaint");

	cout << "\nArray unsorted\n\n";
	printArray(peopleArray);

	// Create a duplicate of the unsorted values which are
	// used later on for sorting without overloaded operators
	Person *duplicateUnsortedArray[6];
	for (int i = 0; i < 6; i++) {
		duplicateUnsortedArray[i] = peopleArray[i];
	}

	// Now using operator overloading to sort the array from A-Z order
	Person *personHolder;
	for (int i = 0; i < 6; i++) {
		for (int j = i + 1; j < 6; j++) {
			if (peopleArray[i]->operator>(peopleArray[j])) {
				personHolder = peopleArray[i];
				peopleArray[i] = peopleArray[j];
				peopleArray[j] = personHolder;
			}
		}
	}

	cout << "\nArray sorted using operator overloading\n\n";
	printArray(peopleArray);

	for (int i = 0; i < 6; i++) {
		for (int j = i + 1; j < 6; j++) {
			if (duplicateUnsortedArray[i]->getName() > duplicateUnsortedArray[j]->getName()) {
				personHolder = duplicateUnsortedArray[i];
				duplicateUnsortedArray[i] = duplicateUnsortedArray[j];
				duplicateUnsortedArray[j] = personHolder;
			}
		}
	}

	cout << "\nArray sorted not using operator overloading\n\n";
	printArray(duplicateUnsortedArray);

	system("pause");
	return(0);
}

void printArray(Person* peopleArray[]) {
	for (int i = 0; i < 6; i++) {
		cout << peopleArray[i]->printname() << "\n";
	}
}