//https://leetcode.com/problems/balanced-binary-tree
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int height(TreeNode* root){
    if(root==NULL) return 0;
    return max(height(root->right),height(root->left))+1;

}
bool isBalanced(TreeNode* root) {
    if(root==NULL) return true;
    bool left=isBalanced(root->left);
    bool right=isBalanced(root->right);
    if(not right or not left) return false;
    int ht_left=height(root->left);
    int ht_right=height(root->right);
    if(abs(ht_right-ht_left)==1 and left and right){
        return true;
    }
    else{
        return false;
    }
}
/*
int dfsHeight (TreeNode *root) {
        if (root == NULL) return 0;
        
        int leftHeight = dfsHeight (root -> left);
        if (leftHeight == -1) return -1;
        int rightHeight = dfsHeight (root -> right);
        if (rightHeight == -1) return -1;
        
        if (abs(leftHeight - rightHeight) > 1)  return -1;
        return max (leftHeight, rightHeight) + 1;
    }
    bool isBalanced(TreeNode *root) {
        return dfsHeight (root) != -1;
    } */