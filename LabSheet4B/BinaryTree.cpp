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

int BinaryTree::isBST() {
	return isBST(root);
}

/***************************************************************************************
*
*    Usage: used
*    Date: 28/2/2017
*    Availability: http://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/
*
***************************************************************************************/
int BinaryTree::isBST(TreeNode *root) {
	if (root == NULL) {
		return true;
	}

	if (root->left != NULL && maxValue(root->left) > root->data) {
		return false;
	}

	if (root->right != NULL && minValue(root->right) < root->data) {
		return false;
	}

	if (!isBST(root->left) || !isBST(root->right)) {
		return false;
	}
}

int BinaryTree::isBST2() {
	return isBSTRecur(root, INT_MIN, INT_MAX);
}

/***************************************************************************************
*
*    Usage: Based
*    Date: 28/2/2017
*    Availability: http://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/
*
***************************************************************************************/
int BinaryTree::isBSTRecur(TreeNode *root, int min, int max) {
	if (root == NULL) {
		return true;
	}

	if (root->data < min || root->data > max) {
		return false;
	}

	bool left = isBSTRecur(root->left, min, root->data);
	bool right = isBSTRecur(root->right, root->data, max);

	return left && right;
}