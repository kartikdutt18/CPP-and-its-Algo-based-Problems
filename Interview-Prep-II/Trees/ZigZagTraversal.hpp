/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int>> Solution::zigzagLevelOrder(TreeNode *A)
{
  if (!A)
    return {};
  queue<TreeNode *> q;
  q.push(A);
  int lel = 0;
  vector<vector<int>> ans;
  while (!q.empty())
  {
    int len = q.size();
    vector<int> level;
    for (int i = 0; i < len; i++)
    {
      TreeNode *cur = q.front();
      q.pop();
      level.push_back(cur->val);
      if (cur->left)
        q.push(cur->left);
      if (cur->right)
        q.push(cur->right);
    }
    if (lel & 1)
      reverse(level.begin(), level.end());
    ans.push_back(level);
    lel++;
  }
  return ans;
}
