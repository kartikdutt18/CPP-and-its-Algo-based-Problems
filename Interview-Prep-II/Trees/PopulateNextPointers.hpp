/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode *A)
{
  if (!A)
    return;
  queue<TreeLinkNode *> q;
  q.push(A);
  while (!q.empty())
  {
    int len = q.size();
    for (int i = 0; i < len; i++)
    {
      TreeLinkNode *cur = q.front();
      q.pop();
      if (i != len - 1)
        cur->next = q.front();
      if (cur->left)
        q.push(cur->left);
      if (cur->right)
        q.push(cur->right);
    }
  }
}
