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

int Height(TreeNode *A, bool &isBalanced)
{
  if (!A)
    return 0;
  int leftHt = Height(A->left, isBalanced);
  int rightHt = Height(A->right, isBalanced);
  int curHeight = 1 + max(leftHt, rightHt);
  if (abs(leftHt - rightHt) > 1)
    isBalanced = false;
  return curHeight;
}
int isBalanced(TreeNode *A)
{
  bool ans = true;
  Height(A, ans);
  return ans;
}

int main()
{
  ios::sync_with_stdio(false);
  return 0;
}