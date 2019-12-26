//https://leetcode.com/contest/weekly-contest-161/problems/count-number-of-nice-subarrays/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int count_odd = 0;
        int ans = 0;
        vector<int> dp(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            dp[count_odd]++;
            if (nums[i] & 1)
                count_odd++;
            if (count_odd >= k)
            {
                ans += dp[count_odd - k];
            }
        }
        return ans;
    }
};