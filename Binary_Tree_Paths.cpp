//https://leetcode.com/problems/binary-tree-paths/submissions/
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

    class Solution
{
public:
    vector<string> sets;
    void dfs(TreeNode *root, string s)
    {
        if (!root)
            return;
        s += to_string(root->val);
        if (!root->right && !root->left)
        {
            sets.emplace_back(s);
            return;
        }
        if (root->left)
            dfs(root->left, s + "->");
        if (root->right)
            dfs(root->right, s + "->");
        return;
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {
        dfs(root, "");
        return sets;
    }
};