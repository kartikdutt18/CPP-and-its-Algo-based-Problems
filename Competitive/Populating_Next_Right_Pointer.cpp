//https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
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

Node *connect(Node *root)
{
    if(!root) return root;
    queue<pair<int,Node*>> q;
    q.push({0,root});
    while(!q.empty()){
        int len=q.size();
        for(int i=0;i<len;i++){
            auto cur=q.front();
            q.pop();
            cur.second->next = NULL;
            if(q.empty()==false && q.front().first==cur.first){
                cur.second->next=q.front().second;
            }
            if(cur.second->left) q.push({cur.first+1,cur.second->left});
            if(cur.second->right) q.push({cur.first+1,cur.second->right});
        }
    }
    return root;
}