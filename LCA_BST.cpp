//https : //practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1
#include<iostream>
#include<bits/stdc++.h>
        using namespace std;
struct Node
{
    int data;
    Node *right;
    Node *left;

    Node(int x)
    {
        data = x;
        right = NULL;
        left = NULL;
    }
};
Node *LCA(Node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;

    // If both n1 and n2 are smaller than root, then LCA lies in left
    if (root->data > n1 && root->data > n2)
        return LCA(root->left, n1, n2);

    // If both n1 and n2 are greater than root, then LCA lies in right
    if (root->data < n1 && root->data < n2)
        return LCA(root->right, n1, n2);
    return root;
}