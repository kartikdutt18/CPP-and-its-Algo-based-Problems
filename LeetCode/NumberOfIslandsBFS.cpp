#include<iostream>
#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid)
    {
        int numIslands = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    numIslands++;
                    bfs(i, j, grid);
                }
            }
        }
        return numIslands;
    }

private:
    bool isValid(int x, int y, int n, int m)
    {
        return x >= 0 && y >= 0 && x < n && y < m;
    }

    void bfs(int x, int y, vector<vector<char>>& grid)
    {
        queue<pair<int, int>> q;
        q.push({ x, y });
        vector<int> dvec ={ 1, -1 };
        while (!q.empty())
        {
            pair<int, int> coods = q.front();
            q.pop();
            grid[coods.first][coods.second] = '0';
            for (int dx : dvec)
            {
                if (isValid(coods.first + dx, coods.second, grid.size(), grid[0].size()) &&
                    grid[coods.first + dx][coods.second] == '1')
                    q.push({ coods.first + dx, coods.second });
            }
            for (int dy : dvec)
            {
                if (isValid(coods.first, coods.second + dy, grid.size(), grid[0].size()) &&
                    grid[coods.first][coods.second + dy] == '1')
                    q.push({ coods.first, coods.second + dy });
            }
        }

        return;
    }
};

int main()
{
  ios::sync_with_stdio(false);
  return 0;
}