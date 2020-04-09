//https://leetcode.com/problems/parallel-courses/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph
{
    map<int, list<int>> adjlist;
    int v;
    vector<int> indegree;

public:
    Graph(int v)
    {
        this->v = v;
        indegree.reserve(v + 1);
        for (int i = 1; i <= v; i++)
        {
            indegree[i] = 0;
        }
    }
    void addEdge(int u, int v)
    {
        adjlist[u].push_back(v);
        indegree[v]++;
    }
    int topological_sort()
    {
        queue<int> q;
        for (int i = 1; i <= v; i++)
        {
            cout << indegree[i] << " ";
            if (indegree[i] == 0)
                q.push(i);
        }
        if (q.size() == 0)
            return -1;
        int cnt = 0;
        int sub_completed(0);
        while (!q.empty())
        {
            cnt++;
            int len = q.size();
            for (int i = 0; i < len; i++)
            {
                auto cur = q.front();
                q.pop();
                sub_completed++;
                for (auto child : adjlist[cur])
                {
                    if (--indegree[child] == 0)
                    {
                        q.push(child);
                    }
                }
            }
        }
        return sub_completed == v ? cnt : -1;
    }
};
int minimumSemesters(int N, vector<vector<int>> &relations)
{
    Graph g(N);
    for(auto i:relations){
        g.addEdge(i[1],i[0]);
    }
    return g.topological_sort();

}