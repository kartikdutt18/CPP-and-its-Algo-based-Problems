//https://leetcode.com/problems/single-number/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(auto i:nums){
            ans=ans^i;
        }
    return ans;}
};