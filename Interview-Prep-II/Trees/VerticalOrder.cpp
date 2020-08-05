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

vector<vector<int>> verticalOrderTraversal(TreeNode *A)
{
  vector<vector<int>> v;
  if (A == NULL)
    return v;

  queue<pair<TreeNode *, int>> q;
  q.push({A, 0});

  map<int, vector<int>> mp;
  while (!q.empty())
  {
    pair<TreeNode *, int> temp = q.front();
    q.pop();

    if (temp.first->left)
    {
      q.push({temp.first->left, temp.second - 1});
    }
    if (temp.first->right)
    {
      q.push({temp.first->right, temp.second + 1});
    }

    mp[temp.second].push_back(temp.first->val);
  }

  for (map<int, vector<int>>::iterator it = mp.begin(); it != mp.end(); it++)
  {
    v.push_back(it->second);
  }
  return v;
}

int main()
{
  ios::sync_with_stdio(false);
  return 0;
}