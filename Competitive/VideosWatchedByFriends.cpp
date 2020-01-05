//https://leetcode.com/contest/weekly-contest-170/problems/get-watched-videos-by-your-friends/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Graph
{
    int nodes;
    map<int, list<int>> adjlist;

public:
    Graph(int v) : nodes(v) {}
    void makeGraph(vector<vector<int>> f)
    {
        for (int i = 0; i < f.size(); i++)
        {
            for (auto j : f[i])
                adjlist[i].push_back(j);
        }
        return;
    }
    vector<int> bfs(int start, int level)
    {
        vector<int> v;
        queue<int> q;
        q.push(start);
        int curLevel = 0;
        vector<int> friends;
        set<int> visited;
        while (!q.empty() && curLevel <= level)
        {
            int len = q.size();
            for (int i = 0; i < len; i++)
            {
                auto cur = q.front();
                q.pop();

                if (level == curLevel && !visited.count(cur))
                {
                    friends.push_back(cur);
                }
                visited.insert(cur);
                for (auto child : adjlist[cur])
                {
                    if (!visited.count(child))
                        q.push(child);
                }
            }
            curLevel++;
        }
        return friends;
    }
};
class Solution
{
public:
    vector<string> watchedVideosByFriends(vector<vector<string>> &watchedVideos, vector<vector<int>> &friends, int id, int level)
    {

        vector<int> indices;
        Graph g(friends.size());
        g.makeGraph(friends);
        indices = g.bfs(id, level);
        map<string, int> ht;
        for (auto i : indices)
        {
            //cout<<i<<endl;
            for (auto j : watchedVideos[i])
            {
                ht[j]++;
            }
        }
        vector<string> ans;
        for (auto i : ht)
        {
            ans.push_back(i.first);
        }
        sort(ans.begin(), ans.end(), [&ht](string a, string b) {
            return ht[a] != ht[b] ? ht[a] < ht[b] : a < b;
        });
        return ans;
    }
};