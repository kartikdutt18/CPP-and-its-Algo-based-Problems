//https://practice.geeksforgeeks.org/problems/union-of-two-linked-list/1
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
    node(int x)
    {
        data = x;
        next = NULL;
    }
};
void insertattail(int val,node* &head,node*&tail){
    node *Node=new node(val);
    if(head==NULL){
        head=Node;
        tail=Node;
    }
    tail->next=Node;
    tail=Node;
}
void push(node** head,int i);
struct node *makeUnion(struct node *head1, struct node *head2)
{   node* temp=head1;
    set<int> s;
    while(temp){
        s.insert(temp->data);
        temp=temp->next;
    }
    temp=head2;
    while (temp)
    {
        s.insert(temp->data);
        temp = temp->next;
    }
    node*tail=NULL;
    node*head=NULL;
    for (auto itr = s.rbegin(); itr != s.rend(); itr++)
    {

        push(&head, *itr);
    }
    return head;
}
