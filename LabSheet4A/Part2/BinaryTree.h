#pragma once
#include "TreeNode.h"

class BinaryTree {
private:
	TreeNode *root;

	void add(TreeNode*, TreeNode*);
	int height(TreeNode*);
public:
	BinaryTree();
	~BinaryTree();
	void destroy(TreeNode*);
	void add(int);
	void preorder(TreeNode*);
	TreeNode* getRoot();
	int height();

	// LabSheet 4A Methods
	bool hasPathSum(TreeNode*, int);
	void printPathsRecur(TreeNode*, int[], int);
	void printPaths(TreeNode*);
};
