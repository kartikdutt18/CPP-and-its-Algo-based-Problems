//https://leetcode.com/problems/two-sum/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    map<int, int> ht;
    int j = 0;
    for (auto i : nums)
    {
        if (ht.count(target - i))
            return {ht[target - i], j};
        ht.insert(make_pair(i, j));
        j++;
    }
    return {-1, -1};
}