//https://leetcode.com/problems/increasing-order-search-tree/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* GetLeftNode(TreeNode *root){
    TreeNode* leaf=root;
    while(root->left){
        leaf=root;
        root=root->left;
    }
    return root; 
}
TreeNode* MorrisTraversalMod(TreeNode * &root){
    TreeNode* cur=root;
    cur=root;
    TreeNode dummy(0);
    TreeNode *prev = &dummy;
    while(cur!=NULL){
        if(cur->left!=NULL){
            prev->right = cur;
            prev = cur;
            cur=cur->right;
        }
        else{
            TreeNode * predecessor=cur->left;
            while(predecessor->right!=NULL && predecessor->right!=cur){
                predecessor=predecessor->right;
            }
            if(predecessor->right==NULL){
                predecessor->right=cur;
                cur=cur->left;
            }
            else{
                cur->left=NULL;
                prev->right=cur;
                prev=cur;
                cur=cur->right;
            }
        }
    }
return dummy.right;}