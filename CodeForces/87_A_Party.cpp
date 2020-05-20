#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  int n;
  cin >> n;
  unordered_map<int, list<int>> adjList;
  queue<int> q;
  for (int i = 1; i <= n; i++)
  {
    int boss;
    cin >> boss;
    if (boss == -1)
      q.push(i);
    else
      adjList[boss].push_back(i);
  }
  // Level Order Traversal.
  int groups = 0;
  while(!q.empty())
  {
    int len = q.size();
    for (int i = 0; i < len; i++)
    {
      int cur = q.front();
      q.pop();
      for (int child : adjList[cur])
        q.push(child);
    }
    groups++;
  }
  cout << groups << endl;
  return 0;
}