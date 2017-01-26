// Daniel Buckley X00109141

#include <iostream>
#include <string>
#include "Product.h"
#include "Software.h"
#include "Book.h"
using namespace std;

int main() {
	// A. Declare an array of 10 pointers to Product
	Product *productArray[10];

	// B. Pointer to Software
	Software *software;

	// B. Pointer to Book
	Book *book;

	double priceIn = 0;

	// C. Create the two items dynamically and store the addresses in the pointers
	cout << "Please enter the price of the software\n";
	cin >> priceIn;

	software = new Software(priceIn);
	cout << "Software price is € " << software->getGrossPrice() << "\n";

	cout << "Please enter the price of the book\n";
	cin >> priceIn;

	book = new Book(priceIn);
	cout << "Book price is € " << book->getGrossPrice() << "\n";

	// D. Methods work correctly now to add them to the product array
	productArray[0] = software;
	productArray[1] = book;

	string choice = "";

	// E. Enter in data for the rest of the array
	for (int i = 2; i < 10; i++) {
		cout << "Please enter Book or Software as a product\n";
		cin >> choice;
		cout << "Please enter the price for the " << choice << "\n";
		cin >> priceIn;

		if (choice == "Software" || choice == "software") {
			productArray[i] = new Software(priceIn);
		}
		else if (choice == "Book" || choice == "book") {
			productArray[i] = new Book(priceIn);
		}
	}

	// F. Cycle through the array and print the gross price for all
	// The first two items do not return the price that i received up further. This is due to part of the object becoming lost.
	// This solution is not polymorphic and this is the problem with the output
	for (int i = 0; i < 10; i++) {
		cout << "Gross Price for Item " << i << " is €" << productArray[i]->getGrossPrice() << "\n";
	}

	// G. Sort the array in ascending order
	double priceHolder = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = i + 1; j < 10; j++) {
			// When greater we want to swap the twos positions - Bubble Swap Method
			if (productArray[i]->getPrice() > productArray[j]->getPrice()) {
				priceHolder = productArray[i]->getPrice();
				productArray[i]->setPrice(productArray[j]->getPrice());
				productArray[j]->setPrice(priceHolder);
			}
		}
	}

	// H. Cycle through the array and print the gross price for all
	cout << "\n**********Sorted Array**********\n";
	for (int i = 0; i < 10; i++) {
		cout << "Gross Price for Item " << i << " is €" << productArray[i]->getGrossPrice() << "\n";
	}

	system("pause");
	return 0;
}