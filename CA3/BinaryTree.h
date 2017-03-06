#pragma once
#include "TreeNode.h"


class BinaryTree {
private:
	TreeNode *root;
	void insert(TreeNode *, TreeNode *);
	int height(TreeNode*);
public:
	BinaryTree();
	~BinaryTree();
	void destroy(TreeNode *);
	void insert(City);
	void printPreOrder(TreeNode *);
	void printInOrder(TreeNode *);
	void printPostOrder(TreeNode *);
	TreeNode* getRoot() { return root; };
	int height();
	bool search(TreeNode*, pair<double, double>);
};