//https://leetcode.com/problems/course-schedule-ii/
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
        indegree = vector<int>(v, 0);
    }
    void addEdge(int u, int v)
    {
        adjlist[u].push_back(v);
        indegree[v]++;
    }
    vector<int> top_sort()
    {
        queue<int> q;
        for (int i = 0; i < v; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }
        vector<int> ans;
        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();
            ans.push_back(cur);
            for (auto j : adjlist[cur])
            {
                if (--indegree[j] == 0)
                    q.push(j);
            }
        }
        if (ans.size() == v)
            return ans;
        vector<int> t(0);
        return t;
    }
};
vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    Graph g(numCourses);
    for(auto i:prerequisites){
        g.addEdge(i[1],i[0]);
    }
    return g.top_sort();
}