//https://leetcode.com/problems/reverse-linked-list-ii/submissions/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
                                   
};

ListNode *reverseBetween(ListNode *head, int m, int n)
{
    ListNode node(0);
    node.next = head;
    ListNode *pHead = &node;
    ListNode *pHead2 = pHead;
    int count = 1;
    while (count != m)
    {
        pHead2 = pHead2->next;
        count++;
    }
    ListNode *temp1 = pHead2->next;
    ListNode *rear = temp1;
    pHead2->next = NULL;
    for (int i = 0; i <= (n - m); i++)
    {
        ListNode *temp2 = temp1->next;
        temp1->next = pHead2->next;
        pHead2->next = temp1;
        temp1 = temp2;
    }
    rear->next = temp1;
    return pHead->next;
}