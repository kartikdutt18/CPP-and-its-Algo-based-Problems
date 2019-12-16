//https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
                                   
};
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 class Solution
 {
 public:
     int len(ListNode *head)
     {
         int lens = 0;
         while (head)
         {
             head = head->next;
             lens++;
         }
         return lens;
     }
     ListNode *getKthNode(ListNode *head, int k)
     {
         if (k < 0)
             return NULL;
         while (k-- && head)
             head = head->next;
         return head;
     }
     TreeNode *createList(ListNode *head, int start, int end)
     {
         if (end < start)
             return NULL;
         int mid = (start + end) / 2;
         cout << start << " " << mid << " " << end << endl;
         ListNode *middle = getKthNode(head, mid);
         if (!middle)
             return NULL;
         TreeNode *node = new TreeNode(middle->val);
         node->left = createList(head, start, mid - 1);
         node->right = createList(head, mid + 1, end);
         return node;
     }
     TreeNode *sortedListToBST(ListNode *head)
     {
         return createList(head, 0, len(head));
     }
 };