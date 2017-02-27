#pragma once

class TreeNode {
	friend class BinaryTree;
private:
	int data;
	TreeNode *right;
	TreeNode *left;

public:
	TreeNode();
	TreeNode(int);
};

class BinaryTree {
private:
	TreeNode *root;
	void insert(TreeNode*, TreeNode*);
	int minValue(TreeNode*);
	int maxValue(TreeNode*);
public:
	BinaryTree();
	void insert(int);
	void print(TreeNode*);
	TreeNode* getRoot();
	int minValue();
	int maxValue();
};