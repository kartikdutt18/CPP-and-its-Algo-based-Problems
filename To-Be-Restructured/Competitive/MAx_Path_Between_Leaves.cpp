//https://practice.geeksforgeeks.org/problems/maximum-path-sum/1
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
};
int ConvertTree(Node *root, int &ans)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL and root->right == NULL)
        return root->data;

    int leftsum = ConvertTree(root->left, ans);
    int rightsum = ConvertTree(root->right, ans);

    ans = max(ans, root->data + leftsum + rightsum);
    return max(leftsum, rightsum) + root->data;
}

int maxPathSum(struct Node *root)
{
    int ans = INT_MIN;
    ConvertTree(root, ans);
    return ans;
}

