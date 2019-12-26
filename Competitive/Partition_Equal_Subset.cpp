//https://leetcode.com/problems/partition-equal-subset-sum/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool canPartition(vector<int> &nums)
{
    int ts = 0;
    if (nums.size() == 0)
        return true;
    if (nums.size() == 1)
        return false;
    for (auto i : nums)
        ts += i;
    if (ts & 1)
        return false;
    int req_sum = ts / 2;
    vector<vector<bool>> dp(nums.size() + 1, vector<bool>(req_sum + 1, false));
    for (int i = 0; i <= nums.size(); i++)
        dp[i][0] = true;
    dp[0][nums[0]] = true;
    for (int i = 1; i < nums.size(); i++)
    {
        for (int j = 1; j <= req_sum; j++)
        {
            dp[i][j] = nums[i] > j ? dp[i - 1][j] : dp[i - 1][j - nums[i]] || dp[i - 1][j];
        }
    }
    return dp[nums.size() - 1][req_sum];
}