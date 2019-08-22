//https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Graph
{
    map<int, list<int>> adjlist;
    vector<bool> visited;
    int v;

public:
    Graph(int x) : v(x){};
    void addEdge(int u, int v)
    {
        adjlist[u].push_back(v);
        visited.reserve(v + 1);
    }
    int dfs()
    {
        int count = 0;

        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                dfshelper(i);
                count++;
            }
        }
        return count;
    }
    void dfshelper(int src)
    {
        visited[src] = true;
        for (auto j : adjlist[src])
        {
            if (!visited[j])
                dfshelper(j);
        }
        return;
    }
};
class Solution
{
public:
    int countComponents(int n, vector<vector<int>> &edges)
    {
        if (edges.size() == 0)
            return 1;
        Graph g(n);
        for (auto i : edges)
        {
            g.addEdge(i[0], i[1]);
            g.addEdge(i[1],i[0]);
        }
        return g.dfs();
    }
};