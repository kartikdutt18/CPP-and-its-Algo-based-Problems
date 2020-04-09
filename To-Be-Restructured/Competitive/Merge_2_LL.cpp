//https://leetcode.com/problems/merge-two-sorted-lists/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
                                   
};

    class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {

        if (l1 == NULL and l2 == NULL)
        {
            return NULL;
        }
        else if (l2 != NULL and l1 == NULL)
        {
            return l2;
        }
        else if (l1 != NULL and l2 == NULL)
        {
            return l1;
        }
        else if (l1 != NULL and l2 != NULL)
        {
            if (l1->val < l2->val)
            {
                ListNode *head = new ListNode(l1->val);

                head->next = mergeTwoLists(l1->next, l2);
                return head;
            }
            else
            {
                ListNode *head = new ListNode(l2->val);
                head->next = mergeTwoLists(l1, l2->next);
                return head;
            }
        }

        return NULL;
    }
};