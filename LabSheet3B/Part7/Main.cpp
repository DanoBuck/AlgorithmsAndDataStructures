#include "BinaryTree.h"
#include <iostream>
using namespace std;

void isFound(bool);

int main() {
	BinaryTree<int> tree = BinaryTree<int>();
	tree.insert(1);
	tree.insert(5);
	tree.insert(4);
	tree.insert(2);
	tree.insert(1);
	tree.printTree(tree.getRoot());
	isFound(tree.findElement(tree.getRoot(), 5)); // true
	isFound(tree.findElement(tree.getRoot(), 15)); // false
	isFound(tree.findElement(tree.getRoot(), 21)); // false
	isFound(tree.findElement(tree.getRoot(), 2)); // true

	cout << "\n";

	BinaryTree<double> tree2 = BinaryTree<double>();
	tree2.insert(1.74);
	tree2.insert(5.12);
	tree2.insert(4.21);
	tree2.insert(2.12);
	tree2.insert(1.9);
	tree2.printTree(tree2.getRoot());
	isFound(tree2.findElement(tree2.getRoot(), 5)); // false
	isFound(tree2.findElement(tree2.getRoot(), 5.12)); // true
	isFound(tree2.findElement(tree2.getRoot(), 2.12)); // true
	isFound(tree2.findElement(tree2.getRoot(), 2)); // false

	cout << "\n";

	BinaryTree<string> tree3 = BinaryTree<string>();
	tree3.insert("Daniel");
	tree3.insert("Buckley");
	tree3.insert("Binary");
	tree3.insert("Tree");
	tree3.insert("Here");
	tree3.printTree(tree3.getRoot());

	system("pause");
	return 0;
}

void isFound(bool result) {
	if (result) {
		cout << "Is Found: true\n";
	}
	else {
		cout << "Is Found: false\n";
	}
}