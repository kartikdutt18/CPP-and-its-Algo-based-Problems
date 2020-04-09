//https://leetcode.com/problems/construct-string-from-binary-tree/
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
void serialize(TreeNode* t,string & s){
    if (!t)
        return;
    
    if(!t->left && t->right){
        s+=to_string(t->val)+')';
        return;
    }
    s += to_string(t->val);
    s+='(';
    serialize(t->left,s);
    serialize(t->right,s);
    s+=')';

}
string tree2str(TreeNode *t)
{
    string ans="";
    serialize(t,ans);
    return ans;
    
}