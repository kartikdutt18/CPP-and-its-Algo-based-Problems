//https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
                                               
};

class FindElements
{
    set<int> values;

public:
    FindElements(TreeNode *root)
    {
        if (!root)
            return;
        root->val = 0;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();
            values.insert(cur->val);
            if (cur->left)
            {
                cur->left->val = 2 * cur->val + 1;
                q.push(cur->left);
            }
            if (cur->right)
            {
                cur->right->val = 2 * cur->val + 2;
                q.push(cur->right);
            }
        }
        return;
    }

    bool find(int target)
    {
        return values.count(target);
    }
};