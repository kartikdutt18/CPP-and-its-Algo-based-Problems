//https://leetcode.com/problems/linked-list-cycle-ii/
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
    ListNode *detectCycle(ListNode *head)
    {
        if (!head)
            return NULL;
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast && slow && fast->next)
        {

            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
            {
                break;
            }
        }
        if (fast == NULL || fast->next == NULL)
            return NULL;

        slow = head;
        while (slow != fast && fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};