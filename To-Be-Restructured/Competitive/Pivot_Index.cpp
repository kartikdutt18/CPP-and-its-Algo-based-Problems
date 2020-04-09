//https://leetcode.com/problems/find-pivot-index/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int pivotIndex(vector<int> &nums)
{
    if(nums.size()==0) return -1;
    int csum=0;
    for(int i=0;i<nums.size();i++){
        csum+=nums[i];
    }
    int leftsum=0;
    for(int i=0;i<nums.size();i++){
        if(leftsum==csum-leftsum) return i;
        leftsum+=nums[i];
    }
return -1;}