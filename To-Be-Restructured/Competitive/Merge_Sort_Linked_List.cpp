//https://leetcode.com/problems/sort-list/
//https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};


void PartitionMiddle(Node* root,Node* &ini,Node* &ini2){
    if(root==NULL) return ;
    Node* fast=root->next;
    Node*slow=root;
    while(fast->next && fast->next->next){
        fast=fast->next->next;
        slow=slow->next;
    }
    ini=root;
    ini2=slow->next;
    slow->next=NULL;
}

Node*sortedMerge(Node * a,Node*b){
    Node* ans=NULL;
    if(a==NULL) return b;
    if(b==NULL) return a;
    if(a->data<b->data){
        ans=a;
        ans->next=sortedMerge(a->next,b);
    }
    else{
        ans=b;
        ans->next=sortedMerge(a,b->next);
    }
    return ans;
}
void MergeSort(Node * &head){
    Node* a;
    Node* b;
    if(head==NULL || head->next==NULL) return;
    PartitionMiddle(head,a,b);
    MergeSort(a);
    MergeSort(b);
    head=sortedMerge(a,b);
}