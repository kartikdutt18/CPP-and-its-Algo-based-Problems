//https://leetcode.com/problems/top-k-frequent-elements/submissions/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> topKFrequent(vector<int> &nums, int k)
{
    map<int, int> mp;
    vector<pair<int, int>> vec;
    vector<int> res;
    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    }
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        vec.push_back(make_pair(it->second, it->first));
    }
    //sort by first value in descending order
    sort(vec.begin(), vec.end(), greater<pair<int, int>>());
    for (auto i = 0; i < k; i++)
    {
        res.push_back(vec[i].second);
    }

    return res;
}