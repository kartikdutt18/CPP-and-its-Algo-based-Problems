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

class Solution
{
public:
  vector<int> postorderTraversal(TreeNode *root)
  {
    if (!root)
      return {};
    stack<TreeNode *> st;
    st.push(root);
    vector<int> ans;
    while (!st.empty())
    {
      if (!st.top()->right && !st.top()->left)
      {
        ans.push_back(st.top()->val);
        st.pop();
      }
      else
      {
        if (st.top()->right && st.top()->left)
        {
          TreeNode *cur = st.top();
          TreeNode *right = st.top()->right;
          TreeNode *left = st.top()->left;
          st.pop();
          cur->left = NULL;
          cur->right = NULL;
          st.push(cur);
          st.push(right);
          st.push(left);
        }
        else if (st.top()->right)
        {
          TreeNode *cur = st.top();
          TreeNode *right = st.top()->right;
          st.pop();
          cur->right = NULL;
          st.push(cur);
          st.push(right);
        }
        else if (st.top()->left)
        {
          TreeNode *cur = st.top();
          TreeNode *left = st.top()->left;
          st.pop();
          cur->left = NULL;
          st.push(cur);
          st.push(left);
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