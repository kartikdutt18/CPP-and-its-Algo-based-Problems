//https://leetcode.com/problems/binary-tree-preorder-traversal/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<int> ans={};
vector<int> preorderTraversal(TreeNode* root) {
        if(root==NULL) return ans;
        ans.push_back(root->val);
        if(root->left)preorderTraversal(root->left);
        if(root->right)preorderTraversal(root->right);
       
    return ans;}