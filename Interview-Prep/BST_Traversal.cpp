// Copyright © 2020 AlgoExpert, LLC. All rights reserved.

#include <vector>
using namespace std;

class BST
{
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
};

// O(n) time | O(n) space
vector<int> inOrderTraverse(BST *tree, vector<int> array)
{
  if (tree->left != NULL)
  {
    array = inOrderTraverse(tree->left, array);
  }
  array.push_back(tree->value);
  if (tree->right != NULL)
  {
    array = inOrderTraverse(tree->right, array);
  }
  return array;
}

// O(n) time | O(n) space
vector<int> preOrderTraverse(BST *tree, vector<int> array)
{
  array.push_back(tree->value);
  if (tree->left != NULL)
  {
    array = preOrderTraverse(tree->left, array);
  }
  if (tree->right != NULL)
  {
    array = preOrderTraverse(tree->right, array);
  }
  return array;
}

// O(n) time | O(n) space
vector<int> postOrderTraverse(BST *tree, vector<int> array)
{
  if (tree->left != NULL)
  {
    array = postOrderTraverse(tree->left, array);
  }
  if (tree->right != NULL)
  {
    array = postOrderTraverse(tree->right, array);
  }
  array.push_back(tree->value);
  return array;
}

int main()
{
  return 0;
}