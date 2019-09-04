//
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph
{
    map<int, list<int>> adjlist;
    int v;
    vector<int> indegree;
    vector<vector<int>> parent;

public:
    Graph(int v)
    {
        this->v = v;
        indegree = vector<int>(v, 0);
        parent=vector<vector<int>>(v);
    }
    void addEdge(int u, int v)
    {
        adjlist[u].push_back(v);
        indegree[v]++;
        parent[v].push_back(u);
    }
    bool CycleDetect(){
        bool ans=true;
        for(int i=0;i<v;i++){
            ans&=(parent[v].size()<2);
        }
    return ans;
    }
};

bool validTree(int n, vector<vector<int>> &edges)
{
    Graph g(n);
    for(auto edge:edges){
        g.addEdge(edge[0],edge[1]);
    }
    return g.CycleDetect();
}