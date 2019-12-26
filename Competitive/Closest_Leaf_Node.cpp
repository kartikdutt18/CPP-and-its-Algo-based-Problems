//https://leetcode.com/problems/closest-leaf-in-a-binary-tree/
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

int countNodes(TreeNode *root)
{
    if(!root) return 0;
    queue<TreeNode*> q;
    q.push(root);
    int cnt=0;
    while(!q.empty()){
        auto cur=q.front();
        q.pop();
        //if ((cur->right && cur->left) || (cur->right == NULL && cur->left == NULL)) cnt++;
        cnt++;
        if(cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
    return cnt;
}