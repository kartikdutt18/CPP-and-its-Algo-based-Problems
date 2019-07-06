//https://leetcode.com/problems/remove-nth-node-from-end-of-list/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
ListNode* removeNthFromEnd(ListNode* &head, int n) {
        ListNode*fast =head;
        ListNode* slow=head;
        
        if(head->next==NULL and n==1) return NULL;
        
        while(n--){
            fast=fast->next;
        
        }
        if(fast==NULL){
            return slow->next;
        }
        fast=fast->next;
        while(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
      
        cout<<slow->val;
        if(slow->next!=NULL and slow->next->next!=NULL){
            ListNode*temp=slow->next;
            slow->next=slow->next->next;
            delete temp;
        }
        else{
            slow->next=NULL;
        }
    
return head;}