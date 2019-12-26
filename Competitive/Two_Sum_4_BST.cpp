//https://leetcode.com/problems/two-sum-iv-input-is-a-bst/s
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void dfs(TreeNode* root,map<int,int> &s){
    if(!root) return;
    if(s.count(root->val)) s[root->val]=s[root->val]+1;
    else s.insert(make_pair(root->val,1));
    dfs(root->right,s);
    dfs(root->left,s);
}
bool findTarget(TreeNode* root, int k) {
        map<int,int> s;
        dfs(root,s);
        for(auto i:s){
            s[i.first]=s[i.first]-1;
            if(s.count(k-i.first)){
                if(s[k-i.first]>=1){
                    return true;
                }
            }
            s[i.first]=s[i.first]+1;
        }
    return false;
    }