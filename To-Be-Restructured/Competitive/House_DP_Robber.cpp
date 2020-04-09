//https://leetcode.com/problems/house-robber/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int rob(vector<int>& nums) {
    vector<int> dp(nums.size()+2,0);
    dp[1]=nums[0];
    int ans=0;
    for(int i=1;i<nums.size();i++){
        dp[i+1]=max(dp[i],dp[i-1]+nums[i]);
        ans=max(ans,dp[i+1]);
    }      
    return ans;  
}