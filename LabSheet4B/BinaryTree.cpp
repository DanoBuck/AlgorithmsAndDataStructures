#include "BinaryTree.h"
#include <iostream>
using namespace std;

TreeNode::TreeNode() {
	right = NULL;
	left = NULL;
	data = 0;
}

TreeNode::TreeNode(int dataIn) {
	right = NULL;
	left = NULL;
	data = dataIn;
}

BinaryTree::BinaryTree() {
	root = NULL;
}

void BinaryTree::insert(TreeNode *newNode, TreeNode *root) {
	if (newNode->data < root->data) {
		if (root->left != NULL) {
			insert(newNode, root->left);
		}
		else {
			root->left = newNode;
		}
	}
	else if (newNode->data >= root->data) {
		if (root->right != NULL) {
			insert(newNode, root->right);
		}
		else {
			root->right = newNode;
		}
	}
}

void BinaryTree::insert(int data) {
	TreeNode *newNode = new TreeNode(data);
	if (root == NULL) {
		root = newNode;
	}
	else {
		insert(newNode, root);
	}
}

void BinaryTree::print(TreeNode *root) {
	if (root != NULL) {
		cout << root->data << "\n";
		print(root->left);
		print(root->right);
	}
}

TreeNode* BinaryTree::getRoot() {
	return root;
}

int BinaryTree::minValue(TreeNode *root) {
	if (root->left != NULL) {
		return minValue(root->left);
	}
	return root->data;
}

int BinaryTree::minValue() {
	if (root == NULL) {
		return -1;
	}
	return (minValue(root));
}

int BinaryTree::maxValue(TreeNode *root) {
	if (root->right != NULL) {
		return maxValue(root->right);
	}
	return root->data;
}

int BinaryTree::maxValue() {
	if (root == NULL) {
		return -1;
	}
	return (maxValue(root));
}