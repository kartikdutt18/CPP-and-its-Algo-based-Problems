//https://leetcode.com/contest/weekly-contest-172/problems/delete-leaves-with-a-given-value/
#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};
TreeNode *removeLeafNodes(TreeNode *root, int target)
{
    if (!root)
        return root;
    root->left = removeLeafNodes(root->left, target);
    root->right = removeLeafNodes(root->right, target);
    if (root->val == target && root->left == NULL && root->right == NULL)
    {
        return NULL;
    }
    return root;
}
int main()
{
    return 0;
}