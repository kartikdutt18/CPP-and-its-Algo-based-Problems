/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode *A)
{
  if (!A)
    return {};
  queue<TreeNode *> q;
  q.push(A);
  vector<int> ans;
  while (!q.empty())
  {
    int len = q.size();
    for (int i = 0; i < len; i++)
    {
      TreeNode *cur = q.front();
      q.pop();
      if (i == len - 1)
        ans.push_back(cur->val);
      if (cur->left)
        q.push(cur->left);
      if (cur->right)
        q.push(cur->right);
    }
  }
  return ans;
}
