using namespace std;

struct ListNode
{
	int val;
	string key;
	ListNode* next;
	ListNode* prev;
	ListNode(int val, string key = "") :
			val(val),
			key(key),
			prev(NULL),
			next(NULL)
	{
		// Nothing to do here.			
	}
};

// Do not edit the class below except for the insertKeyValuePair,
// getValueFromKey, and getMostRecentKey methods. Feel free
// to add new properties and methods to the class.
class LRUCache {
unordered_map<string, ListNode*> cache;
ListNode* head;
ListNode* tail;
int curSize;

void remove(ListNode* node)
{
	node->prev->next = node->next;
	node->next->prev = node->prev;
	node->next = NULL;
	node->prev = NULL;
	delete node;
}

void insertAtTail(ListNode* node)
{
	node->prev = tail->prev;
	node->next = tail;
	tail->prev->next = node;
	tail->prev = node;
	return;
}

void update(string key, int value)
{
			if (cache.count(key))
			{
				curSize--;
				remove(cache[key]);
			}

			curSize++;
			ListNode* temp = new ListNode(value, key);
			insertAtTail(temp);
			cache[key] = temp;
}
public:
  int maxSize;

  LRUCache(int maxSize) {
		this->maxSize = maxSize > 1 ? maxSize : 1;
		head = new ListNode(-1);
		tail = new ListNode(-1);
		head->next = tail;
		tail->prev = head;
		curSize = 0;
	}

  void insertKeyValuePair(string key, int value) {
    if (curSize >= maxSize)
		{
				cache.erase(head->next->key);
				remove(head->next);
				curSize--;
		}
		update(key, value);
  }

  int *getValueFromKey(string key) {
		if (!cache.count(key))
			return NULL;
    update(key, cache[key]->val);
    return &cache[key]->val;
  }

  string getMostRecentKey() {
    return tail->prev->key;
  }
};

