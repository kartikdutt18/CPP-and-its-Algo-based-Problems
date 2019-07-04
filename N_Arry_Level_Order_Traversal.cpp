//https://leetcode.com/problems/n-ary-tree-level-order-traversal/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

vector<vector<int>> levelOrder(Node* root) {
    if(!root) return {};
    queue<Node*> q;
    q.push(root);
    vector<vector<int>> ans;
    while(!q.empty()){
        int len=q.size();
        vector<int> level={};
        for(int i=0;i<len;i++){
            auto src=q.front();
            q.pop();
            for(auto i:src->children){
                q.push(i);
            }
            level.push_back(src->val);
        }
        ans.push_back(level);
    }
return ans;}