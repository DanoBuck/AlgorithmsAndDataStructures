#include "BinaryTree.h"
#include <iostream>
using namespace std;

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
	cout << "Min value in tree is: " << newTree.minValue() << "\n";
	cout << "Max value in tree is: " << newTree.maxValue() << "\n";
	system("pause");
	return 0;
}