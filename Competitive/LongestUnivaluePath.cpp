//https://leetcode.com/problems/longest-univalue-path/submissions/

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
    int max_len = 0;
    int longestUnival(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int left = longestUnival(root->left);
        int right = longestUnival(root->right);
        int len_left = 0, len_right = 0;
        if (root->left && root->left->val == root->val)
            len_left += left + 1;
        if (root->right && root->right->val == root->val)
            len_right += right + 1;
        max_len = max(max_len, len_left + len_right);
        return max(len_right, len_left);
    }
    int longestUnivaluePath(TreeNode *root)
    {
        if (!root)
            return 0;
        longestUnival(root);
        return max_len;
    }
};