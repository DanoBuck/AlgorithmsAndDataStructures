// Daniel Buckley
// X00109141

#pragma once
#include "Cities.h"

class TreeNode {
	friend class BinaryTree;
private:
	TreeNode *left;
	TreeNode *right;
	City city;

public:
	TreeNode();
	TreeNode(City cityIn);
	bool isLeaf();
};
