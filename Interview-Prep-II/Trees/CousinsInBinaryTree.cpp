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
  vector<int> solve(TreeNode *A, int B)
  {
    vector<int> ans;
    queue<pair<TreeNode *, TreeNode *>> q;
    q.push({A, A});
    int level = 0;
    int reqLevel = -1;
    TreeNode *parent = NULL;
    while (!q.empty())
    {
      int len = q.size();
      for (int i = 0; i < len; i++)
      {
        pair<TreeNode *, TreeNode *> pp = q.front();
        q.pop();
        // cout << "{"<< pp.first->val << ", " << pp.second->val << "}";
        if (level == reqLevel && pp.second != parent)
        {
          ans.push_back(pp.first->val);
        }
        if (pp.first->left)
        {
          q.push({pp.first->left, pp.first});
          if (pp.first->left->val == B)
          {
            reqLevel = level + 1;
            parent = pp.first;
          }
        }
        if (pp.first->right)
        {
          q.push({pp.first->right, pp.first});
          if (pp.first->right->val == B)
          {
            reqLevel = level + 1;
            parent = pp.first;
          }
        }
      }
      level++;
    }
    return ans;
  }
};

int main()
{
  ios::sync_with_stdio(false);
  return 0;
}