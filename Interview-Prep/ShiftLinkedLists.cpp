using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value) {
    this->value = value;
    next = NULL;
  }
};


int GetLength(LinkedList* head)
{
	int len = 0;
	while(head)
	{
		head = head->next;
		len++;
	}
	return len;
}
LinkedList *shiftLinkedList(LinkedList *head, int k) {
 int len = GetLength(head);
 if (k < 0)
 {
	 k = len - (abs(k) % len);
 }
 k = k % len;
 if (k == 0)
	 return head;
	// Get Kth Element from LL.
	LinkedList* fast = head;
	while (fast && k--)
	{
		fast = fast->next;
	}
	if (!fast)
	{
		// reverse Linked List;
		return head;
	}

	LinkedList*slow = head;
	while(fast->next)
	{
		slow = slow->next;
		fast = fast->next;
	}
	cout << slow->value << endl;
	fast = slow->next;
	LinkedList* ans = fast;
	slow->next = NULL;
	while(fast->next)
	{
		fast = fast->next;
	}
	fast->next = head;
	return ans;
}

