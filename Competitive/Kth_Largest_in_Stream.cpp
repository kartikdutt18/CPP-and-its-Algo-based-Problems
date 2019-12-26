//https://leetcode.com/problems/kth-largest-element-in-a-stream/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class KthLargest
{
    priority_queue<int,vector<int>,greater<int>> pq;
    int k;
public:
    KthLargest(int k, vector<int> &nums)
    {
        this->k=k;
        for(auto i:nums){
            if(pq.size()<k){
                pq.push(i);
            }
            else if(pq.top()<=i){
                pq.pop();
                pq.push(i);
            }
        }
    }

    int add(int val)
    {
        if (pq.size() < k){
            pq.push(val);
            
        }
        else if (pq.top() <= val)
        {
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};