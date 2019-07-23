//https://practice.geeksforgeeks.org/problems/mirror-tree/1
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int x): data(x),left(NULL),right(NULL) {}
};

void mirror(Node *node)
{   if(node==NULL) return;
    swap(node->right,node->left);
    mirror(node->right);
    mirror(node->left);
    return;
}