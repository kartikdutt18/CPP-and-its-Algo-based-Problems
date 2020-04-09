//https://practice.geeksforgeeks.org/problems/delete-without-head-pointer/1
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int x) : val(x),next(NULL) {}
};
void deleteNode(Node *node)
{
    node->val = node->next->val;
    node->next = node->next->next;
    return;
}