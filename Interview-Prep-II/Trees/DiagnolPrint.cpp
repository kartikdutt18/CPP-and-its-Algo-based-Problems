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

void diagonalPrintUtil(TreeNode *root, int d, map<int, vector<int>> &diagonalPrint)
{
  // Base case
  if (!root)
    return;

  // Store all nodes of same line together as a vector
  diagonalPrint[d].push_back(root->val);

  // Increase the vertical distance if left child
  diagonalPrintUtil(root->left, d + 1, diagonalPrint);

  // Vertical distance remains same for right child
  diagonalPrintUtil(root->right, d, diagonalPrint);
}

vector<int> solve(TreeNode *A)
{
  if (!A)
    return {};
  map<int, vector<int>> levelOrder;
  diagonalPrintUtil(A, 0, levelOrder);
  vector<int> ans;
  for (auto it = levelOrder.begin(); it != levelOrder.end(); ++it)
  {
    for (auto itr = it->second.begin(); itr != it->second.end(); ++itr)
      ans.push_back(*itr);
  }

  return ans;
}

int main()
{
  ios::sync_with_stdio(false);
  return 0;
}