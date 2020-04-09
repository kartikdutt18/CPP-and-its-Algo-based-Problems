//https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/submissions/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
    {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return root;
        queue<pair<Node *, int>> q;
        q.push({root, 0});
        int l = 0;
        while (!q.empty())
        {
            int len = q.size();
            for (int i = 0; i < len; i++)
            {
                auto cur = q.front();
                q.pop();
                auto t = q.front();
                cur.first->next = (cur.second == t.second) ? q.front().first : NULL;
                if (cur.first->left)
                    q.push({cur.first->left, cur.second + 1});
                if (cur.first->right)
                    q.push({cur.first->right, cur.second + 1});
            }
        }
        return root;
    }
};