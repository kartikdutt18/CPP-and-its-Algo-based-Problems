#include<iostream>
#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int inOrder(TreeNode *root, int &B)
{
  if (!root)
    return 0;
  int t = inOrder(root->left, B);
  if (B == 0)
    return t;
  B--;
  if (B == 0)
    return root->val;

  return inOrder(root->right, B);
}

int kthsmallest(TreeNode *A, int B)
{
  return inOrder(A, B);
}


int main()
{
  ios::sync_with_stdio(false);
  return 0;
}