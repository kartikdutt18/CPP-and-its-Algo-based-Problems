//https://leetcode.com/problems/range-sum-query-immutable/submissions/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class NumArray
{
    vector<int> dp;

public:
    NumArray(vector<int> &nums)
    {
        dp.push_back(0);
        for (auto i : nums)
            dp.push_back(dp.back() + i);
    }

    int sumRange(int i, int j)
    {
        return dp[j + 1] - dp[i];
    }
};