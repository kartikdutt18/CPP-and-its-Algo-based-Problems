//
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;

    Node() {}

    Node(int _val, Node *_prev, Node *_next, Node *_child)
    {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};

Node *flatten(Node *head)
{
    Node *cur = head;
    while (cur)
    {
        if (cur->child)
        {
            Node *next = cur->next;
            Node *child = flatten(cur->child);
            cur->child = NULL;
            cur->next = child;
            child->prev = cur;
            while (cur->next)
            {
                cur = cur->next;
            }
            cur->next = next;
            if (next)
            {
                next->prev = cur;
            }
        }
        cur = cur->next;
    }
    return head;
}