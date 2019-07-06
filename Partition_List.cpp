#include<iostream>
#include<bits/stdc++.h>
using namespace std;


struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
//Get Tail to insert in O(1)
ListNode* GetTail(ListNode* head){
    ListNode* tail=head;
    while(head){
        tail=head;
        head=head->next;
    }
    return tail;
}
ListNode* insertattail(ListNode* tail,int val){
    ListNode* node=new ListNode(val);
    tail->next=node;
    tail=node;
    return tail;
}
int len(ListNode * head){ 
    int count=0;
    while(head!=NULL){
        head=head->next;
        count++;
    }
    return count;
}

ListNode* partition(ListNode* head, int x) {
   int l=len(head);
   if(head==NULL) return NULL;

   ListNode* prev=head;
   ListNode * tail=GetTail(head);
   ListNode* temp=head;
    while(l--){
        if(temp->val>=x){
            prev->next=temp->next;
            tail=insertattail(tail,temp->val);
        }
        prev=temp;
        temp=temp->next;
    }     
return head;}