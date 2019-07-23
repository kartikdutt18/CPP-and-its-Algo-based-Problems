//https://leetcode.com/problems/maximum-product-subarray/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxProduct(vector<int> &nums)
{
    int mx, lastMax, lastMin;
    mx = lastMax = lastMin = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {

        int curMax = max(max(nums[i], nums[i] * lastMax), nums[i] * lastMin);
        int curMin = min(min(nums[i], nums[i] * lastMax), nums[i] * lastMin);

        lastMax = curMax;
        lastMin = curMin;

        if (curMax > mx)
            mx = curMax;
    }
    return mx;
}