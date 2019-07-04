//https://leetcode.com/problems/kth-largest-element-in-an-array/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> pq;
    for(auto i: nums){
        pq.push(i);
        if(pq.size()>k){
            pq.pop();
        }
    }
    int ans=0;
    while(!pq.empty()){
        ans=pq.top();
        pq.pop();
    }
    return ans;
}