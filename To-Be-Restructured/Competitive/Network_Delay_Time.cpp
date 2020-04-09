//https://leetcode.com/problems/network-delay-time/
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
    void addEdge(int u,int v,int w){
      adjl[u].push_back(pair(v,w));  
    }
    
    int dijisiktra(int src){
        unordered_map <int,int> dist;
        for(int i=1;i<=v;i++){
            dist[i]=INT_MAX;
        }
        set<pair<int,int>> s; //Sorting by pair.first Hence pair.first is distance
        dist[src]=0;
        s.insert(pair(0,src));
        while(!s.empty()){
            auto p=* (s.begin());
            int node=p.second;
            int nodeDist=p.first;
            s.erase(s.begin());
            for(auto i: adjl[node]){
                if(nodeDist+i.second<dist[i.first]){
                     auto f=s.find(make_pair(dist[i.first],i.first));
                     if(f!=s.end()) s.erase(f);
                     dist[i.first] = nodeDist + i.second;
                     s.insert(make_pair(dist[i.first],i.first));
                }
            }

        }
        int max_dist=0;
        for(auto i:dist){
            if(i.second==INT_MAX) return -1;
            max_dist=max(max_dist,i.second);
        }
    return max_dist;}


};
int networkDelayTime(vector<vector<int>> &times, int N, int K)
{
    Graph g(N);
    for(auto i: times){
        g.addEdge(i[0],i[1],i[2]);
    }
    return g.dijisiktra(K);
}