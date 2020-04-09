//https://leetcode.com/problems/find-the-town-judge
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
        int v;
        map<int,list<int>> adjl;
        Graph(int v){
            this->v=v;
        }
        void addedge(int u,int v){
            adjl[u].push_back(v);}
        int judge(){
            map<int,pair<int,int>> trustlevel;
            for(int i=1;i<=v;i++){
                trustlevel[i]=pair(0,0);
            }
            
            for(auto i:adjl){
                trustlevel[i.first]=make_pair(trustlevel[i.first].first,i.second.size());
                for(auto j:i.second){
                    trustlevel[j]=make_pair(trustlevel[j].first+1,trustlevel[j].second);
                }
                
            }
            for(auto i: trustlevel){
                if(i.second.first==v-1 and i.second.second==0) return i.first;
            }
        return -1;}
        
        
};
int findJudge(int N, vector<vector<int>>& trust) {
     Graph g(N);
    
     for(auto i:trust){
          g.addedge(i[0],i[1]);  
     }
     return g.judge();   
}

// Better No Graph Solution
int findJudge(int N, vector<vector<int>>& trust) {
  vector<int> trusts(N + 1), trusted(N + 1);
  for (auto &t : trust) ++trusts[t[0]], ++trusted[t[1]];
  for (auto i = 1; i <= N; ++i) if (trusts[i] == 0 && trusted[i] == N - 1) return i;
  return -1;
}