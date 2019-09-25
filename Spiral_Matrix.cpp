//https://leetcode.com/problems/spiral-matrix/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    vector<int> res;
    if (row == 0)
    {
        return res;
    }
    int col = matrix[0].size();
    int rstart = 0, rend = row - 1, cstart = 0, cend = col - 1, i;
    while (rstart <= rend && cstart <= cend)
    {
        for (i = cstart; i <= cend; i++)
        {
            res.push_back(matrix[rstart][i]);
        }
        rstart++;
        if (!(rstart <= rend && cstart <= cend))
        {
            break;
        }
        for (i = rstart; i <= rend; i++)
        {
            res.push_back(matrix[i][cend]);
        }
        cend--;
        if (!(rstart <= rend && cstart <= cend))
        {
            break;
        }
        for (i = cend; i >= cstart; i--)
        {
            res.push_back(matrix[rend][i]);
        }
        rend--;
        if (!(rstart <= rend && cstart <= cend))
        {
            break;
        }
        for (i = rend; i >= rstart; i--)
        {
            res.push_back(matrix[i][cstart]);
        }
        cstart++;
    }
    return res;
}