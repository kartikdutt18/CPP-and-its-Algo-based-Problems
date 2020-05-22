#include <vector>
#include <bits/stdc++.h>
using namespace std;

// Do not edit the class below except
// for the breadthFirstSearch method.
// Feel free to add new properties
// and methods to the class.
class Node
{
public:
  string name;
  vector<Node *> children;

  Node(string str) { name = str; }

  vector<string> breadthFirstSearch(vector<string> *array)
  {
    vector<string> arr;
    queue<Node *> q;
    q.push(this);
    while (!q.empty())
    {
      Node *cur = q.front();
      q.pop();
      arr.push_back(cur->name);
      for (Node *child : cur->children)
        q.push(child);
    }
    return arr;
  }

  Node *addChild(string name)
  {
    Node *child = new Node(name);
    children.push_back(child);
    return this;
  }
};
