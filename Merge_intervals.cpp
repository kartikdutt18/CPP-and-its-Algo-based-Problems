//https://leetcode.com/problems/merge-intervals/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool compare(vector<int> a,vector<int> b){
    return a[0]<b[0];
}
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    stack<vector<int>> s;
    sort(intervals.begin(),intervals.end(),compare);
    for (auto i : intervals)
    {
        if (s.empty())
            s.push(i);
        else
        {
            if (s.top()[1] >= i[0])
            {
                auto j = s.top();
                s.pop();
                j[1] = max(i[1], j[1]);
                j[0] = min(i[0], j[0]);
                s.push(j);
            }
            else
            {
                s.push(i);
            }
        }
    }
    vector<vector<int>> ans;
    while (!s.empty())
    {
        auto i = s.top();
        s.pop();
        ans.push_back(i);
    }
    reverse(ans.begin(), ans.end());

    return ans;
}