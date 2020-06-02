#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        if (!node->next)
        {
           delete node;
            return;
        }
        node->val = node->next->val;
        node->next = node->next->next;
        return;
    }
};

int main()
{

  return 0;
}