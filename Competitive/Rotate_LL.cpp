//https://leetcode.com/problems/rotate-list/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
int len(ListNode* head){
    int l=0;
    while(head!=NULL){
        head=head->next;
        l+=1;
    }
    return l;
}
ListNode* KthNode(ListNode * head,int k){
    ListNode* knode=head;
    
    while(k--){
        knode=knode->next;
    }
    return knode;
}
ListNode* GetTail(ListNode *head){
    ListNode* fast=head;
    ListNode * slow=NULL;
    while(fast!=NULL){
        slow=fast;
        fast=fast->next;
    }
    return slow;
}
ListNode* rotateRight(ListNode* head, int k) {
        int l=len(head);
        if(l==0) return head;
        k=k%l;
        ListNode*ans=head;
        if(k){
            ListNode *knode=KthNode(head,l-k-1);
            ListNode *tail=GetTail(head);
            ans=knode->next;
            tail->next=head;
            knode->next=NULL;

        }
    return ans;
}