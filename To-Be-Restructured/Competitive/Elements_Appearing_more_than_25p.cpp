//https://leetcode.com/contest/biweekly-contest-15/problems/element-appearing-more-than-25-in-sorted-array/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findSpecialInteger(vector<int> &arr)
    {
        map<int, int> ht;
        for (auto i : arr)
            ht[i]++;
        int max_freq = 0;
        int ans;
        for (auto i : ht)
        {
            if (i.second > max_freq)
            {
                max_freq = i.second;
                ans = i.first;
            }
        }
        return ans;
    }
};
