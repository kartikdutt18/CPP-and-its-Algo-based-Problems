//https://leetcode.com/problems/minimum-distance-between-bst-nodes/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode*left;
    TreeNode*right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
void Inorder(TreeNode *root,vector<int> &v){
    if(root==NULL) return ;
    if(root->left) Inorder(root->left,v);
    v.push_back(root->val);
    if(root->right) Inorder(root->right,v);
    return ;
}
int minDiffInBST(TreeNode *root)
{
    if(root==NULL) return 0;
    vector<int> v;
    Inorder(root,v);
    int ans=INT_MAX;
    for(int i=0;i<v.size()-1;i++){
        ans = min(ans, v[i + 1] - v[i]);
    }
return ans;}