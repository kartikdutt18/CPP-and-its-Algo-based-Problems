//https://leetcode.com/problems/swap-nodes-in-pairs/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
                                   
};
ListNode *swapPairs(ListNode *head)
{
    if(head==NULL or head->next==NULL) return head;
    ListNode *remaing = head->next->next;
    ListNode* newhead=head->next;
    newhead->next=head;
    head->next=swapPairs(remaing);
    return newhead;

}
