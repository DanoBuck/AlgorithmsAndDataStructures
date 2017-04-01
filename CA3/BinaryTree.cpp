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
			return searchByCoordinate(root->left, searchFor);
		}
		else if (searchFor > root->city.coordinates) {
			return searchByCoordinate(root->right, searchFor);
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
		if (name == root->city.city) {
			cout << "They are equal\n";
			found = true;
			return found;
		}
		else if (root->left != NULL && name < root->city.city) {
			return searchByName(root->left, name);
		}
		else if (root->right != NULL && name > root->city.city) {
			return searchByName(root->right, name);
		}
		else {
			cout << "I am returning false\n";
			found = false;
			return found;
		}
	}
}

bool BinaryTree::deleteByName(string data) {
	if (root == NULL) {
		return false;
	}
	else {
		if (root->city.city == data) {
			TreeNode *tempNode = new TreeNode();
			tempNode->left = root;
			TreeNode *nodeToRemove = deleteByName(data, tempNode, root);
			root = tempNode->left;
			if (nodeToRemove != NULL) {
				delete nodeToRemove;
				return true;
			}
			return false;
		}
		else {
			TreeNode *nodeToRemove = deleteByName(data, NULL, root);
			if (nodeToRemove != NULL) {
				delete nodeToRemove;
				return true;
			}
			return false;
		}
	}
}

TreeNode* BinaryTree::deleteByName(string data, TreeNode *parent, TreeNode *root) {
	if (data < root->city.city) {
		if (root->left != NULL) {
			return deleteByName(data, root, root->left);
		}
		return NULL;
	}
	else if (data > root->city.city) {
		if (root->right != NULL) {
			return deleteByName(data, root, root->right);
		}
		return NULL;
	}
	else {
		if (root->left != NULL && root->right != NULL) {
			root->city = getMin(root->right);
			return deleteByName(root->city.city, root, root->right);
		}
		else if (parent->left == root) {
			if (root->left != NULL)
			{
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

City BinaryTree::getMin(TreeNode *root) {
	if (root->left != NULL) {
		return getMin(root->left);
	}
	return root->city;
}

TreeNode* BinaryTree::findCityByCoordinates(pair<double, double> coordinates, TreeNode *root) {
	if (root == NULL) {
		return NULL;
	}

	if (root->city.coordinates == coordinates) {
		return root;
	}

	TreeNode *left = findCityByCoordinates(coordinates, root->left);
	TreeNode *right = findCityByCoordinates(coordinates, root->right);

	if (left != NULL) {
		return left;
	}
	else if (right != NULL) {
		return right;
	}
}

TreeNode* BinaryTree::findCityByCoordinates(pair<double, double> coordinates) {
	if (root == NULL) {
		return NULL;
	}
	return findCityByCoordinates(coordinates, root);
}

bool BinaryTree::deleteByCoordinatesHelper(pair<double, double> coordinates) {
	TreeNode *data = findCityByCoordinates(coordinates);
	if (data != NULL) {
		return deleteByNameAndCoordinates(data->city.city, data->city.coordinates);
	}
	return false;
}

bool BinaryTree::deleteByNameAndCoordinates(string name, pair<double, double> coordinates) {
	if (root == NULL) {
		return false;
	}
	else {
		if (name == root->city.city && coordinates == root->city.coordinates) {
			TreeNode *temp = new TreeNode();
			temp->left = root;
			TreeNode *toDelete = deleteByNameAndCoordinates(name, coordinates, temp, root);
			root = temp->left;
			if (toDelete != NULL) {
				delete toDelete;
				return true;
			}
			return false;
		}
		else {
			TreeNode *toDelete = deleteByNameAndCoordinates(name, coordinates, NULL, root);
			if (toDelete != NULL) {
				delete toDelete;
				return true;
			}
			return false;
		}
	}
}

TreeNode* BinaryTree::deleteByNameAndCoordinates(string name, pair<double, double> coordinates, TreeNode *parent, TreeNode *root) {
	if ((name < root->city.city && root->city.coordinates != coordinates) || (root->city.city == name && root->city.coordinates != coordinates)) {
		if (root->left != NULL) {
			return deleteByNameAndCoordinates(name, coordinates, root, root->left);
		}
		return NULL;
	}
	else if (name > root->city.city && root->city.coordinates != coordinates) {
		if (root->right != NULL) {
			return deleteByNameAndCoordinates(name, coordinates, root, root->right);
		}
		return NULL;
	}
	else {
		if (root->left != NULL && root->right != NULL) {
			root->city = getMin(root->right);
			return deleteByNameAndCoordinates(root->city.city, root->city.coordinates, root, root->right);
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