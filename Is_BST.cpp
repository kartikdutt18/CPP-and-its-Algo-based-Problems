//https://leetcode.com/problems/validate-binary-search-tree/
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

bool isBST(TreeNode *root, int max_val, int min_val)
{
    if (root == NULL)
        return true;
    if (root->val < min_val || root->val > max_val)
        return 0;

    return isBST(root->left, root->val, min_val) && isBST(root->right, max_val, root->val);
}
bool isValidBST(TreeNode *root)
{
    return isBST(root, INT_MAX, INT_MIN);
}