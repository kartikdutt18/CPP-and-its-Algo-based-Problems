//https://practice.geeksforgeeks.org/problems/maximum-width-of-tree/1
//https://leetcode.com/problems/maximum-width-of-binary-tree/
//Gives WA in LC
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
int levelOrder(Node *root)
{
    if (root == NULL)
        return {};
    int ans = 0;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {

        int l = q.size();
        ans = max(ans, l);

        for (int i = 0; i < l; i++)
        {
            Node *cur = q.front();
            q.pop();
            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
        }
    }

    return ans;
}