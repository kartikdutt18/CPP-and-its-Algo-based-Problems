//https://leetcode.com/problems/insert-into-a-binary-search-tree/
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
TreeNode *insertIntoBST(TreeNode *root, int val)
{   TreeNode * node= new TreeNode(val);
    if(root==NULL){
        return node;
    }
    TreeNode *cur=root;
    TreeNode* parent=NULL;
    while(cur){
        parent=cur;
        cur->val <= val ? cur = cur->right : cur = cur->left;
    }
    if(parent->val>=val){
        parent->left=node;
    }
    else{
        parent->right=node;
    }
    return root;
}