#include<iostream>
#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* solve(TreeNode *A)
{
  if (!A)
    return A;

  if (A->left && !A->right)
    A = A->left;
  if (A->right && !A->left)
    A = A->right;

  A->left = solve(A->left);
  A->right = solve(A->right);
  return A;
}

int main()
{
  ios::sync_with_stdio(false);
  
  return 0;
}