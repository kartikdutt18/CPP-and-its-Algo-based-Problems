//https://leetcode.com/problems/reshape-the-matrix

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c)
{
    int cur_r = nums.size();
    int cur_c = nums[0].size();

    if (r * c > cur_r * cur_c || r * c < cur_r * cur_c)
        return nums;
    int ri = 0;
    int ci = 0;
    vector<vector<int>> ans(r, vector<int>(c, 0));
    for (int i = 0; i < cur_r; i++)
    {
        for (int j = 0; j < cur_c; j++)
        {
            if (ci == c)
            {
                ri++;
                ci = 0;
            }

            ans[ri][ci] = nums[i][j];
            ci++;
        }
    }

    return ans;
}