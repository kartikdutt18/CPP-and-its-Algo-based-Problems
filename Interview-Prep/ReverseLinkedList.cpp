#include <bits/stdc++.h>
using namespace std;

class LinkedList
{
public:
  int value;
  LinkedList *next;

  LinkedList(int value)
  {
    this->value = value;
    this->next = NULL;
  }
};

LinkedList *reverseLinkedList(LinkedList *head)
{
  LinkedList *prev = NULL;
  LinkedList *temp = head;
  while (head)
  {
    temp = head->next;
    head->next = prev;
    prev = head;
    head = temp;
  }
  return prev;
}
