//https://leetcode.com/problems/closest-binary-search-tree-value/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x),left(NULL),right(NULL) {}
};

int closestValue(TreeNode *root, double target)
{
    double min_diff = numeric_limits<double>::max();
    int ans = root->val;
    while (root)
    {
        double cur_diff = abs(root->val - target);
        if (cur_diff < min_diff)
        {
            ans = root->val;
            min_diff = cur_diff;
        }
        root = target < root->val ? root->left : root->right;
    }
    return ans;
}
