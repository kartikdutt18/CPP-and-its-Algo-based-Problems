#include<iostream>
#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode
{
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode *head = NULL;
ListNode *curNode = NULL;

void buildLL(TreeNode *root)
{
  if (!root)
    return;
  if (root->left)
    buildLL(root->left);
  if (!curNode)
  {
    curNode = new ListNode(root->val);
    head = curNode;
  }
  else
  {
    curNode->next = new ListNode(root->val);
    curNode = curNode->next;
  }
  if (root->right)
    buildLL(root->right);
  return;
}

class BSTIterator
{
public:
  BSTIterator(TreeNode *root)
  {

    head = NULL;
    curNode = NULL;
    buildLL(root);
  }

  /** @return the next smallest number */
  int next()
  {
    int val = head->val;
    head = head->next;
    return val;
  }

  /** @return whether we have a next smallest number */
  bool hasNext()
  {
    return head != NULL;
  }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main()
{
  ios::sync_with_stdio(false);
  return 0;
}