//https://leetcode.com/contest/weekly-contest-171/problems/number-of-operations-to-make-network-connected/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Graph
{
    int v;
    unordered_map<int, list<int>> adjList;
    vector<int> indegree;
    int dic;

public:
    Graph(int n) : v(n)
    {
        vector<int> indeg(v, 0);
        indegree = indeg;
    }
    void makeGraph(vector<vector<int>> connections)
    {
        dic = 0;
        for (auto edge : connections)
        {
            indegree[edge[0]]++;
            indegree[edge[1]]++;
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        return;
    }
    int zero_indegree()
    {
        return dic > 0 ? dic - 1 : 0;
    }
    int dfs()
    {
        int red_connections = 0;
        vector<bool> visited(v, false);
        vector<int> parent(v, -1);
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                dfsHelper(i, visited, parent, red_connections, -2);
                dic++;
                // cout<<i<<endl;
            }
        }
        //cout<<red_connections<<endl;
        return red_connections / 2;
    }
    void dfsHelper(int src, vector<bool> &visited, vector<int> &parent, int &redC, int curParent)
    {
        if (visited[src] && parent[src] == curParent)
            return;

        visited[src] = true;
        for (auto i : adjList[src])
        {
            if (!visited[i])
            {
                parent[i] = src;
                dfsHelper(i, visited, parent, redC, src);
            }
            else if (visited[i] && parent[i] != src && parent[i] != -1)
                redC++;
        }

        return;
    }
};
class Solution
{
public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        Graph g(n);
        g.makeGraph(connections);
        int j = g.dfs();
        int t = g.zero_indegree();
        if (t > j)
            return -1;

        return min(t, j);
    }
};