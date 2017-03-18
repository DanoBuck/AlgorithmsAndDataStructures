#include <iostream>
#include "Cities.h"
#include "BinaryTree.h"
using namespace std;

string existsInTree(bool);

int main() {
	City city1 = City("Dublin", 53.3498, 6.2603, 1000000, 10.5);
	City city2 = City("Galway", 57.123, 6.2603, 30, 10);
	City city3 = City("Cork", 49.00, 12.124, 50000, 10.5);
	City city4 = City("Sligo", 53.34981, 6.2603, 1000000, 10.5);
	City city5 = City("Donegal", 49.00, 12.124, 1200, 10.5);
	City city6 = City("Dublin", 53.312498, 6.26121203, 1000000, 10.5);

	BinaryTree newTree = BinaryTree();
	newTree.insert(city1);
	newTree.insert(city2);
	newTree.insert(city3);
	newTree.insert(city4);
	newTree.insert(city5);
	newTree.insert(city6);

	cout << "**********Pre Order**********\n";
	newTree.printPreOrder(newTree.getRoot());

	cout << "\n**********In Order**********\n";
	newTree.printInOrder(newTree.getRoot());

	cout << "\n**********Post Order**********\n";
	newTree.printPostOrder(newTree.getRoot());

	cout << "\nHeight of this tree is: " << newTree.height() << "\n";

	cout << "\nSearching for  53.3498, 6.2603: " << existsInTree(newTree.searchByCoordinate({ 53.3498, 6.2603 })) << "\n";
	cout << "\nSearching for  53.34111111198, 6.2603: " << existsInTree(newTree.searchByCoordinate({ 34111111198, 6.2603 })) << "\n";
	cout << "\Searching for Galway: " << existsInTree(newTree.searchByName("Galway")) << "\n";
	cout << "\Searching for sky: " << existsInTree(newTree.searchByName("sky")) << "\n";

	cout << "Deleting Cork by coordinates 49.00, 12.124: " << existsInTree(newTree.deleteByCoordinates({ 49.00, 12.124 })) << "\n";
	cout << "Deleting Dublin by coordinates 53.312498, 6.26121203: " << existsInTree(newTree.deleteByCoordinates({ 53.312498, 6.26121203 })) << "\n";
	cout << "Deleting City which doesn't exist by coordinates 53.312498, 6.26121203: " << existsInTree(newTree.deleteByCoordinates({ 0, 0 })) << "\n";
	cout << "Deleting Dublin by name: " << existsInTree(newTree.deleteByName("Dublin")) << "\n";
	cout << "Deleting City which doesn't exist by name: " << existsInTree(newTree.deleteByName("assddsds")) << "\n";
	cout << "\n**********In Order**********\n";
	newTree.printInOrder(newTree.getRoot());

	system("pause");
	return 0;
}

string existsInTree(bool exists) {
	if (exists) {
		return "Yes";
	}
	else {
		return "No";
	}
}