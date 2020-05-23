#include <bits/stdc++.h>
using namespace std;

class BinaryTree
{
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value)
  {
    this->value = value;
    left = NULL;
    right = NULL;
  }
};

int nodeDepths(BinaryTree *root, int depth = 0)
{
  if (!root)
    return 0;
  int sum = depth;
  sum += nodeDepths(root->left, depth + 1);
  sum += nodeDepths(root->right, depth + 1);
  return sum;
}