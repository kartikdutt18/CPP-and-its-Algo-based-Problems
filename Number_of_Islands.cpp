//https://leetcode.com/problems/number-of-islands/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> dx = {1, -1};
vector<int> dy = {1, -1};
void dfshelper(vector<vector<bool>> &visited, vector<vector<char>> &grid, int r, int c)
{

    visited[r][c] = true;

    for (int k = 0; k < 2; k++)
    {
        if (r + dx[k] >= 0 && r + dx[k] < grid.size() && grid[r + dx[k]][c] == '1' && !visited[r + dx[k]][c])
        {

            dfshelper(visited, grid, r + dx[k], c);
        }
    }
    for (int l = 0; l < 2; l++)
    {
        if (c + dy[l] >= 0 && c + dy[l] < grid[0].size() && grid[r][c + dy[l]] == '1' && !visited[r][c + dy[l]])
        {
            dfshelper(visited, grid, r, dy[l] + c);
        }
    }
    return;
}

int numIslands(vector<vector<char>> &grid)
{
    int islands = 0;
    if (grid.size() == 0)
        return 0;
    vector<vector<bool>> visited(grid.size() + 1, vector<bool>(grid[0].size() + 1, false));
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == '1' && !visited[i][j])
            {

                dfshelper(visited, grid, i, j);
                islands++;
            }
        }
    }
    return islands;
}