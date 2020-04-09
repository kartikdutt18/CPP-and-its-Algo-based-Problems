//https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
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
int maxLevelSum(TreeNode *root)
{
    if(!root) return 0;
    queue<TreeNode*> q;
    q.push(root);
    int max_sum=root->val;
    int min_level=1;
    int level=1;
    while(!q.empty()){
        int len=q.size();
        int cur_sum=0;
        for(int i=0;i<len;i++){
            auto cur = q.front();
            q.pop();
            cur_sum+=cur->val;
            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
        }
        if(cur_sum>max_sum){
            max_sum=cur_sum;
            min_level=level;
        }
        level++;

    }
    return min_level;
}