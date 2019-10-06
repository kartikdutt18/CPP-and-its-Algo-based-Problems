//https://leetcode.com/problems/subsets-ii/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
set<vector<int>> s;
void Generate_subsets(vector<int> nums, vector<int> cur_set,int i){
    if(i>nums.size()) return;
    s.insert(cur_set);
    for(int j=i;j<nums.size();j++){
        cur_set.emplace_back(nums[j]);
        Generate_subsets(nums,cur_set,j+1);
        cur_set.pop_back();
    }
    return;
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<vector<int>> ans;
    Generate_subsets(nums, {}, 0);
    sort(nums.begin(), nums.end());
    for(auto i: s){
        ans.emplace_back(i);
    }
    return ans;
}
