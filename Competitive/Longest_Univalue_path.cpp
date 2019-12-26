//
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
int ans=1;
void LongestPath(TreeNode* root,int len){
    if(!root) return;
    ans=max(ans,len);
    if(root->left){
        if(root->left->val==root->val){
            LongestPath(root->left,len);
        }
        else{
            LongestPath(root->left,0);
        }
    }
    if(root->right){
        if (root->right->val == root->val)
        {
            LongestPath(root->right, len);
        }
        else
        {
            LongestPath(root->right, 0);
        }
    }
}
int longestUnivaluePath(TreeNode *root)
{
    LongestPath(root,1);
    return ans;
}