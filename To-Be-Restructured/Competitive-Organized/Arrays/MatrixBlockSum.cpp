//https://leetcode.com/contest/biweekly-contest-17/problems/matrix-block-sum/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int K)
    {
        vector<vector<int>> ans(mat.size(), vector<int>(mat[0].size(), 0));
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                for (int r = max(i - K, 0); r <= min(i + K, (int)(mat.size() - 1)); r++)
                {
                    for (int c = max(j - K, 0); c <= min(j + K, (int)(mat[0].size() - 1)); c++)
                    {
                        ans[i][j] += mat[r][c];
                    }
                }
            }
        }
        return ans;
    }
};