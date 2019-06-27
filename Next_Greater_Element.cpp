//https://leetcode.com/problems/next-greater-element-i
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    if(nums1.size()==0 or nums2.size()==0) return {};
    stack <int> s;
    vector <int> ans(10000,0);
    s.push(nums2[0]);
    
    for(int i=0;i<nums2.size();i++){
        if(s.empty()) s.push(nums2[i]);
        while(s.empty()==false and (nums2[i]>s.top())){
            ans[s.top()]=nums2[i];
            s.pop();
        }
        s.push(nums2[i]);
    }
    while(not s.empty()){
        ans[s.top()]=-1;
        s.pop();
    }
    vector<int> ret;      
    for(auto i:nums1){
        ret.push_back(ans[i]);
    }  
return ret;}