//https://practice.geeksforgeeks.org/problems/circular-linked-list/1
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
};

bool isCircular(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        if (temp->next == head)
            return true;
        temp = temp->next;
    }
    return false;
}
