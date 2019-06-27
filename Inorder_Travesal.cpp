//https://leetcode.com/problems/binary-tree-inorder-traversal
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> v={};
vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL) return v;
        
        if(root->left) inorderTraversal(root->left);
        v.push_back(root->val);
        if(root->right) inorderTraversal(root->right);
    return v;}