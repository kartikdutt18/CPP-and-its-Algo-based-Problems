//https://leetcode.com/problems/subsets/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;
void subset(vector<int> nums, int i, int n, vector<int> temp)
{
    if (i >= n)
    {
        ans.push_back(temp);
        return;
    }

    temp.push_back(nums[i]);
    subset(nums, i + 1, n, temp);
    temp.pop_back();
    subset(nums, i + 1, n, temp);
    return;
}
vector<vector<int>> subsets(vector<int> &nums)
{
    subset(nums, 0, nums.size(), {});
    return ans;
}