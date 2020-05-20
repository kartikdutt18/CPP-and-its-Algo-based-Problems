#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct Node
{
  int val;
  int maxConseq;
  list<int> children;
};
int main()
{
  int n, m;
  cin >> n >> m;
  unordered_map<int, Node> adjList;
  for (int i = 0; i < n; i++)
  {
    int hasCat;
    cin >> hasCat;
    adjList[i+1].val= hasCat;
    adjList[i+1].maxConseq = hasCat;
  }
  for (int i = 1; i < n; i++)
  {
    int v1, v2;
    cin >> v1 >> v2;
    adjList[v1].children.push_back(v2);
    adjList[v2].children.push_front(v1);
  }
  queue<int> q;
  q.push(1);
  int ans = 0;
  vector<int> visited(n + 1, 0);
  while(!q.empty())
  {
    
    int curNode = q.front();
    q.pop();
    visited[curNode] = 1;
    if (adjList[curNode].children.size() == 1 && visited[adjList[curNode].children.front()])
    {
      ans += (adjList[curNode].maxConseq <= m);
    }
    for(int child: adjList[curNode].children)
    {
      if (adjList[child].val && adjList[curNode].val)
      {
        adjList[child].val += adjList[curNode].val;
        adjList[child].maxConseq = max(adjList[curNode].maxConseq,
            adjList[child].val);
      }
      else
      {
        adjList[child].maxConseq = max(adjList[child].maxConseq,
            adjList[curNode].maxConseq);
      }
      if (!visited[child])
        q.push(child);
    }
  }
  cout << ans << endl;
  return 0;
}