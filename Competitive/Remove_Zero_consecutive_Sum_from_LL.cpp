//https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/submissions/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x) , next(NULL) {}
};

ListNode *removeZeroSumSublists(ListNode *head)
{
    if(!head) return head;
    stack<ListNode*> ans;
    while(head){
        if(ans.empty() || ans.top()->val+head->val!=0){
            ans.emplace(head);
        }
            
        else{
            ans.pop();
        }
            
        head=head->next;
    }
    ListNode* ll=new ListNode(0);
    auto fin=ll;
    stack<ListNode*> st2;
    while(!ans.empty()){
        st2.emplace(ans.top());
        ans.pop();
    } 
    while(!st2.empty()){
        ll->next=st2.top();
        st2.pop();
        ll=ll->next;
    }
    ll->next=NULL;

    return fin->next;
}
