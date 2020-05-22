#include <vector>
#include <bits/stdc++.h>
using namespace std;

class BinaryTree
{
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value);
  void insert(vector<int> values, int i = 0);
  void invertedInsert(vector<int> values, int i = 0);
};

void invertBinaryTree(BinaryTree *root)
{
  if (!root)
    return;
  queue<BinaryTree *> q;
  q.push(root);
  while (!q.empty())
  {
    auto cur = q.front();
    q.pop();
    if (!cur->left && !cur->right)
      continue;
    swap(cur->left, cur->right);
    if (cur->left)
      q.push(cur->left);
    if (cur->right)
      q.push(cur->right);
  }
  return;
}
