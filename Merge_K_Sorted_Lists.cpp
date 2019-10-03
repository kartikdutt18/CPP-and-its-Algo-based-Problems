//https://leetcode.com/problems/merge-k-sorted-lists/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

ListNode *mergeKLists(vector<ListNode *> &lists)
{

    priority_queue<ListNode *, vector<ListNode *>, function<bool(ListNode *, ListNode *)>> pq([](ListNode *a, ListNode *b) -> bool { return a->val > b->val; });
    for (int i = 0; i < lists.size(); i++)
    {
        if (lists[i])
            pq.emplace(lists[i]);
    }
    ListNode *head = new ListNode(0);
    ListNode *ll = head;
    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        head->next = top;
        head = head->next;
        if (top && top->next)
            pq.emplace(top->next);
    }
    return ll->next;
}