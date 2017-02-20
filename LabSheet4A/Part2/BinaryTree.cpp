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
	if (node == NULL) {
		return -1;
	}

	int left = height(node->getLeft());
	int	right = height(node->getRight());

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

/***************************************************************************************

*    Usage: Based
*    Date: 20/2/2017
*    Availability: http://www.geeksforgeeks.org/root-to-leaf-path-sum-equal-to-a-given-number/
*
***************************************************************************************/
bool BinaryTree::hasPathSum(TreeNode* root, int sum) {
	if (root == NULL) {
		return false;
	}

	int treeSum = sum - root->getData();

	if (treeSum == 0 && root->left == NULL && root->right == NULL) {
		return true;
	}

	return hasPathSum(root->left, treeSum) || hasPathSum(root->right, treeSum);
}

/***************************************************************************************

*    Usage: Based
*    Date: 20/2/2017
*    Availability: http://www.geeksforgeeks.org/given-a-binary-tree-print-all-root-to-leaf-paths/
*
***************************************************************************************/
void BinaryTree::printPathsRecur(TreeNode* root, int path[], int pathLength)
{
	if (root == NULL)
		return;

	/* append this node to the path array */
	path[pathLength] = root->data;
	pathLength++;

	/* it's a leaf, so print the path that led to here  */
	if (root->left == NULL && root->right == NULL)
	{
		int sum = 0;
		for (int i = 0; i < pathLength; i++) {
			sum += path[i];
			if (i != pathLength - 1) {
				cout << path[i] << " + ";
			}
			else {
				cout << path[i] << " = " << sum;
			}
		}
		cout << "\n";
	}
	else
	{
		printPathsRecur(root->left, path, pathLength);
		printPathsRecur(root->right, path, pathLength);
	}
}

/***************************************************************************************

*    Usage: Used
*    Date: 20/2/2017
*    Availability: http://www.geeksforgeeks.org/given-a-binary-tree-print-all-root-to-leaf-paths/
*
***************************************************************************************/
void BinaryTree::printPaths(TreeNode* root)
{
	int path[1000];
	printPathsRecur(root, path, 0);
}