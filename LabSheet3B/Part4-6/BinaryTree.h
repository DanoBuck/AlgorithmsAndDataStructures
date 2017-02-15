#pragma once

class TreeNode {
	friend class BinaryTree;
private:
	TreeNode *left;
	TreeNode *right;
	char data;
public:
	TreeNode();
	TreeNode(char);
};

class BinaryTree
{
private:
	TreeNode *root;
	void insert(TreeNode *, TreeNode *);

public:
	BinaryTree();
	~BinaryTree();
	void destroy(TreeNode*);
	void insert(char);
	bool search(TreeNode *, char);
	TreeNode* getRoot() { return root; }
	void printAscendingOrder(TreeNode *);
};