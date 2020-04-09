//https://leetcode.com/problems/copy-list-with-random-pointer/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node() {}

    Node(int _val, Node *_next, Node *_random)
    {
        val = _val;
        next = _next;
        random = _random;
    }
};

Node *clone(Node *start)
{
    Node *curr = start, *temp;

    // insert additional node after
    // every node of original list
    while (curr)
    {
        temp = curr->next;

        // Inserting node
        curr->next = new Node(curr->val);
        curr->next->next = temp;
        curr = temp;
    }

    curr = start;

    // adjust the random pointers of the
    // newly added nodes
    while (curr)
    {
        if (curr->next)
            curr->next->random = curr->random ? curr->random->next : curr->random;

        // move to the next newly added node by
        // skipping an original node
        curr = curr->next ? curr->next->next : curr->next;
    }

    Node *original = start, *copy = start->next;

    // save the start of copied linked list
    temp = copy;

    // now separate the original list and copied list
    while (original && copy)
    {
        original->next =
            original->next ? original->next->next : original->next;

        copy->next = copy->next ? copy->next->next : copy->next;
        original = original->next;
        copy = copy->next;
    }

    return temp;
}