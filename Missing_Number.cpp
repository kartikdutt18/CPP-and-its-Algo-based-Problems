//https://leetcode.com/problems/missing-number/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int missingNumber(vector<int> &nums)
{
    int ans = nums.size();
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        ans ^= i ^ nums[i];
    }

    return ans;
}