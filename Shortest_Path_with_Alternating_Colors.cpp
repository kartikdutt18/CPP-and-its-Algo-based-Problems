//https://leetcode.com/contest/weekly-contest-146/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Graph{
    int v;
    map<int,list<pair<int,int>>> adjl;
    public:
    Graph(int v){
        this->v=v;
    }
    void addEdge(int u,int v,int c){
        adjl[u].push_back(pair(v,c));
    }
    vector<int> bfs(int src=0){
        vector<int> ans;
        vector<bool> visited(v,false);
        queue<int> q;
        q.push(src);
        visited[src]=true;
        bool color=adjl[src].front().second;
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            for(auto i: adjl[cur]){
                if(!visited[i.first] && i.second!=color){
                    q.push(i.first);
                }
            }
            color=1-color;
        }
    ans.push_back(-1);
    return ans;}
};
vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &red_edges, vector<vector<int>> &blue_edges)
{
    Graph g(n);
    for(auto i: red_edges){
        g.addEdge(i[0],i[1],0);
    }
    for (auto i : blue_edges)
    {
        g.addEdge(i[0], i[1], 1);
    }
    return g.bfs();
}