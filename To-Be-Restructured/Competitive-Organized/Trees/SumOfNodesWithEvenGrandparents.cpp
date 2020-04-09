//
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution
{
public:
    void sumTree(TreeNode *root, int &sum, bool evenParent, bool evenGrandParent)
    {
        if (!root)
            return;
        if (evenGrandParent)
            sum += root->val;
        if (root->left)
        {
            sumTree(root->left, sum, root->val % 2 == 0, evenParent);
        }
        if (root->right)
            sumTree(root->right, sum, root->val % 2 == 0, evenParent);
        return;
    }
    int sumEvenGrandparent(TreeNode *root)
    {
        int sum = 0;
        sumTree(root, sum, false, false);
        return sum;
    }
};