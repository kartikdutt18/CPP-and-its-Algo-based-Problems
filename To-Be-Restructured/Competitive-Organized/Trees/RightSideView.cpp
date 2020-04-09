//
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
};

vector<int> rightSideView(TreeNode *root)
{
    if (!root)
        return vector<int>();
    vector<int> ans;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        vector<int> curLevel;
        int len = q.size();
        for (int i = 0; i < len; i++)
        {
            auto cur = q.front();
            q.pop();
            curLevel.push_back(cur->val);
            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
        }
        ans.push_back(curLevel.back());
    }
    return ans;
}