//https://leetcode.com/problems/invert-binary-tree/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//Recursive
TreeNode* invertTree(TreeNode* root) {
    if(root==NULL) return root;
    swap(root->right,root->left);
    invertTree(root->right);
    invertTree(root->left);
    return root;
    }
TreeNode* invertTreebfs(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* temp=q.front();
        q.pop();
        if(root) {
            swap(temp->right,temp->left);
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
    return root;
}