//
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode*next;
    ListNode(int x) : val(x), next(NULL) {}
};
int len(ListNode *head)
{
    int cnt = 0;
    while (head)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
}

vector<ListNode *> splitListToParts(ListNode *root, int k)
{
    int length = len(root);
    vector<ListNode *> v(k,NULL);
    ListNode *cur = root;
    int i=0;

    while (cur)
    {
        int elements = length / k;
        if (length % k)
            elements++;

        length -= elements;
        k--;
        v[i++]=cur;
        while (--elements && cur)    cur = cur->next;
        
        if (cur)
        {
            ListNode *prev = cur->next;
            cur->next = NULL;
            cur = prev;
        }
    }
    return v;
}