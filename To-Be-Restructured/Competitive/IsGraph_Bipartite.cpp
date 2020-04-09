//https://leetcode.com/problems/is-graph-bipartite/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph{
    int v;
    map<int,list<int>> adjl;
    public:
        Graph(int v){
            this->v=v;
        }
        void insert(int u,int v){
            adjl[u].push_back(v);
            adjl[v].push_back(u);
        }
        bool bfsBipartite(int src){
            vector <bool> visited(v,false);
            vector <int> color(v,0);
            color[0]=-1;
            queue<int> q;
            q.push(src);
            visited[src]=true;
            while(!q.empty()){
                int cur=q.front();
                q.pop();
                for(auto i:adjl[cur]){
                    if(!visited[i]){
                        q.push(i);
                        visited[i]=true;
                        color[i]=1-color[cur];
                    }
                    else{
                        if(color[i]==color[cur]){
                            return false;
                        }
                    }
                }
            }
        return true;}
};

bool isBipartite(vector<vector<int>> &graph){
    Graph g(graph.size());
    int src=0;
    for(int i=0;i<graph.size();i++){
        if(graph[i].size()>1) src=i;
        for(auto j:graph[i]){
            g.insert(i,j);
        }
    }
    return g.bfsBipartite(src);
}