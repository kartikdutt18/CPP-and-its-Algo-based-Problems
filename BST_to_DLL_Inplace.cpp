//https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node() {}

    Node(int _val, Node *_left, Node *_right)
    {
        val = _val;
        left = _left;
        right = _right;
    }
};

Node *treeToDoublyList(Node *root)
{
    
}