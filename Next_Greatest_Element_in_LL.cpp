//https://leetcode.com/problems/next-greater-node-in-linked-list/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
int len(ListNode* head){
    int cnt=0;
    while(head){
        head=head->next;
        cnt++;
    }
    return cnt;
}
vector<int> nextLargerNodes(ListNode* head) {
    if(not head) return {};
    stack<pair<int,int>> s;
    vector<int> ans(len(head),0);
    int i=0;
    while(head){
        if(s.empty()) s.push(make_pair(head->val,i));
        while(not(s.empty()) and s.top().first<head->val){
           ans[s.top().second]=head->val;
           s.pop(); 
        }
        s.push(make_pair(head->val,i));
        head=head->next;
        i++;
    }
    return ans;
}