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

struct LinkedListPair
{
	LinkedList* head;
	LinkedList* tail;
};

void removeBindings(LinkedList* node)
{
	node->next = NULL;
}
LinkedListPair GrowLinkedList(LinkedListPair& ll, LinkedList* node)
{
	LinkedList* newHead = ll.head;
	LinkedList*newTail = node;
	LinkedList*tail = ll.tail;
	if (!newHead)
		newHead = node;
	if (tail!= NULL)
		tail->next = node;
	return LinkedListPair{newHead, newTail};
}

LinkedListPair ConnectLinkedLists(LinkedListPair& ll1, LinkedListPair& ll2)
{
	LinkedList* newHead = ll1.head == NULL ? ll2.head : ll1.head;
	LinkedList* newTail = ll2.tail == NULL ? ll1.tail : ll2.tail;
		if (ll1.tail!=NULL)
			ll1.tail->next = ll2.head;
	return LinkedListPair{newHead, newTail};
}

LinkedList *rearrangeLinkedList(LinkedList *head, int k) {
  LinkedListPair smallerThanK{NULL, NULL};
	LinkedListPair equalToK{NULL, NULL};
	LinkedListPair greaterThanK{NULL, NULL};

	LinkedList* itr = head;
	while(itr)
	{
		
		if (itr->value == k)
			equalToK = GrowLinkedList(equalToK, itr);
		else if (itr->value > k)
			greaterThanK = GrowLinkedList(greaterThanK, itr);
		else
			smallerThanK = GrowLinkedList(smallerThanK, itr);
		LinkedList* temp = itr;
		itr = itr->next;
		temp->next = NULL;
	}
	
	LinkedListPair first = ConnectLinkedLists(smallerThanK, equalToK);
	LinkedListPair ans = ConnectLinkedLists(first, greaterThanK);
  return ans.head;
}


