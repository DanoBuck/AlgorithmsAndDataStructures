#include <iostream>
#include <string>

template<typename T> class TreeNode {
public:
	TreeNode<T> *left;
	TreeNode<T> *right;
	T data;

public:
	TreeNode();
	TreeNode(T dataIn);
};

template<typename T> class BinaryTree {
private:
	TreeNode<T> *root;
	void insert(TreeNode<T> *newNode, TreeNode<T> *root);
public:
	BinaryTree();
	~BinaryTree();
	void destroy(TreeNode<T> *);
	void printTree(TreeNode<T>*);
	void insert(T data);
	TreeNode<T>* getRoot() { return root; }
	bool findElement(TreeNode<T>*, T);
};

template<typename T> TreeNode<T>::TreeNode() {
	data = NULL;
	left = NULL;
	right = NULL;
}

template<typename T> TreeNode<T>::TreeNode(T dataIn) {
	data = dataIn;
	left = NULL;
	right = NULL;
}

template<typename T> BinaryTree<T>::BinaryTree() {
	root = NULL;
}

template<typename T> BinaryTree<T>::~BinaryTree() {
	destroy(root);
}

template<typename T> void BinaryTree<T>::destroy(TreeNode<T> *root) {
	if (root != NULL) {
		destroy(root->left);
		destroy(root->right);
		delete root;
	}
}

template<typename T> void BinaryTree<T>::insert(T data) {
	TreeNode<T> *newNode = new TreeNode<T>(data);

	if (root == NULL) {
		root = newNode;
	}
	else {
		insert(newNode, root);
	}
}

template<typename T> void BinaryTree<T>::insert(TreeNode<T> *newNode, TreeNode<T> *root) {
	if (newNode->data < root->data) {
		if (root->left != NULL) {
			insert(newNode, root->left);
		}
		else {
			root->left = newNode;
		}
	}
	else if (newNode->data >= root->data) {
		if (root->right != NULL) {
			insert(newNode, root->right);
		}
		else {
			root->right = newNode;
		}
	}
}

template<typename T> void BinaryTree<T>::printTree(TreeNode<T> *root) {
	if (root != NULL) {
		printTree(root->left);
		printTree(root->right);
		cout << root->data << "\n";
	}
}

template<typename T> bool BinaryTree<T>::findElement(TreeNode<T> *root, T searchFor) {
	bool isFound = false;

	if (!isFound && root->data != searchFor) {
		if (searchFor == root->data) {
			isFound = true;
			return isFound;
		}
		else if (root->left != NULL && searchFor < root->data) {
			findElement(root->left, searchFor);
		}
		else if (root->right != NULL && searchFor >= root->data) {
			findElement(root->right, searchFor);
		}
		else {
			isFound = false;
			return isFound;
		}
	}
}
