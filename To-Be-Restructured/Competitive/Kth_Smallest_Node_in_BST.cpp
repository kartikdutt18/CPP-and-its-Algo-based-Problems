//https://leetcode.com/problems/kth-smallest-element-in-a-bst/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x),right(NULL),left(NULL) {}
};
int kthSmallest(TreeNode *root, int k)
{
    if(root==NULL) return 0;
    stack<TreeNode*> s;
    list<int> ll;
    s.push(root);
    TreeNode* cur=s.top();
    while(!s.empty() && k){
        while(cur){
            s.push(cur);
            cur=cur->left;
        }
        cur=s.top();
        s.pop();
        k--;
        ll.push_back(cur->val);
        cur=cur->right;
    }
    return ll.back();
}
    
