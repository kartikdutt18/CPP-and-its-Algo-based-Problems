//https://leetcode.com/problems/circular-array-loop/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int GetPos(int fast,int cur,int size){
    if(fast<0){
        return size
    }
}
bool circularArrayLoop(vector<int> &nums)
{
    int fast=0,slow=0;
    while(fast<nums.size() && (fast+nums[fast])<nums.size()){
        fast=nums[fast]+fast;
        if(fast==slow) return true;
        if (fast < nums.size() && (fast + nums[fast]) < nums.size()) return false;
        fast = nums[fast] + fast;
        slow=nums[slow]+slow;
    }
    return false;
}