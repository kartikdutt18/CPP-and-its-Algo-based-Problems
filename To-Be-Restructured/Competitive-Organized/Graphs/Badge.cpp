//https://codeforces.com/problemset/problem/1020/B
#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
class Graph
{
    int v;
    map<int,int> adjList;
    public:
    void makeGraph(vector<int> edges)
    {
        this->v=edges.size();
        for(int i=0;i<edges.size();i++)
        {
            adjList[i+1]=edges[i];
        }
        return ;
    }
    void firstCycle(int src)
    {
        queue<int> q;
        q.push(src);
        vector<bool>visited(v+1,false);
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            if(visited[cur])
            {
                cout<<cur<<" ";
                break;
            }
            visited[cur]=true;
            if(!visited[adjList[cur]])
            {
                q.push(adjList[cur]);
            }
            else
            {
                cout<<adjList[cur]<<" ";
                break;
            }
        }
    return ;}
};
int main()
{
    ll t;
    cin>>t;
    vector<int> edges(t);
    for(ll i=0;i<t;i++)
    {
        cin>>edges[i];
    }
    Graph g;
    g.makeGraph(edges);
    for(int i=0;i<t;i++)
    {
        g.firstCycle(i+1);
    }
    return 0;
}