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
  vector<int> inorderTraversal(TreeNode *root)
  {
    if (!root)
      return {};
    vector<int> ans;
    TreeNode *current = root;
    while (current)
    {
      if (!current->left)
      {
        ans.push_back(current->val);
        current = current->right;
      }
      else
      {
        TreeNode *predecessor = current->left;
        while (predecessor->right != current && predecessor->right != NULL)
          predecessor = predecessor->right;

        if (!predecessor->right)
        {
          predecessor->right = current;
          current = current->left;
        }
        else
        {
          predecessor->right = NULL;
          ans.push_back(current->val);
          current = current->right;
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