//https://leetcode.com/problems/average-of-levels-in-binary-tree/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<double> averageOfLevels(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        vector<double> fin={};
        q.push(root);
        while(!q.empty()){
            int len=q.size();
            int sum=0;
            for(int i=0;i<len;i++){
                auto src=q.front();
                q.pop();
                sum+=src->val;
                if(root->right) q.push(root->right);
                if(root->left) q.push(root->left);
        }
    double ans=sum/len;
    fin.push_back(ans);
    }
return fin;}
