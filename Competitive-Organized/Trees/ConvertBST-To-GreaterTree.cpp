//
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
    TreeNode *sumBST(TreeNode *root, int &curSum)
    {
        if (!root)
            return root;
        if (root->right)
            sumBST(root->right, curSum);
        root->val = root->val + curSum;
        curSum = root->val;
        if (root->left)
            sumBST(root->left, curSum);
        return root;
    }
    TreeNode *convertBST(TreeNode *root)
    {
        int t = 0;
        return sumBST(root, t);
    }
};