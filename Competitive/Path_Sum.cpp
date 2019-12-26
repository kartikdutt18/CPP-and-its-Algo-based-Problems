//https://leetcode.com/problems/path-sum/
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
bool hasPathSum(TreeNode *root, int sum)
{
    if (root == NULL)
        return false;
    sum = sum - root->val;
    if (sum == 0 && root->left == NULL && root->right == NULL)
        return true;
    return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
}