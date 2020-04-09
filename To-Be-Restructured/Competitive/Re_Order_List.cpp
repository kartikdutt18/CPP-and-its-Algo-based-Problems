//https://leetcode.com/problems/reorder-list/submissions/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};
void reorderList(ListNode *head)
{
    vector<ListNode *> LL;
    ListNode *temp = head;
    while (temp)
    {
        LL.emplace_back(temp);
        auto t = temp->next;
        temp->next = NULL;
        temp = t;
    }
    int i = 0;
    int j = LL.size() - 1;

    while (i < j)
    {
        if (i + 1 < j)
        {
            LL[i]->next = LL[j];
            LL[j]->next = LL[i + 1];
        }
        else
        {
            if (LL.size() & 1)
                LL[i]->next = NULL;
            else
                LL[i]->next = LL[j];
        }
        i++;
        j--;
    }
}