//https://leetcode.com/problems/clone-graph/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    vector<Node *> neighbors;

    Node() {}

    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};
Node *cloneGraph(Node *node)
{
    Node * newnode=new Node(node->val,{});
    for(auto i:node->neighbors){
        newnode->neighbors.push_back(cloneGraph(i));
    }
    return newnode;
}