#include "BinaryTree.h"
#include <iostream>
using namespace std;

TreeNode::TreeNode() {
	data = ' ';
	left = NULL;
	right = NULL;
}

TreeNode::TreeNode(char dataIn) {
	data = dataIn;
	left = NULL;
	right = NULL;
}

BinaryTree::BinaryTree()
{
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

void BinaryTree::insert(char dataIn) {
	TreeNode *newNode = new TreeNode(dataIn);

	if (root == NULL) {
		root = newNode;
	}
	else {
		insert(newNode, root);
	}
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
	else if(newNode->data >= root->data) {
		if (root->right != NULL) {
			insert(newNode, root->right);
		}
		else {
			root->right = newNode;
		}
	}
}

bool BinaryTree::search(TreeNode *root, char searchFor) {
	bool found = false;
	if (!found && root->data != searchFor) {
		if (searchFor == root->data) {
			found = true;
			return found;
		}
		else if (root->left != NULL && searchFor < root->data) {
			search(root->left, searchFor);
		}
		else if (root->right != NULL && searchFor >= root->data) {
			search(root->right, searchFor);
		}
		else {
			found = false;
			return found;
		}
	}
}

void BinaryTree::printAscendingOrder(TreeNode *root) {
	// Printing the tree in ascending order i.e. A-Z in this case
	if (root != NULL) {
		printAscendingOrder(root->left);
		cout << root->data << "\n";
		printAscendingOrder(root->right);
	}
}
