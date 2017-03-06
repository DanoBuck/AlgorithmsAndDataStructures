#include <iostream>
#include "Cities.h"
#include "BinaryTree.h"
using namespace std;

int main() {
	City city1 = City("Dublin", 53.3498, 6.2603, 1000000, 10.5);
	City city2 = City("Galway", 57.123, 6.2603, 30, 10);
	City city3 = City("Cork", 49.00, 12.124, 50000, 10.5);
	City city4 = City("Sligo", 53.34981, 6.2603, 1000000, 10.5);
	City city5 = City("Donegal", 49.00, 12.124, 1200, 10.5);

	BinaryTree newTree = BinaryTree();
	newTree.insert(city1);
	newTree.insert(city2);
	newTree.insert(city3);
	newTree.insert(city4);
	newTree.insert(city5);

	cout << "**********Pre Order**********\n";
	newTree.printPreOrder(newTree.getRoot());

	cout << "\n**********In Order**********\n";
	newTree.printInOrder(newTree.getRoot());

	cout << "\n**********Post Order**********\n";
	newTree.printPostOrder(newTree.getRoot());

	cout << "\nHeight of this tree is: " << newTree.height() << "\n";

	bool isfound = newTree.search(newTree.getRoot(), { 53.3498, 6.2603 });
	cout << "\nSearching for: " << isfound << "\n";
	system("pause");
	return 0;
}