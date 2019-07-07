//https://leetcode.com/problems/rotate-array/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void rotate(vector<int>& nums, int k){
        k%=nums.size();
        if(k == 0) return;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
}