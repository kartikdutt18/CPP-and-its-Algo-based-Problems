//https://leetcode.com/problems/delete-node-in-a-bst/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode * right;
    TreeNode(int x): val(x),left(NULL),right(NULL) {}
};
TreeNode *deleteNode(TreeNode *root, int key)
{
    if (!root)
        return NULL;
    if (key < root->val)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->val)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        //single or no child case
        if (!root->left || !root->right)
        {
            TreeNode *next = root->left ? root->left : root->right;
            delete root;
            return next;
        }
        //two children case
        TreeNode *curr = root->right;
        while (curr->left)
            curr = curr->left;
        root->val = curr->val;
        root->right = deleteNode(root->right, curr->val); //delete curr node
    }
    return root;
}