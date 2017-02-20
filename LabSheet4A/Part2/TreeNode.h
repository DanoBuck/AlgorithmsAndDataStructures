class TreeNode {
	friend class BinaryTree;
private:
	int data;
	TreeNode *left;
	TreeNode *right;

public:
	TreeNode();
	TreeNode(int);
	int getData();
	TreeNode* getRight();
	TreeNode* getLeft();
};
