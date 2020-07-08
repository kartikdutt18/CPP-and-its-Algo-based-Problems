#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool compare(ListNode *node1, ListNode *node2)
{
  return node1->val >= node2->val;
}

class Solution
{
public:
  ListNode *mergeKLists(vector<ListNode *> &lists)
  {
    priority_queue<ListNode *, vector<ListNode *>, decltype(&compare)> pq(compare);
    for (ListNode *node : lists)
    {
      if (node)
        pq.push(node);
    }
    ListNode *temp = new ListNode(0);
    ListNode *ans = temp;
    while (!pq.empty())
    {
      ListNode *curNode = pq.top();
      pq.pop();
      if (curNode->next)
        pq.push(curNode->next);
      curNode->next = NULL;
      temp->next = curNode;
      temp = temp->next;
    }
    return ans->next;
  }
};

int main()
{
  return 0;
}