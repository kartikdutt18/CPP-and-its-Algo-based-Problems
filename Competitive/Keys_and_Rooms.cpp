//https://leetcode.com/problems/keys-and-rooms/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Graph{
    map<int,list<int>> adjlist;
    int v;
    public:
    Graph(int v){
        this->v=v;
    }
    void addEdge(int u,int v){
        adjlist[u].push_back(v);
    }
    bool dfs(int src){
        vector<bool> visit(v,false);
        dfshelper(src,visit);
        for(auto i:visit) if(!i) return false;
        return true;
    }
    void dfshelper(int src,vector<bool>& visited){
        visited[src]=true;
        for(auto i: adjlist[src]){
            if(!visited[i]) dfshelper(i,visited);
        }
        return;
    }
};
bool canVisitAllRooms(vector<vector<int>> &rooms)
{
    Graph g(rooms.size());
    int k=0;
    for(auto i: rooms){
        
        for(auto j: i) g.addEdge(k,j);
        k++;
    }
    return g.dfs(0);
}