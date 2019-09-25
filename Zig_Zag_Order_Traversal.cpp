//https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/submissions/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{

    queue<TreeNode*> q;
    vector<vector<int>> ans;
    q.push(root);
    int l=0;
    while(!q.empty()){
        vector<int> level;
        int siz=q.size();
        for(int i=0;i<siz;i++){
            auto cur = q.front();
            q.pop();
            level.push_back(cur->val);
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
        if(l&1) reverse(level.begin(),level.end());
        l++;
        ans.push_back(level);
    }
    return ans;
}