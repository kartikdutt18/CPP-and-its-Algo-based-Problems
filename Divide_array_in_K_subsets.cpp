//https://leetcode.com/contest/weekly-contest-168/submissions/detail/287654749/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPossibleDivide(vector<int> &nums, int k)
    {
        if (nums.size() < k || (nums.size() == 0 && k != 0))
            return false;
        if (nums.size() % k != 0)
            return false;
        if (k == nums.size())
            return true;
        map<int, int> ht;
        for (auto i : nums)
            ht[i]++;
        int t = 0;

        vector<vector<int>> ans(nums.size() / k + 1);
        for (auto j : ht)
        {
            int row = 0;
            while (ans[row].size() == k)
                row++;
            while (j.second--)
            {
                ans[row].push_back(j.first);
                row++;
            }
        }
        for (int i = 0; i < nums.size() / k; i++)
        {
            if (ans[i].size() != k)
                return false;

            for (int l = 1; l < k; l++)
            {
                if (ans[i][l] != ans[i][l - 1] + 1)
                    return false;
            }
        }
        return true;
    }
};