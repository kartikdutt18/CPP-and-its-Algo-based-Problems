//https://leetcode.com/problems/maximum-product-subarray/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxProduct(vector<int> &nums)
{
    int maxP=nums[0];
    int minP=nums[0];
    for(int i=1;i<nums.size();i++){
        maxP=max(nums[i],max(maxP*nums[i],minP*nums[i]));
        minP = min(nums[i], max(maxP * nums[i], minP * nums[i]));
    }
    return maxP;
}