//https://codeforces.com/problemset/problem/1037/D
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Graph{
    map<int,list<int>> adjlist;
    public:
    Graph(){}
    void addNode(int u,int v){
        adjlist[u].push_back(v);
    }
    void bfs(vector<int> bfs, int src = 1)
    {
        queue<int> q;
        q.push(src);
        vector<int> bfs_1;
        vector<int> bfs_2;
        while(!q.empty()){
            auto cur=q.front();
            q.pop();
            vector<int> level;
            for(auto i: adjlist[cur]){
                level.push_back(i);
                bfs_1.push_back(i);
                q.push(i);
            }
            reverse(level.begin(),level.end());
            for(auto i:level) bfs_2.push_back(i);
        }
        if(bfs==bfs_1 || bfs==bfs_2) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        return;
    }
    
};
int main(){
    int n;
    cin>>n;
    Graph g;
    for(int i=1;i<n;i++){
        int t1,t2;
        cin>>t1>>t2;
        g.addNode(t1,t2);
    }
    g.bfs();
    return 0;

}