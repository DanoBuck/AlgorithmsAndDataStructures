#include "BinaryTree.h"
#include <iostream>
using namespace std;

BinaryTree::BinaryTree() {
	root = NULL;
}

BinaryTree::~BinaryTree() {
	destroy(root);
}

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
	int left = 0;
	int right = 0;
	if (node->getLeft() != NULL) {
		left = height(node->getLeft());
	}
	else if (node->getRight() != NULL) {
		right = height(node->getRight());
	}

	if (left > right) {
		return left + 1;
	}
	else {
		return right + 1;
	}
}

int BinaryTree::height() {
	if (root == NULL) {
		return -1;
	}

	return height(root);
}