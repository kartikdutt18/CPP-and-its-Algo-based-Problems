//https://leetcode.com/problems/odd-even-linked-list/
//Beats 100% Time->O(N) and Space->O(1)

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
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
ListNode* oddEvenList(ListNode* head) {
    int ind=0;
    int l=len(head);
    if(head==NULL or l==2){
        return head;
    }
    

    ListNode* prev=head;
    ListNode * tail=GetTail(head);
    ListNode* temp=head;
    while(l--){
        if(ind&1){
            prev->next=temp->next;
            tail=insertattail(tail,temp->val);
        }
        ind++;
        prev=temp;
        temp=temp->next;
    }        
return head;}