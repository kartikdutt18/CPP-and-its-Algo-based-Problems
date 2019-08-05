//https://leetcode.com/problems/binary-search-tree-iterator/solution/
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

class BSTIterator
{
    vector<TreeNode *> adjlist;
    int i;

public:
    void LL_Builder(TreeNode *root)
    {
        if (!root)
            return;
        if (root->left)
        {

            LL_Builder(root->left);
        }
        adjlist.push_back(root);
        if (root->right)
        {

            LL_Builder(root->right);
        }
        return;
    }
    BSTIterator(TreeNode *root)
    {
        LL_Builder(root);
        i = 0;
        for (auto j : adjlist)
            cout << j->val << " ";
    }

    /** @return the next smallest number */
    int next()
    {
        int ans = adjlist[i]->val;
        i++;
        return ans;
    }

    /** @return whether we have a next smallest number */
    bool hasNext()
    {
        return i != adjlist.size();
    }
};