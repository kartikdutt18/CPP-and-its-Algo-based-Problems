//https://leetcode.com/problems/leaf-similar-trees

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> bfsleaf(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    vector<int> v={};
    while(!q.empty()){
        TreeNode* cur=q.front();
        q.pop();
        if(root){
            if(root->right) q.push(root->right);
            if(root->left) q.push(root->left);
            else if((!root->right) and (!root->left)) v.push_back(root->val);
        }
    }

return v;}
void dfsleaf(TreeNode * root,vector<int> &v){
    if(root==NULL) return;
    if((root->right==NULL) and (root->left==NULL)){
        v.push_back(root->val);
    }
    dfsleaf(root->right,v);
    dfsleaf(root->left,v);
    return ;

}
bool leafSimilar(TreeNode* root1, TreeNode* root2){
    // vector<int> v1=bfsleaf(root1);
    // vector<int> v2=bfsleaf(root2);
    vector<int> v1={};
    vector <int> v2={};
    dfsleaf(root1,v1);
    dfsleaf(root2,v2);
    return v1==v2;

}