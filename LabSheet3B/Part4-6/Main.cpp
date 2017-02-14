#include <iostream>
#include "BinaryTree.h"
using namespace std;

void printFindings(bool, char);

int main() {
	BinaryTree newTree = BinaryTree();
	newTree.insert('D');
	newTree.insert('A');
	newTree.insert('N');
	newTree.insert('I');
	newTree.insert('E');
	newTree.insert('L');
	newTree.insert('B'); 
	newTree.insert('U');
	newTree.insert('C');
	newTree.insert('K');
	newTree.insert('L');
	newTree.insert('E');
	newTree.insert('Y');

	printFindings(newTree.search(newTree.getRoot(), 'F'), 'F');
	printFindings(newTree.search(newTree.getRoot(), 'N'), 'N');
	printFindings(newTree.search(newTree.getRoot(), 'A') , 'A');
	printFindings(newTree.search(newTree.getRoot(), '1'), '1');
	printFindings(newTree.search(newTree.getRoot(), 'B'), 'B');

	newTree.printAscendingOrder(newTree.getRoot());

	system("pause");
	return 0;
}

void printFindings(bool result, char letter) {
	if (result) {
		cout << "Is " << letter << " Found : true \n";
	}
	else {
		cout << "Is " << letter << " Found : false \n";
	}
}