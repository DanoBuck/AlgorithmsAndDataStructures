#include "BinaryTree.h"
#include <iostream>
using namespace std;

BinaryTree::BinaryTree() {
	root = NULL;
}

/***************************************************************************************

*    Usage: Used
*    Date: 15/2/2017
*    Availability: http://stackoverflow.com/questions/34170164/destructor-for-binary-search-tree 
*
***************************************************************************************/
BinaryTree::~BinaryTree() {
	destroy(root);
}

/***************************************************************************************

*    Usage: Used
*    Date: 15/2/2017
*    Availability: http://stackoverflow.com/questions/34170164/destructor-for-binary-search-tree 
*
***************************************************************************************/
void BinaryTree::destroy(TreeNode *root) {
	if (root != NULL) {
		destroy(root->left);
		destroy(root->right);
		delete root;
	}
}

void BinaryTree::preorder(TreeNode *node) {

	if (node != NULL) {
		cout << node->getData() << "\n";
		preorder(node->getLeft());
		preorder(node->getRight());
	}
}

TreeNode* BinaryTree::getRoot() {
	return root;
}

void BinaryTree::add(TreeNode *nodeToAdd, TreeNode *root) {
	if (nodeToAdd->getData() < root->getData()) {
		if (root->getLeft() != NULL) {
			add(nodeToAdd, root->getLeft());
		}
		else {
			root->left = nodeToAdd;
		}
	}
	else if (nodeToAdd->getData() >= root->getData()) {
		if (root->getRight() != NULL) {
			add(nodeToAdd, root->getRight());
		}
		else {
			root->right = nodeToAdd;
		}
	}
}

void BinaryTree::add(int dataIn) {
	TreeNode *newNode = new TreeNode(dataIn);

	if (root != NULL) {
		add(newNode, root);
	}
	else {
		root = newNode;
	}
}

int BinaryTree::height(TreeNode *node) {
	if (root == NULL) {
		return -1;
	}
	
	int left = height(node->getLeft());
	int right = height(node->getRight());

	if (left > right) {
		return left + 1;
	}
	else {
		return right + 1;
	}
}

int BinaryTree::height() {
	return height(root);
}