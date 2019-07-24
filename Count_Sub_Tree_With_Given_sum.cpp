//https://practice.geeksforgeeks.org/problems/count-number-of-subtrees-having-given-sum/1
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
int ConvertTree(Node *&root)
{
    if (root == NULL)
        return 0;
    int temp = root->data;
    int lsum = ConvertTree(root->left);
    int rsum = ConvertTree(root->right);
    root->data = lsum + rsum;
    return temp + root->data;
}
int GetCount(Node *root, int x)
{
    if (root == NULL)
        return 0;
    int ans = 0;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *cur = q.front();
        q.pop();
        if (cur->data == x)
            ans++;
        if (cur->right)
            q.push(cur->right);
        if (cur->left)
            q.push(cur->left);
    }
    return ans;
}
int countSubtreesWithSumX(Node *root, int x)
{
    if (!root)
        return 0;
    ConvertTree(root);
    cout << GetCount(root, x) << endl;
}
