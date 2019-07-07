//https://leetcode.com/problems/two-sum/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    map<int,int> ht;
    for(int i=0;i<nums.size();i++){
        ht.insert(make_pair(nums[i],i));
    }
    for(auto i:ht){
        if(ht.count(target-i.first)){
            int j=min(i.second,ht[target-i.first]);
            int k=max(i.second,ht[target-i.first]);
            return {j,k};

        }
    }
return {-1,-1};}