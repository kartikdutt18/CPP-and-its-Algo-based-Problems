//https://leetcode.com/problems/symmetric-tree/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), right(NULL), left(NULL){};
};
bool Symmetry(TreeNode* root1,TreeNode* root2){
    if(root1==NULL && root2==NULL) return true;
    if(root1==NULL || root2==NULL) return false;
    if(root1->val!=root2->val) return false;
    return Symmetry(root1->right, root2->left) && Symmetry(root1->left, root2->right);
}
bool isSymmetric(TreeNode *root)
{
    return Symmetry(root,root);
}