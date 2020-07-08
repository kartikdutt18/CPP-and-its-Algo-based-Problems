#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

class BST
{
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};

void helper(BST *root, int target, int &ans, int &minDiff)
{
  if (!root)
    return;
  if (abs(target - root->value) < minDiff)
  {
    minDiff = abs(target - root->value);
    ans = root->value;
  }

  if (root->value > target)
    return helper(root->left, target, ans, minDiff);
  return helper(root->right, target, ans, minDiff);
}

int findClosestValueInBst(BST *tree, int target)
{
  int ans = INT_MAX;
  int minDiff = INT_MAX;
  helper(tree, target, ans, minDiff);
  return ans;
}

int main()
{
  return 0;
}