//https://leetcode.com/problems/meeting-rooms-ii/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool compare(vector<int> a, vector<int> b)
{
    return a[0] < b[0];
}
class Solution
{
public:
    int minMeetingRooms(vector<vector<int>> &intervals)
    {
        if (intervals.size() == 0)
            return 0;
        sort(intervals.begin(), intervals.end(), compare);
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto i : intervals)
        {
            if (pq.empty() || pq.top() > i[0])
            {
                pq.push(i[1]);
            }
            else
            {
                if (!pq.empty())
                    pq.pop();
                pq.push(i[1]);
            }
        }
        return pq.size();
    }
};