//https://leetcode.com/problems/intersection-of-two-linked-lists/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

int len(ListNode * head){ 
    int count=0;
    while(head!=NULL){
        head=head->next;
        count++;
    }
    return count;
}
ListNode *Kthnode(ListNode *head,int k){
    while(k--){
        head=head->next;
    }
    return head;
}  
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
    int l1=len(headA);
    int l2=len(headB);
    if(l1>l2){
        headA=Kthnode(headA,l1-l2);
    }
    else if(l2>l1){
        headB=Kthnode(headB,l2-l1);
    }
    while(headA!=NULL and headB!=NULL){
        if(headA==headB) return headA;
        headA=headA->next;
        headB=headB->next;
    }
    return NULL;
}