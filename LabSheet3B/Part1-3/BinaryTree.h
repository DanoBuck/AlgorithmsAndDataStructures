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
};
