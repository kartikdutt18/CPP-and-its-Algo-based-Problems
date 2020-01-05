//https://leetcode.com/contest/weekly-contest-170/problems/xor-queries-of-a-subarray/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
{
    vector<int> dp;
    dp.push_back(0);
    for (auto i : arr)
    {
        dp.push_back(dp.back() ^ i);
    }
    vector<int> ans;
    for (auto i : queries)
    {
        ans.push_back(dp[i[0]] ^ dp[i[1] + 1]);
    }
    return ans;
}