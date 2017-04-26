// Daniel Buckley
// X00109141

#include "BinaryTree.h"
#include <iostream>
using namespace std;

BinaryTree::BinaryTree() {
	root = NULL;
}

BinaryTree::~BinaryTree() {
	destroy(root);
}

// Helper method used in destructor to destroy the tree and
// free the memory consumed by it
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

// Method to allow insert into the tree, figures out whether
// the node should be placed left or right depending on the
// value of the city name. This method does not allow objects
// to be entered if they have the same coordinates as an object
// already in the tree
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

// Gets the height of the tree by checking the
// right and left side of the tree and checks which
// side is bigger, that is then returned
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

// Searches the tree to check if coordinates exist
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

// Used for comparisons, changes string to upper
string toUpperCase(string uppercase) {
	string result = "";
	for (int i = 0; i < uppercase.length(); i++) {
		result += toupper(uppercase[i]);
	}
	return result;
}

bool BinaryTree::searchByName(string name) {
	if (root == NULL) {
		return false;
	}
	name = toUpperCase(name);
	return searchByName(root, name);
}

// Searches the tree for city name
bool BinaryTree::searchByName(TreeNode *root, string name) {
	bool found = false;
	if (!found && root != NULL) {
		if (name == root->city.city) {
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
			found = false;
			return found;
		}
	}
}

// This deletes a node by city name although it may lead to the
// incorrect city being deleted as there may be cities in the
// tree with the same name so I would advise against using this
// method and use the coordinates delete or name and coordinate delete
bool BinaryTree::deleteByName(string data) {
	if (root == NULL) {
		return false;
	}
	else {
		data = toUpperCase(data);
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

// Private helper for method above
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

// Returns the left most node in a sub-tree
City BinaryTree::getMin(TreeNode *root) {
	if (root->left != NULL) {
		return getMin(root->left);
	}
	return root->city;
}

// Returns the city object which matches the cooridinates,
// used when deleting a node by name and coordinates
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

// This allows me to delete a city when I don't know it's name but
// I do know where it's located as I have it's coordinates. This uses
// the findCityByCordinates helper method to return the object I wish
// to delete and then I extract the name from the oject and call the
// deleteByNameAndCoordinate method which then deletes the node and
// arranges the tree accordingly
bool BinaryTree::deleteByCoordinates(pair<double, double> coordinates) {
	TreeNode *data = findCityByCoordinates(coordinates);
	if (data != NULL) {
		return deleteByNameAndCoordinates(data->city.city, data->city.coordinates);
	}
	return false;
}

// Allows me to delete a node by name and coordinates from the tree
bool BinaryTree::deleteByNameAndCoordinates(string name, pair<double, double> coordinates) {
	if (root == NULL) {
		return false;
	}
	else {
		name = toUpperCase(name);
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
			root->city.city = toUpperCase(root->city.city);
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

// Allows me print out all the city nodes within a specific KM distance from
// that point
void BinaryTree::printAllRecordsInDistance(pair<double, double> point, double distanceBelow) {
	if (root == NULL) {
		return;
	}
	TreeNode* node = findCityByCoordinates(point);
	string city = "";
	if (node != NULL) {
		city = node->city.city;
	}
	printAllRecordsInDistance(point, city, distanceBelow, root);
}

void BinaryTree::printAllRecordsInDistance(pair<double, double> point, string city, double distanceBelow, TreeNode*root) {
	if (root != NULL) {
		double distanceForCity = calculateDistance(point, root->city.coordinates);
		if (distanceForCity <= distanceBelow) {
			if (city != "") {
				cout << root->city.city << " is " << distanceForCity << " KM away from the point " << point.first << ", " << point.second << " which is the city of " << city << "\n";
			}
			else {
				cout << root->city.city << " is " << distanceForCity << " KM away from the point " << point.first << ", " << point.second << "\n";
			}
		}
		printAllRecordsInDistance(point, city, distanceBelow, root->left);
		printAllRecordsInDistance(point, city, distanceBelow, root->right);
	}
}

/***************************************************************************************

*    Usage: Based
*    Date: 1/4/2017
*    Availability: http://stackoverflow.com/questions/365826/calculate-distance-between-2-gps-coordinates
*
***************************************************************************************/
double BinaryTree::calculateDistance(pair<double, double> city1, pair<double, double> city2) {
	double PI = 3.14159265358979323846 / 180;

	int earthRadiusKm = 6371;

	double answerToBeSquared = sin(((city2.first - city1.first) * PI) / 2) 
								* sin(((city2.first - city1.first) * PI) / 2) 
								+ sin(((city2.second - city1.second) * PI) / 2)
								* sin(((city2.second - city1.second) * PI) / 2)
								* cos(city1.first * PI) * cos(city2.first * PI);

	double answerSqaured = 2 * atan2(sqrt(answerToBeSquared), sqrt(1 - answerToBeSquared));
	double distanceInKM = earthRadiusKm * answerSqaured;

	return distanceInKM;
}