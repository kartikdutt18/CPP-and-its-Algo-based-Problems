//https://leetcode.com/problems/find-largest-value-in-each-tree-row/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode*left;
    TreeNode* right;
    TreeNode(int x): val(x),left(NULL),right(NULL) {}
};

vector<int> largestValues(TreeNode *root)
{
    if(!root) return {};
    queue<TreeNode*> q;
    q.push(root);
    vector<int> ans;
    while(!q.empty()){
        int mx=INT_MIN;
        int l=q.size();
        for(int i=0;i<l;i++){
            TreeNode* cur=q.front();
            q.pop();
            mx=max(mx,cur->val);
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
        ans.push_back(mx);
    }
return ans;}