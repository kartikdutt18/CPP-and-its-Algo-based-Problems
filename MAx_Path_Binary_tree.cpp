//https://leetcode.com/problems/binary-tree-maximum-path-sum/submissions/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
};
int ConvertTree(TreeNode *root, int &ans)
{
    if (root == NULL)
        return 0;

    int leftsum = ConvertTree(root->left, ans);
    int rightsum = ConvertTree(root->right, ans);
    int max_single = max(max(leftsum, rightsum) + root->val, root->val);
    int max_tops = max(max_single, root->val + leftsum + rightsum);
    ans = max(ans, max_tops);
    return max_single;
}
int maxPathSum(TreeNode *root)
{
    int ans = INT_MIN;
    ConvertTree(root, ans);
    return ans;
}