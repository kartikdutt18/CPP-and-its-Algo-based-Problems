//https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* recbst(vector<int> nums,int s,int e){
    if(s>e) return NULL;
    int mid=(s+e)/2;
    TreeNode* root =new TreeNode(mid);
    root->left=recbst(nums,s,mid);
    root->right=recbst(nums,mid+1,e);
    return root;
}
TreeNode* sortedArrayToBST(vector<int>& nums) {
       return recbst(nums,0,nums.size());
}