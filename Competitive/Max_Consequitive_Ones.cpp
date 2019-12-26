//https://leetcode.com/problems/max-consecutive-ones/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int c1=0;
    int m1=0;
    for(auto i:nums){
        if(i==1){
            c1++;
            m1=max(m1,c1);
        }
        else c1=0;
    }
return m1;}
