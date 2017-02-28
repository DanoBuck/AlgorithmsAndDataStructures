#include "BinaryTree.h"
#include <iostream>
#include <string>
using namespace std;

string isBST(bool);

int main() {
	BinaryTree newTree = BinaryTree();
	newTree.insert(50);
	newTree.insert(25);
	newTree.insert(75);
	newTree.insert(12);
	newTree.insert(50);
	newTree.insert(4);
	newTree.insert(25);
	newTree.insert(750);
	newTree.insert(12);
	newTree.print(newTree.getRoot());
	bool isBinarySearchTree = newTree.isBST();
	cout << "Min value in tree is: " << newTree.minValue() << "\n";
	cout << "Max value in tree is: " << newTree.maxValue() << "\n";
	cout << "Is this a binary search tree: " << isBST(isBinarySearchTree) << "\n";
	isBinarySearchTree = newTree.isBST2();
	cout << "Is this a binary search tree part 2: " << isBST(isBinarySearchTree) << "\n";
	system("pause");
	return 0;
}

string isBST(bool result) {
	if (result) {
		return "yes";
	}
	return "no";
}