//https://practice.geeksforgeeks.org/problems/k-distance-from-root/1
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
void printKdistance(Node *root, int k)
{   if(root==NULL) return;
    queue<pair<Node*,int>> q;
    q.push(pair(root,0));
    while(!q.empty()){
        auto p=q.front();
        q.pop();
        if(p.second==k) cout<<p.first->data<<" ";
        if(p.first->left)
            q.push(pair(p.first->left,p.second+1));
        if (p.first->right)
            q.push(pair(p.first->right, p.second + 1));
    }
return ;}