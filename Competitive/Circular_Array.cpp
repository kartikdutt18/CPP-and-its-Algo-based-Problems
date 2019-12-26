//https://leetcode.com/problems/circular-array-loop/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool circularArrayLoop(vector<int> &nums)
{
    for(int i=0;i<nums.size();i++){
        int ind=i+nums[i];
        if(ind<0) ind=nums.size()+ind;
        nums[i]=ind; 
    }
    int fast=0;
    int slow=0;
    while(fast<nums.size() && nums[fast]<nums.size()){
        fast=nums[fast];
        if(fast==slow) return true;
        if(fast>nums.size() || nums[fast]>nums.size()){
            return false;
        }
        slow=nums[slow];
        fast=nums[fast];
    }
    return false;
}