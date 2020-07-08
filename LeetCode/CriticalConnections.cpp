#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct Node
{
  int val = INT_MAX;
  int lowVal = INT_MAX;
  int id = -1;
  bool visited = false;
};

class Graph
{
    unordered_map<int, list<int>> adjList;
    vector<Node> graphDetails;
    vector<vector<int>> criticalConnections;
    int id;
    int n;

    void DFSHelper(int src, int parent)
    {
        if (src > n || graphDetails[src].visited)
            return;
        graphDetails[src].visited = true;
        graphDetails[src].id = id;
        graphDetails[src].lowVal = id;
        id++;
        for (int child : adjList[src])
        {
            if (!graphDetails[child].visited)
            {
                DFSHelper(child, src);
                if (graphDetails[child].lowVal > graphDetails[src].id)
                    criticalConnections.push_back({src, child});
                graphDetails[src].lowVal = min(graphDetails[src].lowVal, graphDetails[child].lowVal);
            }
            else if (child != parent)
            {
                graphDetails[src].lowVal = min(graphDetails[src].lowVal,
                                               graphDetails[child].id);
            }
        }
    }

 public:
    Graph(int n) : n(n)
    {
        for (int i = 0; i < n; i++)
            graphDetails.push_back(Node{i, INT_MAX, 0, false});
        this->id = 0;
    }
    
    void BuildGraph(vector<vector<int>>& edges)
    {
        for (vector<int>& edge : edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
    }

    void TarjanDFS()
    {
        DFSHelper(n - 1, -1);
        return;
    }

    vector<vector<int>>& CriticalConnections() { return criticalConnections; }
};
class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        Graph g(n);
        g.BuildGraph(connections);
        g.TarjanDFS();
        return g.CriticalConnections();
    }
};

int main()
{
  return 0;
}