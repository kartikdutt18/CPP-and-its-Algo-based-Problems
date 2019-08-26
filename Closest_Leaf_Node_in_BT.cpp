//https://leetcode.com/problems/closest-leaf-in-a-binary-tree/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int findClosestLeaf(TreeNode *root, int k)
{
    if(!root) return k;
    queue<TreeNode *> q;
    q.push(root);
    int ans=root->val;
    int min_diff=INT_MAX;
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        if (abs(cur->val - k) < min_diff && cur->left == NULL && cur->right == NULL)
        {
            ans=cur->val;
            min_diff = abs(cur->val - k);
        }
        if (cur->left)
            q.push(cur->left);
        if (cur->right)
            q.push(cur->right);
    }
    return ans;
}