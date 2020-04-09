//https://codeforces.com/problemset/problem/522/A
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph
{
    map<string,list<string>> adjList;
    public:
    void makeGraph(vector<string> v)
    {
        for(auto i:v)
        {
            stringstream ss(i);
            string t1,t2,t3;
            ss>>t1>>t3>>t2;
            transform(t1.begin(),t1.end(),t1.begin(),::tolower);
            transform(t2.begin(), t2.end(),t2.begin(), ::tolower);
            adjList[t2].push_back(t1);
        }
    }
    void levelOrder()
    {
        queue<string> q;
        if(adjList.count("polycarp"))
        {
            q.push("polycarp");
        }
        int levels=0;
        while(!q.empty())
        {
            int l=q.size();
            levels++;
            for(int i=0;i<l;i++)
            {
                auto cur=q.front();
                q.pop();
                for(auto child:adjList[cur])
                {
                    q.push(child);
                }
            }
        }
        cout<<levels<<endl;
        return;
    }
};

int main()
{
    int n;
    cin>>n;
    vector<string>v;
    while(n--)
    {
        string s;
        while(s.length()==0)
            getline(cin,s);
        v.push_back(s);
    }
    Graph g;
    g.makeGraph(v);
    g.levelOrder();
    return 0;
}