//https://leetcode.com/problems/plus-one-linked-list/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
    
};
ListNode* reverse(ListNode* head){
    if(!head || !head->next) return head;
    ListNode* prev=NULL;
    while(head){
        ListNode* temp=head->next;
        head->next=prev;
        prev=head;
        head=temp;
    }
    return prev;
}
ListNode *plusOne(ListNode *head)
{
    ListNode* newhead=reverse(head);
    ListNode* temp=newhead;
    int carry=1;
    
    while(carry && temp){
        int sum=temp->val+carry;
        carry=0;
        if(sum>10){
            carry=1;
            sum-=10;
        }
        temp->val=sum;
        temp=temp->next;
    }
    ListNode* ans=reverse(newhead);
    if(carry){
        ListNode* p=new ListNode(1);
        carry=0;
        p->next=ans;
        ans=p;
    }
    return ans;
}