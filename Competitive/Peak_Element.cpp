//https://leetcode.com/problems/find-peak-element/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> &nums)
{
    int s=0;
    int e=nums.size()-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(nums[mid+1]>nums[mid]) e=mid;
        else  s=mid+1;
    }
return s;}