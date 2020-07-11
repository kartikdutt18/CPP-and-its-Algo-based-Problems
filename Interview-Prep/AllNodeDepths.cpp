#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

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

int helper(BinaryTree *root, int depth, int &ans)
{
  if (!root)
    return 0;
  ans += (depth + 1) * depth / 2;
  return helper(root->left, depth + 1, ans) + helper(root->right, depth + 1, ans);
}

int allKindsOfNodeDepths(BinaryTree *root)
{

  int ans = 0;
  helper(root, 0, ans);
  return ans;
}

int main()
{
  return 0;
}