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
    ListNode*temp=head;
    while(k--){
        temp=head;
        head=head->next;
    }
    return head,temp;
}  
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *prev=NULL;
    int len1=len(l1);
    int len2=len(l2);
    
    if(l1>l2){
        l1,prev=Kthnode(l1,len1-len2);
    }
    else if(l2>l1){
        l2,prev=Kthnode(l2,len2-len1-1);
        
    }
    int sum=l1->val+l2->val;
    int carry=0;
    if(sum>=10){
        sum=sum-10;
        carry=1;
    }
    ListNode * head = new ListNode(sum);
    if(carry==1){
      ListNode * nhead=new ListNode(1);
      carry=0;
      nhead->next=head;
      head=nhead;  
    }
    prev=head;
    ListNode* temp=head;
    while(l1 and l2){
        sum=l1->val+l2->val;
        if(sum>=10){
            sum=sum-10;
            prev->val=prev->val+1;
            carry=0;
        }
        ListNode* node=new ListNode(sum);
        prev=temp;
        temp->next=node;
        temp=node;
        l1=l1->next;
        l2=l2->next;
    }
    
    return head;
}