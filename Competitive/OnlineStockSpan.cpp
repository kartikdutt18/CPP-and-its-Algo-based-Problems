//https://leetcode.com/contest/weekly-contest-101/problems
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class StockSpanner
{
    stack<int> s;
    vector<int> v;
    int i;

public:
    StockSpanner()
    {
        i = -1;
    }
    int next(int price)
    {
        v.push_back(price);
        i++;
        while (!s.empty() && v[s.top()] <= v[i])
        {
            s.pop();
        }
        int ans = s.empty() ? v.size() : (i - s.top());
        s.emplace(i);
        return ans;
    }
};
