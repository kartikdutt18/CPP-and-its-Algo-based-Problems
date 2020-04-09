//
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node() {}

    Node(int _val, Node *_next)
    {
        val = _val;
        next = _next;
    }
};

class Solution
{
public:
    Node *GetTail(Node *head)
    {
        Node *temp = head->next;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        return temp;
    }
    Node *insert(Node *head, int insertVal)
    {
        Node *node = new Node(insertVal,NULL);
        Node *prev = GetTail(head);
        Node *ans = head;
        if(!head){
            node->next=node;
            return node;
        }
        if(head->next==head){
            head->next=node;
            node->next=head;
            if(head->val<insertVal) return head;
            return node;
        }
        if(head->val>insertVal){
            prev->next=node;
            node->next=head;
            return node;
        }
        while (head->val < insertVal)
        {
            prev=head;
            head = head->next;
        }
        prev->next = node;
        node->next = head;
        if (ans->val > insertVal)
            ans = node;
        return ans;
    }
};