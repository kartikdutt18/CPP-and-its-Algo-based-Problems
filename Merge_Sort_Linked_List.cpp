//https://leetcode.com/problems/sort-list/
//https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int len(Node* root){
    int c=0;
    while(root){
        c++;
        root=root->next;
    }
    return c;
}

Node* GetMiddle(Node* root){
    if(root==NULL) return root;
    Node* fast=root;
    Node*slow=fast;
    
}