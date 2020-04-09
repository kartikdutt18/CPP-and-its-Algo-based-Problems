#include<iostream>
#include<bits/stdc++.h>
using namespace std;


struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
//Get Tail to insert in O(1)

    //To insert in O(1)
pair<ListNode *, int>  GetTail(ListNode *head)
{
    if (head == NULL)
        return pair(head, 0);
    int len = 0;
    while (head->next)
    {
        head = head->next;
        len++;
    }
    return pair(head, len);
}
ListNode *InsertAtTail(ListNode *tail, int d)
{
    ListNode *node = new ListNode(d);
    tail->next = node;
    tail = node;
    return tail;
}
ListNode *partition(ListNode *head, int x)
{
    if (head == NULL)
        return head;
    pair<ListNode *, int> p = GetTail(head);
    int l = p.second + 1;
    ListNode *dummy = new ListNode(INT_MIN);
    dummy->next = head;
    ListNode *tail = p.first;
    ListNode *fast = head;
    ListNode *slow = dummy;
    while (l--)
    {
        if (fast->val >= x && slow->val < x)
        {
            tail = InsertAtTail(tail, fast->val);
            slow->next = fast->next;
            fast = fast->next;
        }
        else
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    return dummy->next;
}
