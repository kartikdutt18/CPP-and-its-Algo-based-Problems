//https://leetcode.com/problems/unique-paths/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int uniquePaths(int m, int n)
{
    vector<long> init_row(m, 1);
    vector<vector<long>> grid(n, init_row);
    for (auto row = grid.begin() + 1; row != grid.end(); row++)
    {
        for (auto val = row->begin() + 1; val != row->end(); val++)
        {
            grid[row - grid.begin()][val - row->begin()] = grid[row - grid.begin() - 1][val - row->begin()] + grid[row - grid.begin()][val - row->begin() - 1];
        }
    }
    return grid[n - 1][m - 1];
}