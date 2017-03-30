#pragma once
#include "TreeNode.h"


class BinaryTree {
private:
	TreeNode *root;
	void insert(TreeNode *, TreeNode *);
	int height(TreeNode*);
	bool searchByCoordinate(TreeNode*, pair<double, double>);
	bool searchByName(TreeNode*, string);
	TreeNode* deleteByName(string, TreeNode *, TreeNode *);
	TreeNode* deleteByNameAndCoordinates(string, pair<double, double>, TreeNode *, TreeNode *);
	TreeNode* getMin(TreeNode*);
	TreeNode* findCityByCoordinates(pair<double, double>, TreeNode*);
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
	TreeNode* findCityByCoordinates(pair<double, double>);
	bool deleteByCoordinatesHelper(pair<double, double>);
	bool deleteByNameAndCoordinates(string, pair<double, double>);
	bool deleteByName(string);
};