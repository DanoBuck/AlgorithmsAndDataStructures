#include "BinaryTree.h"
#include <iostream>
using namespace std;

BinaryTree::BinaryTree() {
	root = NULL;
}

BinaryTree::~BinaryTree() {
	destroy(root);
}

void BinaryTree::destroy(TreeNode* root) {
	if (root != NULL) {
		destroy(root->left);
		destroy(root->right);
		delete root;
	}
}

void BinaryTree::insert(City city) {
	TreeNode *newNode = new TreeNode(city);
	if (root == NULL) {
		root = newNode;
		return;
	}
	insert(newNode, root);
}

void BinaryTree::insert(TreeNode *newNode, TreeNode *root) {
	bool alreadyExists = search(root, { newNode->city.coordinates.first, newNode->city.coordinates.second });
	if (!alreadyExists) {
		if (newNode->city.city < root->city.city) {
			if (root->left != NULL) {
				insert(newNode, root->left);
			}
			else {
				root->left = newNode;
			}
		}
		else if (newNode->city.city > root->city.city) {
			if (root->right != NULL) {
				insert(newNode, root->right);
			}
			else {
				root->right = newNode;
			}
		}
	}
}

void BinaryTree::printPreOrder(TreeNode *root) {
	if (root != NULL) {
		cout << root->city;
		printPreOrder(root->left);
		printPreOrder(root->right);
	}
}

void BinaryTree::printInOrder(TreeNode *root) {
	if (root != NULL) {
		printInOrder(root->left);
		cout << root->city;
		printInOrder(root->right);
	}
}

void BinaryTree::printPostOrder(TreeNode *root) {
	if (root != NULL) {
		printPostOrder(root->left);
		printPostOrder(root->right);
		cout << root->city;
	}
}

int BinaryTree::height() {
	return height(root);
}

int BinaryTree::height(TreeNode *node) {
	if (node == NULL) {
		return -1;
	}

	int left = height(node->left);
	int	right = height(node->right);

	if (left > right) {
		return left + 1;
	}
	else {
		return right + 1;
	}
}

bool BinaryTree::search(TreeNode *root, pair<double, double> searchFor) {
	bool found = false;
	if (!found && root->city.coordinates.first != searchFor.first && root->city.coordinates.first != searchFor.second) {
		if (searchFor.first == root->city.coordinates.first && searchFor.second == root->city.coordinates.second) {
			found = true;
			return found;
		}
		else if (root->left != NULL && searchFor < root->city.coordinates) {
			search(root->left, searchFor);
		}
		else if (root->right != NULL && searchFor >= root->city.coordinates) {
			search(root->right, searchFor);
		}
		else {
			found = false;
			return found;
		}
	}
}