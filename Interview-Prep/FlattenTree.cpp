#include <vector>
using namespace std;

// This is the class of the input root. Do not edit it.
class BinaryTree {
public:
  int value;
  BinaryTree *left = NULL;
  BinaryTree *right = NULL;

  BinaryTree(int value);
};

void ConnectNodes(BinaryTree* node1, BinaryTree* node2)
{
	node2->left = node1;
	node1->right = node2;
}

vector<BinaryTree*> flattenHelper(BinaryTree* root)
{
	if (!root)
		return {NULL, NULL};
	BinaryTree* leftMost = root;
	BinaryTree* rightMost = root;
	if (root->left)
	{
		vector<BinaryTree*> leftSubTree = flattenHelper(root->left);
		ConnectNodes(leftSubTree[1], root);
		leftMost = leftSubTree[0];
	}
	if (root->right)
	{
		vector<BinaryTree*> rightSubTree = flattenHelper(root->right);
		ConnectNodes(rightMost, rightSubTree[0]);
		rightMost = rightSubTree[1];
	}
	return {leftMost, rightMost};
}

BinaryTree *flattenBinaryTree(BinaryTree *root) {
  return flattenHelper(root)[0];
}

