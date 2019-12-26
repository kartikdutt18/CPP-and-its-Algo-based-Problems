//
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int sumOfLeftLeaves(TreeNode *root)
{
    if(!root) return 0;
    queue<TreeNode*> q;
    q.push(root);
    int sum=0;
    while(!q.empty()){
        auto cur=q.front();
        q.pop();
        if(cur->left){
            if(cur->left->left==NULL && cur->left->right==NULL){
                sum+=cur->left->val;
            }
            q.push(cur->left);
        }
        if(cur->right){
            q.push(cur->right);
        }
    }
    return sum;
}