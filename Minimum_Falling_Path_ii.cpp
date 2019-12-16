//https://leetcode.com/contest/biweekly-contest-15/problems/minimum-falling-path-sum-ii/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int min_element(vector<int> v, int j)
    {
        int ans = INT_MAX;
        for (int i = 0; i < v.size(); i++)
        {
            if (i != j)
                ans = min(ans, v[i]);
        }
        return ans;
    }
    int minFallingPathSum(vector<vector<int>> &arr)
    {
        if (arr.size() == 0)
            return 0;
        if (arr.size() == 1)
            return arr[0][0];
        vector<vector<int>> dp(arr.size(), vector<int>(arr[0].size(), 0));
        for (int i = 0; i < arr[0].size(); i++)
        {
            dp[0][i] = arr[0][i];
        }

        for (int i = 1; i < dp.size(); i++)
        {
            for (int j = 0; j < dp[0].size(); j++)
            {
                dp[i][j] = arr[i][j] + min_element(dp[i - 1], j);
            }
        }

        int ans = dp[dp.size() - 1][0];
        for (int i = 0; i < dp[0].size(); i++)
        {
            ans = min(ans, dp[dp.size() - 1][i]);
        }
        return ans;
    }
};