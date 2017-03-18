#include "TreeNode.h"

TreeNode::TreeNode() {
	left = NULL;
	right = NULL;
	city = City();
}

TreeNode::TreeNode(City cityIn) {
	left = NULL;
	right = NULL;
	city = cityIn;
}

bool TreeNode::isLeaf() {
	return left == NULL && right == NULL;
}