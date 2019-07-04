//https://leetcode.com/problems/maximum-depth-of-binary-tree/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode* root) {
    if(!root) return 0;
    queue<TreeNode*> q;
    q.push(root);
    int depth=0;
    while(!q.empty()){
        int len=q.size();
        
        for(int i=0;i<len;i++){
            auto src=q.front();
            q.pop();
            if(src->left) q.push(src->left);
            if(src->right) q.push(src->right);
        }
        depth++;
    }

return depth;}