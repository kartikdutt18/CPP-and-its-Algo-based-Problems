//https://leetcode.com/contest/biweekly-contest-17/problems/decompress-run-length-encoded-list/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> decompressRLElist(vector<int> &nums)
    {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i += 2)
        {
            int t = nums[i];
            while (t--)
            {
                ans.push_back(nums[i + 1]);
            }
        }
        return ans;
    }
};