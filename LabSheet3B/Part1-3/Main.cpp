#include "BinaryTree.h"
#include <iostream>
using namespace std;

int main() {
	BinaryTree newTree = BinaryTree();
	newTree.add(5);
	newTree.add(10);
	newTree.add(9);
	newTree.add(8);
	newTree.add(122);
	newTree.add(35);
	newTree.add(47);
	newTree.add(23);
	newTree.add(1);
	newTree.add(2);
	newTree.preorder(newTree.getRoot());

	cout << "Height of this tree is " << newTree.height() << "\n";

	system("pause");
	return 0;
}