//https://leetcode.com/problems/paint-house/submissions/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int minCost(vector<vector<int>> &costs)
{

    if (costs.size() == 0)
        return 0;
    if (costs.size() == 1)
        return min(costs[0][0], min(costs[0][1], costs[0][2]));

    vector<vector<int>> dp(costs.size(), vector<int>(3, 0));
    dp[0][0] = costs[0][0];
    dp[0][1] = costs[0][1];
    dp[0][2] = costs[0][2];

    for (int i = 1; i < costs.size(); i++)
    {
        dp[i][0] = costs[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = costs[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = costs[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
    }

    return min(dp[costs.size() - 1][0], min(dp[costs.size() - 1][1], dp[costs.size() - 1][2]));
}