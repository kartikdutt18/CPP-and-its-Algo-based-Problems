//https://www.spoj.com/problems/AKBAR/
#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Graph
{
  int cities;
  unordered_map<int, list<int>> adjList;
  int soldiers;
  queue<pair<int,int>> q;
  public:
  void makeGraph()
  {
    cin>>cities;
    int edges;
    cin>>edges>>soldiers;
    for(int i=0;i<edges;i++)
    {
      int a,b;
      cin>>a>>b;
      adjList[a].push_back(b);
      adjList[b].push_back(a);
    }

    for(int i = 0;i<soldiers;i++)
    {
      int a,b;
      cin>>a>>b;
      q.push({a,b});
    }
  }

  bool bfs()
  {
    vector<bool> visited(cities+1,false);
    visited[0]=true;
    while(!q.empty())
    {
      auto cur = q.front();
      q.pop();
      if(visited[cur.first])
        return false;
      visited[cur.first]=true;
      if(cur.second > 0)
      {
        for(auto child:adjList[cur.first])
        {
          if(!visited[child])
            q.push({child, cur.second - 1});
          else
          {
            return false;
          }
          
          
        }
      }
    }
    return accumulate(visited.begin(),visited.end(),0)==cities+1;
  }
};

int main() {
  
  
  ll t;
  cin>>t;
  while(t--)
  {
    Graph g;
    g.makeGraph();
    if(g.bfs())
      cout<<"Yes\n";
    else
    {
      cout<<"No\n";
    }
  }
  return 0;
}