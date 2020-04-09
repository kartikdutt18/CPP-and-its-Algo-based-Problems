//https://leetcode.com/problems/n-ary-tree-preorder-traversal/

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

void dfshelper(Node * root,vector<int>& fin){
    if(root==NULL) return;
    fin.push_back(root->val);
    for(auto i: root->children){
            dfshelper(i,fin);
       }
    
}
vector<int> preorder(Node* root) {
       vector<int>ans;
       if(root==NULL) return ans;
       dfshelper(root,ans);
       return ans;
            
}