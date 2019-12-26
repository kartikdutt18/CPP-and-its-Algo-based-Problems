//https://leetcode.com/problems/cousins-in-binary-tree/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
                                               
};

bool isCousins(TreeNode *root, int x, int y)
{

    queue<TreeNode *> q;
    q.push(root);
    map<int, pair<int, int>> parent;
    int depth = 0;
    parent[root->val] = {0, -1};
    while (!q.empty())
    {
        int l = q.size();
        for (int i = 0; i < l; i++)
        {
            TreeNode *cur = q.front();
            q.pop();
            if (cur->left)
            {
                parent[cur->left->val] = {depth + 1, cur->val};
                q.push(cur->left);
            }
            if (cur->right)
            {
                parent[cur->right->val] = {depth + 1, cur->val};
                q.push(cur->right);
            }
        }
        if (parent.count(x) && parent.count(y))
        {
            return parent[x].first == parent[y].first && parent[x].second != parent[y].second;
        }
        depth++;
    }
    return parent[x].first == parent[y].first && parent[x].second != parent[y].second;
}