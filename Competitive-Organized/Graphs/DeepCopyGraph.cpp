//https://leetcode.com/problems/clone-graph
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    vector<Node *> neighbors;

    Node() {}

    Node(int _val, vector<Node *> _neighbors = {})
    {
        val = _val;
        neighbors = _neighbors;
    }
};
Node *cloneGraph(Node *node)
{
    if (!node)
        return node;
    queue<Node *> q;
    unordered_map<Node *, Node *> bfsMap;
    q.push(node);
    Node *newGraph = new Node(node->val);
    bfsMap[node] = newGraph;
    while (!q.empty())
    {
        auto curNode = q.front();
        q.pop();
        for (auto neighbor : curNode->neighbors)
        {

            if (!bfsMap.count(neighbor))
            {
                Node *newNode = new Node(neighbor->val);
                bfsMap[neighbor] = newNode;
                q.push(neighbor);
            }
            bfsMap[curNode]->neighbors.push_back(bfsMap[neighbor]);
        }
    }
    return newGraph;
}