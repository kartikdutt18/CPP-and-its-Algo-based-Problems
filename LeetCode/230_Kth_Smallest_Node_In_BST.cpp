#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr){}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
};

int kthSmallest(TreeNode *root, int &k)
{
  if (!root)
    return -1;
  int ans = -1;
  if (root->left)
    ans = max(kthSmallest(root->left, k), ans);
  k--;
  if (k == 0)
    return root->val;
  if (root->right)
    ans = max(kthSmallest(root->right, k), ans);
  return ans;
}

int main() {

  return 0;
}