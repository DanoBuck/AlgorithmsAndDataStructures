#include "BinaryTree.h"
#include <iostream>
using namespace std;

BinaryTree::BinaryTree() {
	root = NULL;
}

BinaryTree::~BinaryTree() {
	destroy(root);
}

void BinaryTree::destroy(TreeNode* root) {
	if (root != NULL) {
		destroy(root->left);
		destroy(root->right);
		delete root;
	}
}

void BinaryTree::insert(City city) {
	TreeNode *newNode = new TreeNode(city);
	if (root == NULL) {
		root = newNode;
		return;
	}
	insert(newNode, root);
}

void BinaryTree::insert(TreeNode *newNode, TreeNode *root) {
	bool alreadyExists = searchByCoordinate(root, { newNode->city.coordinates.first, newNode->city.coordinates.second });
	if (!alreadyExists) {
		if (newNode->city.city <= root->city.city) {
			if (root->left != NULL) {
				insert(newNode, root->left);
			}
			else {
				root->left = newNode;
			}
		}
		else if (newNode->city.city > root->city.city) {
			if (root->right != NULL) {
				insert(newNode, root->right);
			}
			else {
				root->right = newNode;
			}
		}
	}
}

void BinaryTree::printPreOrder(TreeNode *root) {
	if (root != NULL) {
		cout << root->city;
		printPreOrder(root->left);
		printPreOrder(root->right);
	}
}

void BinaryTree::printInOrder(TreeNode *root) {
	if (root != NULL) {
		printInOrder(root->left);
		cout << root->city;
		printInOrder(root->right);
	}
}

void BinaryTree::printPostOrder(TreeNode *root) {
	if (root != NULL) {
		printPostOrder(root->left);
		printPostOrder(root->right);
		cout << root->city;
	}
}

int BinaryTree::height() {
	return height(root);
}

int BinaryTree::height(TreeNode *node) {
	if (node == NULL) {
		return -1;
	}

	int left = height(node->left);
	int	right = height(node->right);

	if (left > right) {
		return left + 1;
	}
	else {
		return right + 1;
	}
}

bool BinaryTree::searchByCoordinate(pair<double, double> searchFor) {
	if (root == NULL) {
		return false;
	}
	return searchByCoordinate(root, searchFor);
}

bool BinaryTree::searchByCoordinate(TreeNode *root, pair<double, double> searchFor) {
	bool found = false;
	if (!found && root != NULL) {
		if (searchFor == root->city.coordinates) {
			found = true;
			return found;
		}
		else if (searchFor <= root->city.coordinates) {
			searchByCoordinate(root->left, searchFor);
		}
		else if (searchFor > root->city.coordinates) {
			searchByCoordinate(root->right, searchFor);
		}
		else {
			found = false;
			return found;
		}
	}
}

bool BinaryTree::searchByName(string name) {
	if (root == NULL) {
		return false;
	}
	return searchByName(root, name);
}

bool BinaryTree::searchByName(TreeNode *root, string name) {
	bool found = false;
	if (!found && root != NULL) {
		cout << "Comparing " << name << " with " << root->city.city << "\n";
		if (name.compare(root->city.city) == 0) {
			cout << "They are equal\n";
			found = true;
			return found;
		}
		else if (root->left != NULL && name.compare(root->city.city) < 0) {
			cout << name << " is less than " << root->city.city << "\n";
			searchByName(root->left, name);
		}
		else if (root->right != NULL && name.compare(root->city.city) > 0) {
			cout << name << " is greater than " << root->city.city << "\n";
			searchByName(root->right, name);
		}
		else {
			cout << "I am returning false\n";
			found = false;
			return found;
		}
	}
}

bool BinaryTree::deleteByCoordinates(pair<double, double> coordinates) {
	if (root == NULL) {
		return false;
	}
	else {
		if (coordinates == root->city.coordinates) {
			TreeNode *temp = new TreeNode();
			temp->left = root;
			TreeNode *toDelete = deleteByCoordinates(coordinates, temp, root);
			root = temp->left;
			if (toDelete != NULL) {
				delete toDelete;
				return true;
			}
			return false;
		}
		else {
			TreeNode *toDelete = deleteByCoordinates(coordinates, NULL, root);
			if (toDelete != NULL) {
				delete toDelete;
				return true;
			}
			return false;
		}
	}
}

TreeNode* BinaryTree::deleteByCoordinates(pair<double, double> coordinates, TreeNode *parent, TreeNode *root) {
	if (coordinates < root->city.coordinates) {
		if (root->left != NULL) {
			return deleteByCoordinates(coordinates, root, root->left);
		}
		return NULL;
	}
	else if (coordinates > root->city.coordinates) {
		if (root->right != NULL) {
			return deleteByCoordinates(coordinates, root, root->right);
		}
		return NULL;
	}
	else {
		if (root->left != NULL && root->right != NULL) {
			root = getMin(root->right);
			return deleteByCoordinates(root->city.coordinates, root, root->right);
		}
		else if (parent->left == root) {
			if (root->left != NULL) {
				parent->left = root->left;
			}
			else {
				parent->left = root->right;
			}
			return root;
		}
		else if (parent->right == root) {
			if (root->left != NULL) {
				parent->right = root->left;
			}
			else {
				parent->right = root->right;
			}
			return root;
		}
	}
}

bool BinaryTree::deleteByName(string name) {
	if (root == NULL) {
		return false;
	}
	else {
		if (name == root->city.city) {
			TreeNode *temp = new TreeNode();
			temp->left = root;
			TreeNode *toDelete = deleteByName(name, temp, root);
			root = temp->left;
			if (toDelete != NULL) {
				delete toDelete;
				return true;
			}
			return false;
		}
		else {
			TreeNode *toDelete = deleteByName(name, NULL, root);
			if (toDelete != NULL) {
				delete toDelete;
				return true;
			}
			return false;
		}
	}
}

TreeNode* BinaryTree::deleteByName(string name, TreeNode *parent, TreeNode *root) {
	if (name < root->city.city) {
		if (root->left != NULL) {
			return deleteByName(name, root, root->left);
		}
		return NULL;
	}
	else if (name > root->city.city) {
		if (root->right != NULL) {
			return deleteByName(name, root, root->right);
		}
		return NULL;
	}
	else {
		if (root->left != NULL && root->right != NULL) {
			root = getMin(root->right);
			return deleteByName(root->city.city, root, root->right);
		}
		else if (parent->left == root) {
			if (root->left != NULL) {
				parent->left = root->left;
			}
			else {
				parent->left = root->right;
			}
			return root;
		}
		else if (parent->right == root) {
			if (root->left != NULL) {
				parent->right = root->left;
			}
			else {
				parent->right = root->right;
			}
			return root;
		}
	}
}

TreeNode* BinaryTree::getMin(TreeNode *root) {
	if (root->left != NULL) {
		return getMin(root->left);
	}
	return root;
}