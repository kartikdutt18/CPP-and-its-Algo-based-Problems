#include <vector>
using namespace std;

class LinkedList
{
public:
  int value;
  LinkedList *next;

  LinkedList(int value);
  void addMany(vector<int> values);
  vector<int> getNodesInArray();
};

void removeKthNodeFromEnd(LinkedList *node, int k)
{

  LinkedList *fast = node;
  LinkedList *slow = node;

  while (k)
  {
    fast = fast->next;
    k--;
  }
  if (!fast)
  {
    node->value = node->next->value;
    node->next = node->next->next;
    return;
  }

  while (fast->next)
  {
    fast = fast->next;
    slow = slow->next;
  }
  slow->next = slow->next->next;
  return;
}
