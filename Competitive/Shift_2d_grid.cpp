//https://leetcode.com/problems/shift-2d-grid/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
    {

        if (grid.size() == 0)
            return grid;
        vector<int> grid_;
        for (auto i : grid)
        {
            for (auto j : i)
                grid_.emplace_back(j);
        }
        int nums_size = grid_.size();
        k %= nums_size;
        reverse(grid_.begin(), grid_.end());
        reverse(grid_.begin(), grid_.begin() + k);
        reverse(grid_.begin() + k, grid_.end());
        vector<vector<int>> _grid_(grid.size(), vector<int>(grid[0].size(), 0));
        int l = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                _grid_[i][j] = grid_[l++];
            }
        }
        return _grid_;
    }
};