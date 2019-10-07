//CTCI
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph{
    int v;
    map<int,list<int>> adjlist;
    public:
    Graph(int v){
        this->v=v;
    }
    bool isConnected(int s,int d){
        vector<bool> visited(v+1);
        dfs(s,visited);
        return visited[d];
    }
    void dfs(int src,vector<bool> &visit){
        visit[src]=true;
        for(auto j:adjlist[src]){
            if(!visit[j]) dfs(j,visit);
        }
        return;
    }
    vector<int> buildorder(){
        vector<int> indegree(v,0);
        for(int i=0;i<v;i++){
            for(auto j:adjlist[i]) indegree[j]++;
        }
        vector<int> ans;
        queue<int> q;
        for(int i=0;i<v;i++){
            if(indegree[i]==0) q.emplace(i);
        }
        while(!q.empty()){
            auto cur=q.front();
            q.pop();
            ans.emplace_back(cur);
            for(auto j:adjlist[cur]){
                if(--indegree[j]==0) q.emplace(j);
            }
        }
        return ans;
    }
};