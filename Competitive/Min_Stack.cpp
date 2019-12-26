//https://leetcode.com/problems/min-stack/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class MinStack
{
    vector<pair<int, int>> v;

    int cur_size;

public:
    /** initialize your data structure here. */
    MinStack()
    {
        cur_size = 0;
        v.reserve(2);
    }

    void push(int x)
    {

        if (cur_size == 0)
        {
            v.push_back(pair(x, x));
            cur_size++;
        }
        else if (cur_size > 0)
        {
            int cur_min = min(v[cur_size - 1].second, x);
            v.push_back(pair(x, cur_min));
            cur_size++;
        }
    }

    void pop()
    {
        v.pop_back();
        if (cur_size > 0)
            cur_size--;
        
    }

    int top()
    {
        if (cur_size > 0)
            return v[cur_size - 1].first;
        return -1;
    }

    int getMin()
    {
        if (cur_size > 0)
            return v[cur_size - 1].second;
        return -1;
        
    }
};