#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

// This is the class of the input root. Do not edit it.
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

void preOrderTraversal(BinaryTree *root, int curSum, vector<int> &v)
{
  if (!root)
  {
    return;
  }
  curSum = curSum + root->value;
  if (!root->left && !root->right)
  {
    v.push_back(curSum);
  }
  if (root->left)
    preOrderTraversal(root->left, curSum, v);
  if (root->right)
    preOrderTraversal(root->right, curSum, v);
  return;
}
vector<int> branchSums(BinaryTree *root)
{
  vector<int> ans;
  preOrderTraversal(root, 0, ans);
  for (auto i : ans)
    cout << i << " ";
  return ans;
}

int main()
{

return 0;
}