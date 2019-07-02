//https://leetcode.com/problems/contains-duplicate/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for(auto i:nums){
            if(s.count(i)) return true;
            s.insert(i);
        }
    return false;}
};