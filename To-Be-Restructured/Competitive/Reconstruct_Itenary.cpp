//https://leetcode.com/problems/reconstruct-itinerary/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Graph
{
    map<string, priority_queue<string, vector<string>, greater<string>>> adjlist;

public:
    vector<string> s;
    Graph() {}
    void insert(string a, string b)
    {
        if (adjlist.count(a))
            adjlist[a].push(b);
        else
        {
            priority_queue<string, vector<string>, greater<string>> pq;
            pq.push(b);
            adjlist.insert({a, pq});
        }
    }
    vector<string> dfs(string src)
    {
        map<string, bool> visited;
        dfshelper(visited, src);
        reverse(s.begin(), s.end());
        return s;
    }
    void dfshelper(map<string, bool> &visited, string src)
    {
        visited[src] = true;
        while (!adjlist[src].empty())
        {
            auto i = adjlist[src].top();
            adjlist[src].pop();
            dfshelper(visited, i);
        }
        s.push_back(src);
        return;
    }
};

vector<string> findItinerary(vector<vector<string>> &tickets)
{
    Graph g;
    for(auto i: tickets){
        g.insert(i[0],i[1]);
    }
    return g.dfs("JFK");
}