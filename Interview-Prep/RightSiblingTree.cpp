#include <vector>
#include <queue>
using namespace std;

// This is the class of the input root. Do not edit it.
class BinaryTree
{
public:
  int value;
  BinaryTree *left = NULL;
  BinaryTree *right = NULL;

  BinaryTree(int value);
};

BinaryTree *rightSiblingTree(BinaryTree *root)
{
  if (!root)
    return root;
  queue<BinaryTree *> q;
  q.push(root);
  while (!q.empty())
  {
    int len = q.size();
    for (int i = 0; i < len; i++)
    {
      BinaryTree *cur = q.front();
      q.pop();
      if (!cur)
        continue;
      q.push(cur->left);
      q.push(cur->right);
      cur->right = NULL;
      if (i + 1 < len)
        cur->right = q.front();
    }
  }
  return root;
}
