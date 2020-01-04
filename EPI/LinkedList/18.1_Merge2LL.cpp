// 18.1
// Merge 2 Linked List
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
    
};
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if (!l1)
        return l2;
    if (!l2)
        return l1;
    ListNode *head = new ListNode(0);
    ListNode *temp = head;
    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {

            temp->next = l1;
            l1 = l1->next;
        }
        else
        {
            temp->next = l2;
            l2 = l2->next;
        }
        temp = temp->next;
    }
    temp->next=l1?l1:l2;
    return head->next;
}