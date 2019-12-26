//https://leetcode.com/contest/weekly-contest-100/problems/increasing-order-search-tree/
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
// Time: O(N)
// Space: O(H)
class Solution
{
public:
    TreeNode *dummy;
    void inOrderTraversal(TreeNode *root)
    {
        if (!root)
            return;
        if (root->left)
            inOrderTraversal(root->left);
        root->left = NULL;
        dummy->right = root;
        dummy = dummy->right;
        if (root->right)
            inOrderTraversal(root->right);
        return;
    }
    TreeNode *increasingBST(TreeNode *root)
    {
        vector<int> v;
        TreeNode *ans = new TreeNode(0);
        dummy = ans;
        inOrderTraversal(root);
        return ans->right;
    }
};
// Time: O(N)
// Space: O(N)
class Solution
{
public:
    void inOrderTraversal(TreeNode *root, vector<int> &v)
    {
        if (!root)
            return;
        if (root->left)
            inOrderTraversal(root->left, v);
        v.push_back(root->val);
        if (root->right)
            inOrderTraversal(root->right, v);
        return;
    }
    TreeNode *increasingBST(TreeNode *root)
    {
        vector<int> v;
        inOrderTraversal(root, v);
        TreeNode *dummy = new TreeNode(0);
        TreeNode *node = dummy;
        for (auto i : v)
        {
            TreeNode *newNode = new TreeNode(i);
            dummy->right = newNode;
            dummy = dummy->right;
        }
        return node->right;
    }
};