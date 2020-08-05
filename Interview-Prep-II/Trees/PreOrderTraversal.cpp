#include <iostream>
#include <bits/stdc++.h>
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

class Solution
{
public:
  vector<int> preorderTraversal(TreeNode *root)
  {
    TreeNode *curr = root;
    vector<int> ans;
    while (curr)
    {
      if (!curr->left)
      {
        ans.push_back(curr->val);
        curr = curr->right;
      }
      else
      {
        TreeNode *predecessor = curr->left;
        while (predecessor->right && predecessor->right != curr)
          predecessor = predecessor->right;
        if (!predecessor->right)
        {
          ans.push_back(curr->val);
          predecessor->right = curr;
          curr = curr->left;
        }
        else
        {
          predecessor->right = NULL;
          curr = curr->right;
        }
      }
    }
    return ans;
  }
};

int main()
{
  ios::sync_with_stdio(false);
  return 0;
}