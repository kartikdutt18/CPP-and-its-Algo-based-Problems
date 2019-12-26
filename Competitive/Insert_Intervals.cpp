//https://leetcode.com/problems/insert-interval/submissions/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool compare(vector<int> v1, vector<int> v2)
{
    return v1[0] < v2[0];
}
class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> ans;
        priority_queue<vector<int>, vector<vector<int>>, function<bool(vector<int>, vector<int>)>> pq([](vector<int> v1, vector<int> v2) -> bool { return v1[1] < v2[1]; });
        int cnt = 0;
        intervals.emplace_back(newInterval);
        sort(intervals.begin(), intervals.end(), compare);
        while (cnt != intervals.size())
        {
            if (pq.empty() || (pq.top()[1] < intervals[cnt][0]))
            {
                pq.push(intervals[cnt++]);
            }
            else
            {
                vector<int> t = pq.top();
                pq.pop();
                t[0] = min(t[0], intervals[cnt][0]);
                t[1] = max(t[1], intervals[cnt][1]);
                pq.push(t);
                cnt++;
            }
        }
        vector<vector<int>> res;
        while (!pq.empty())
        {
            res.emplace_back(pq.top());
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};