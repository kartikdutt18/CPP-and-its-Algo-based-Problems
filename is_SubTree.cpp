//https://practice.geeksforgeeks.org/problems/check-if-subtree/1
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
ch
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

bool isSame(Node *T1, Node *T2)
{
    if (!T1 && !T2)
        return true;
    if (!T1 || !T2)
        return false;
    if (T1->data != T2->data)
        return false;
    return isSame(T1->left, T2->left) && isSame(T1->right, T2->right);
}
bool isSubtree(Node *T1, Node *T2)
{
    if (!T1 && !T2)
        return true;
    if (!T1 || !T2)
        return false;
    if (isSame(T1, T2))
        return true;
    return isSubtree(T1->left, T2) || isSubtree(T1->right, T2);
}