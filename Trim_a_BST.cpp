//https://leetcode.com/problems/trim-a-binary-search-tree/
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
TreeNode *trimBST(TreeNode *root, int L, int R)
{
    if (!root)
        return root;
    if (root->val > R)
        return trimBST(root->left, L, R);

    if (root->val < L)
        return trimBST(root->right, L, R);

    root->left = trimBST(root->left, L, R);
    root->right = trimBST(root->right, L, R);
    return root;
}

//Delete a Node greater than K -->Microsoft Question (GFG Archive)
/* 
Node *deleteNode(Node *root, int key)
{
    if (root == NULL)
        return NULL;
    if (root->data >= key)
    {
        return deleteNode(root->left, key);
    }

    root->left = deleteNode(root->left, key);
    root->right = deleteNode(root->right, key);
    return root;
}
*/