//https://codeforces.com/problemset/problem/115/A
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Graph
{
    int v;
    map<int,list<int>> adjList;
    public:
    void makeGraph(vector<int> edges)
    {
        for(int i=0;i<edges.size();i++)
        {
            adjList[edges[i]].push_back(i+1);
        }
    }
    int levelOrder()
    {
        queue<int> q;
        q.push(-1);
        int levels=0;
        while(!q.empty())
        {
            levels++;
            int len=q.size();
            for(int i=0;i<len;i++)
            {
                int cur = q.front();
                q.pop();
                for (auto child : adjList[cur])
                    q.push(child);
            }
        }
    return levels-1;
    }
};
int main()
{
    int n;
    cin>>n;
    vector<int> edges(n);
    for(int i=0;i<n;i++)
    {
        cin>>edges[i];
    }
    Graph g;
    g.makeGraph(edges);
    cout<<g.levelOrder()<<endl;
    return 0;
}