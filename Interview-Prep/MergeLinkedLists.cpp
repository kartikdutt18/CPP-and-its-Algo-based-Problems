#include <vector>

using namespace std;

// This is an input class. Do not edit.
class LinkedList
{
public:
  int value;
  LinkedList *next;

  LinkedList(int value)
  {
    this->value = value;
    next = NULL;
  }
};

LinkedList *mergeLinkedLists(LinkedList *headOne, LinkedList *headTwo)
{
  LinkedList *dummy = new LinkedList(0);
  LinkedList *ans = dummy;
  while (headOne && headTwo)
  {
    if (headOne->value < headTwo->value)
    {
      dummy->next = headOne;
      headOne = headOne->next;
    }
    else
    {
      dummy->next = headTwo;
      headTwo = headTwo->next;
    }
    dummy = dummy->next;
  }
  if (headOne)
    dummy->next = headOne;
  if (headTwo)
    dummy->next = headTwo;
  return ans->next;
}
