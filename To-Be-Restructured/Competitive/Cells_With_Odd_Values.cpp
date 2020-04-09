//https://leetcode.com/contest/weekly-contest-162/problems/cells-with-odd-values-in-a-matrix/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int oddCells(int n, int m, vector<vector<int>> &indices)
    {
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (auto i : indices)
        {
            int row = i[0];
            int column = i[1];
            if (row >= n || column >= m)
                continue;
            for (int j = 0; j < n; j++)
                matrix[j][column] += 1;
            for (int k = 0; k < m; k++)
                matrix[row][k] += 1;
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans += matrix[i][j] & 1;
            }
        }
        return ans;
    }
};