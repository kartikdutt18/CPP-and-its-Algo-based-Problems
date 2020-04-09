//https://leetcode.com/problems/course-schedule/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Graph{
    int v;
    map< int,list <int> > adjl;
    public:
        Graph(int v){
            this->v=v;
        }
        void insert(int u,int v){
            adjl[u].push_back(v);
        }
        bool isCyclic(vector<int> indegree){
            queue<int> q;
            for(int i=0;i<indegree.size();i++){
                if(indegree[i]==0){
                    q.push(i);
                }
            }
            
            int cnt=0;
            
            
            while(!q.empty()){
                int cur=q.front();
                q.pop();
                for(auto i:adjl[cur]){
                    if(--indegree[i]==0){
                        q.push(i);
                        
                        
                }
                
            }
            cnt++;
            }
            return (cnt != v);
        }
};

bool canFinish(int numCourses, vector<vector<  int > > &prerequisites){
    Graph g(numCourses);
    vector<int> indegree(numCourses,0);
    for(auto i: prerequisites){
        g.insert(i[1],i[0]);
        indegree[i[0]]++;
    }
    return !g.isCyclic(indegree);
}
int main(){
    vector<vector< int > > preq;
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    preq.push_back(v);
    cout<<canFinish(2,preq);

}