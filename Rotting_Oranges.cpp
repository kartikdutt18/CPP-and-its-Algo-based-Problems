//https://leetcode.com/problems/rotting-oranges/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Oranges
{
public:
    int x;
    int y;
    int dist;
    Oranges(int a,int b,int c) :x(a),y(b),dist(c) {};
};
int orangesRotting(vector<vector<int>> &grid)
{
    queue<Oranges> q;
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    int cnt=0;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]==2){
                q.push(Oranges(i,j,0));
                visited[i][j]=true;
            }
            
        }
    }
    if(q.empty()) return -1;
    vector<int> x={1,0,-1,0};
    vector<int> y={0,1,0,-1};
    int ans=0;
    
    while(!q.empty()){
        Oranges cur=q.front();
        q.pop();
        ans=max(ans,cur.dist);
        for(int i=0;i<3;i++){
            if ((cur.x + x[i]) < grid.size() && (cur.y + y[i]) < grid[0].size() && (cur.x + x[i]) >= 0 && (cur.y + y[i]) >= 0 && visited[cur.x + x[i]][cur.y + y[i]]==false)
            {
                q.push(Oranges(cur.x + x[i], cur.y + y[i],cur.dist+1));
                grid[cur.x + x[i]][cur.y + y[i]] = 2;
                visited[cur.x + x[i]][cur.y + y[i]] = true;
                cnt--;
            }
        }
    }
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {

            if (grid[i][j] == 1)
                return -1;
        }
    }
    return ans;
}

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        const int m = grid.size(), n = grid[0].size();
        queue<Vertex> q;
        int maxstep = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 2)
                    q.push({i, j, 0});
        while (!q.empty())
        {
            auto [x, y, step] = q.front();
            q.pop();
            for (const auto &[dx, dy] : {pair(0, 1), pair(0, -1), pair(-1, 0), pair(1, 0)})
            {
                int i = x + dx, j = y + dy;
                if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1)
                    continue;
                grid[i][j] = 2;
                q.push({i, j, step + 1});
                maxstep = step + 1;
            }
        }
        for (const auto &v : grid)
            if (any_of(v.begin(), v.end(), [](int x) { return x == 1; }))
                return -1;
        return maxstep;
    }

    struct Vertex
    {
        int x;
        int y;
        int step;
    };
};