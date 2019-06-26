//https://leetcode.com/problems/linked-list-components/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
int numComponents(ListNode* head, vector<int>& G){
            unordered_set<int> st (G.begin (), G.end ());

            int count=0;
       
            while(head!=NULL){
                if (st.count(head->val) && (head->next == NULL || !st.count(head->next->val))) count++;
            head = head->next;
 
                

            }
 
            return count;
}