//https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
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
void preorder(vector<string> &v, string &s, TreeNode *root)
{
    if (!root)
        return;
    s += to_string(root->val);
    if (root->left == NULL && root->right == NULL)
    {
        v.push_back(s);
    }
    if (root->left)
        preorder(v, s, root->left);
    if (root->right)
        preorder(v, s, root->right);
    s.pop_back();
}
int sumRootToLeaf(TreeNode *root)
{
    vector<string> v;
    string s;
    preorder(v, s, root);
    int ans = 0;
    for (auto i : v)
    {
        ans += stoi(i, 0, 2);
    }
    return ans;
}