//https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1
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
bool isIdentical(Node *r1, Node *r2)
{
    if(r1==NULL && r2==NULL) return true;
    if(r1==NULL||r2==NULL) return false;
    if (r1->data != r2->data) return false;
    return isIdentical(r1->right, r2->right) && isIdentical(r1->left, r2->left);
}