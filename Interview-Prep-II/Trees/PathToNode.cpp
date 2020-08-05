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

vector<int> ans;
void dfs(TreeNode *root, vector<int> curPath, int target)
{
  if (!root)
    return;
  curPath.push_back(root->val);
  if (root->val == target)
    ans = curPath;
  if (root->left)
    dfs(root->left, curPath, target);
  if (root->right)
    dfs(root->right, curPath, target);
}
vector<int> solve(TreeNode *A, int B)
{
  ans.clear();
  dfs(A, {}, B);
  return ans;
}

int main()
{
  ios::sync_with_stdio(false);
  return 0;
}