//https://practice.geeksforgeeks.org/problems/minimum-element-in-bst/1
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

int minValue(Node *root)
{
    while(root->left){
        root=root->left;
    }
    return root->data;
}