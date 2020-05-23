#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL){}
};

bool hasCycle(ListNode *head)
{
  if (!head)
    return false;
  ListNode *fast = head->next;
  ListNode *slow = head;
  while (fast && fast->next && slow->next)
  {
    if (fast == slow)
      return true;
    fast = fast->next->next;
    slow = slow->next;
  }
  return false;
}

int main()
{

  return 0;
}