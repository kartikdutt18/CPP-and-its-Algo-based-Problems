//https://leetcode.com/problems/intersection-of-two-arrays-ii/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    if(nums1.size()>nums2.size()){
        return intersect(nums2,nums1);
    }
    map<int,int> ht;
    for(auto i:nums1){
        if(ht.count(i)) ht[i]+=1;
        else ht.insert(make_pair(i,1));
    }
    map<int,int> ht2;
    for(auto i:nums2){
        if (ht2.count(i))
            ht2[i] += 1;
        else
            ht2.insert(make_pair(i, 1));
    }
    vector<int> ans;
    for(auto i: ht){
        if(ht2.count(i.first)){
            int temp=min(i.second,ht2[i.first]);
            while(temp--){
                ans.push_back(i.first);
            }
        }
    }
return ans;}
vector<int> intersect2(vector<int> &a, vector<int> &b)
{
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    a.erase(set_intersection(a.begin(), a.end(), b.begin(), b.end(), a.begin()), a.end());
    return a;
}