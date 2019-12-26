//https://leetcode.com/problems/range-sum-of-bst/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(root==NULL) return 0;
        
        if(root->val<=R and root->val>=L){
            return root->val+rangeSumBST(root->right,L,R)+ rangeSumBST(root->left,L,R);
        }
  
        else{
            return rangeSumBST(root->right,L,R)+ rangeSumBST(root->left,L,R);

        };}
};