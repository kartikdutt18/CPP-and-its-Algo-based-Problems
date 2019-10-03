//CTCI 2.2
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL) {}
};
ListNode* Kth_Node(ListNode* head,int k){
    if(!head) return head;
    ListNode* fast=head;
    ListNode* slow=head;
    while(k-- && fast){
        fast=fast->next;
    }
    while(slow && fast){
        slow=slow->next;
        fast=fast->next;
    }
    return slow->next;
}
//CTCI 2.3
void DeleteMiddle_in_O1(ListNode* &mid){
    if(!mid) return;
    if(!mid->next){
        delete mid;


    }
    mid->val=mid->next->val;
    mid->next=mid->next->next;
    return;
}

//CTCI 2.4 to 2.8 refer LC solutions


