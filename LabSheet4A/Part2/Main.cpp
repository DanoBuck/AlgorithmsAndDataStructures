#include "BinaryTree.h"
#include <iostream>
using namespace std;

void isThereAPath(bool, int);

int main() {
	BinaryTree newTree = BinaryTree();
	newTree.add(5);
	newTree.add(4);
	newTree.add(8);
	newTree.add(11);
	newTree.add(13);
	newTree.add(4);
	newTree.add(7);
	newTree.add(2);
	newTree.add(1);
	newTree.preorder(newTree.getRoot());

	cout << "Height of this tree is " << newTree.height() << "\n\n";

	bool hasPath = newTree.hasPathSum(newTree.getRoot(), 37);
	isThereAPath(hasPath, 37);

	hasPath = newTree.hasPathSum(newTree.getRoot(), 20);
	isThereAPath(hasPath, 20);

	hasPath = newTree.hasPathSum(newTree.getRoot(), 12);
	isThereAPath(hasPath, 12);

	hasPath = newTree.hasPathSum(newTree.getRoot(), 13);
	isThereAPath(hasPath, 13);

	cout << "\n*************** Printing Paths ***************\n";
	newTree.printPaths(newTree.getRoot());

	system("pause");
	return 0;
}

void isThereAPath(bool result, int number) {
	if (result) {
		cout << "Yes there is a path for number " << number << "\n";
	}
	else {
		cout << "No path for number " << number << "\n";
	}
}