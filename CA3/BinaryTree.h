#pragma once
#include "TreeNode.h"


class BinaryTree {
private:
	TreeNode *root;
	void insert(TreeNode *, TreeNode *);
	int height(TreeNode*);
	bool searchByCoordinate(TreeNode*, pair<double, double>);
	bool searchByName(TreeNode*, string);
	TreeNode* deleteByCoordinates(pair<double, double>, TreeNode *,TreeNode *);
	TreeNode* deleteByName(string, TreeNode *, TreeNode *);
	TreeNode* getMin(TreeNode*);
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
	bool searchByCoordinate(pair<double, double>);
	bool searchByName(string);
	bool deleteByCoordinates(pair<double, double>);
	bool deleteByName(string);
};