//https://leetcode.com/problems/meeting-rooms/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool compare(vector<int> a, vector<int> b)
{
    return a[0] != b[0] ? a[0] < b[0] : a[1] < b[1];
}
class Solution
{
public:
    bool canAttendMeetings(vector<vector<int>> &intervals)
    {
        if (intervals.size() == 0)
            return true;
        sort(intervals.begin(), intervals.end(), compare);
        for (int i = 0; i < intervals.size() - 1; i++)
        {
            if (intervals[i][1] > intervals[i + 1][0])
                return false;
        }
        return true;
    }
};