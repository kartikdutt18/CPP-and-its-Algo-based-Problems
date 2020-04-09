//https://leetcode.com/contest/biweekly-contest-15
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int removeCoveredIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) { return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1]; });
        int cur_size = intervals.size();
        stack<vector<int>> v;
        int i = 0;
        while (i < intervals.size())
        {
            if (v.empty())
                v.emplace(intervals[i]);
            else if (v.top()[0] <= intervals[i][0] && v.top()[1] >= intervals[i][1])
            {
                i++;
            }

            else
            {
                v.emplace(intervals[i]);
                i++;
            }
        }
        return v.size();
    }
};
