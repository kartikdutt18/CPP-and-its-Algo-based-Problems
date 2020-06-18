#include <vector>
using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value);
};

LinkedList *findLoop(LinkedList *head) {
  LinkedList* slow = head;
	LinkedList* fast = head->next;
	while(fast && fast->next)
	{
		fast = fast->next;
		slow = slow->next;
		if (slow == fast)
			break;
		
		if (fast && fast->next)
			fast = fast->next;
		else
			break;
	}
	if (!fast || !fast->next)
		return NULL;

	fast = head;
	while(slow!=fast)
	{
		fast = fast->next;
		slow = slow->next;
	}
  return slow;
}

