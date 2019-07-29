//https://leetcode.com/problems/subarray-sum-equals-k/solution/
//https://practice.geeksforgeeks.org/problems/perfect-sum-problem/0
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int subarraySum(vector<int> &nums, int k)
{
    map<int,int> ht;
    int cum_sum=0;
    int ans=0;
    ht.insert({cum_sum, 1});
    for(auto i:nums){
        cum_sum+=i;
        if(ht.count(cum_sum)) ht[cum_sum]+=1;
        else ht.insert({cum_sum,1});
        if(ht.count(cum_sum-k))
            ans += ht[cum_sum-k];
    }
    return ans;
}