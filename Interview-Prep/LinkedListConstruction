using namespace std;

class Node {
public:
  int value;
  Node *prev;
  Node *next;

  Node(int value);
};

// Feel free to add new properties and methods to the class.
class DoublyLinkedList {
public:
  Node *head;
  Node *tail;

  DoublyLinkedList() {
    head = NULL;
    tail = NULL;
  }

  void setHead(Node *node) {
		if (head == NULL)
		{
			head = node;
			tail = node;
			return;
		}
		insertBefore(head, node);
  }

  void setTail(Node *node) {
    if (!tail)
		{
			setHead(node);
			return;
		}
		insertAfter(tail, node);
  }

  void insertBefore(Node *node, Node *nodeToInsert) {
    if (nodeToInsert == head && nodeToInsert == tail)
				return;
		remove(nodeToInsert);
		nodeToInsert->next = node;
		nodeToInsert->prev = node->prev;
		if (node->prev == NULL)
		{
			head = nodeToInsert;
		}
		else
		{
			node->prev->next = nodeToInsert;
		}
		node->prev = nodeToInsert;
  }

  void insertAfter(Node *node, Node *nodeToInsert) {
    if (nodeToInsert == head && nodeToInsert == tail)
				return;
		remove(nodeToInsert);
		nodeToInsert->next = node->next;
		nodeToInsert->prev = node;
		if (node->next)
		{
			node->next->prev = nodeToInsert;
		}
		else
		{
			tail = nodeToInsert;
		}
		node->next = nodeToInsert;
  }

  void insertAtPosition(int position, Node *nodeToInsert) {
    if (position == 1)
			return setHead(nodeToInsert);

		Node* insertBeforeEl = head;
		position--;
		while(insertBeforeEl && position--)
		{
			insertBeforeEl=insertBeforeEl->next;
		}
		if (!insertBeforeEl)
		{
			setTail(nodeToInsert);
			return;
		}
		insertBefore(insertBeforeEl, nodeToInsert);
  }

  void removeNodesWithValue(int value) {
    Node* itr = head;
		while(itr)
		{
			if (itr->value == value)
			{
				Node* temp = itr;
				itr = itr->next;
				remove(temp);
			}
			else
				itr = itr->next;
		}
  }

  void remove(Node *node) {
    if (node == head)
			head = head->next;
		if (node == tail)
			tail = tail->prev;
		removeNodeBindings(node);
  }

	void removeNodeBindings(Node* node)
	{
		if (node->prev)
			node->prev->next = node->next;
		if (node->next)
			node->next->prev = node->prev;
		node->prev = NULL;
		node->next = NULL;
		return;
	}
	
  bool containsNodeWithValue(int value) {
		Node* itr = head;
		while(itr)
		{
			if (itr->value == value)
				return true;
			itr = itr->next;
		}
    return false;
  }
};

