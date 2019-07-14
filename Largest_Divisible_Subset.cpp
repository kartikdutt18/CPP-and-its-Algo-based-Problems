//https://leetcode.com/problems/largest-divisible-subset/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> largestDivisibleSubset(vector<int> &nums)
{
    if (nums.size() == 0 or nums.size() == 1)
        return nums;
    sort(nums.begin(),nums.end());
    vector<int> dp(nums.size()+1,0);
    dp[nums.size()-1]=1;
    int max_ind=0;
    int ans=0;
    for(int j=nums.size()-2;j>=0;j--){
        int mxm = 0;
        for(int i=j+1;i<nums.size();i++){
            if(nums[i]%nums[j]==0)
                mxm=max(dp[i],mxm);
        }
        dp[j]=mxm + 1;
        if(dp[j]>ans){
            ans=dp[j];
            max_ind=j;
        }
    }
    vector<int> ans_vec;
    int temp=ans;
    for(int k=max_ind;k<nums.size(),temp>0;k++){
        if(dp[k]==temp){
            ans_vec.push_back(nums[k]);
            temp--;
        }
    }

return ans_vec;}