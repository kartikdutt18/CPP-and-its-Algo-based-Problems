//https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), right(NULL), left(NULL){};
};

vector<vector<int>> levelOrderBottom(TreeNode *root)
{
    if (root == NULL)
        return {};
    vector<vector<int>> ans;

    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {

        int l = q.size();
        vector<int> v;
        for (int i = 0; i < l; i++)
        {
            TreeNode *cur = q.front();
            q.pop();
            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
            v.push_back(cur->val);
        }
        ans.push_back(v);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}