#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

#include <vector>
using namespace std;

// Do not edit the class below except
// for the depthFirstSearch method.
// Feel free to add new properties
// and methods to the class.
class Node
{
public:
  string name;
  vector<Node *> children;

  Node(string str) { name = str; }

  void DFSHelper(Node *node, vector<string> &array,
                 set<Node *> visited)
  {
    if (visited.count(node))
      return;
    visited.insert(node);
    array.push_back(node->name);
    for (Node *child : node->children)
    {
      if (!visited.count(child))
      {
        DFSHelper(child, array, visited);
      }
    }
    return;
  }
  vector<string> depthFirstSearch(vector<string> *array)
  {
    vector<string> ans;
    set<Node *> ht;
    DFSHelper(this, ans, ht);
    return ans;
  }

  Node *addChild(string name)
  {
    Node *child = new Node(name);
    children.push_back(child);
    return this;
  }
};

int main()
{
  return 0;
}