//CTCI 2.1
//https://leetcode.com/problems/remove-duplicates-from-sorted-list/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x),next(NULL) {}
};

ListNode *deleteDuplicates(ListNode *head)
{
    if(!head) return head;
    ListNode* temp=head;
    while(head->next){
        if(head->val==head->next->val) head->next=head->next->next;
        head=head->next;
    }
    return temp;
}

