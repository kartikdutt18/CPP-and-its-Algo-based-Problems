//https://leetcode.com/problems/moving-average-from-data-stream/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class MovingAverage
{
    deque<int> d;
    int k;
    int cur_sum;
    int cur_size;
    double cur_avg;

public:
    /** Initialize your data structure here. */
    MovingAverage(int size)
    {
        k = size;
        cur_size = 0;
        cur_sum = 0;
    }

    double next(int val)
    {
        if (cur_size < k)
        {
            d.push_back(val);
            cur_sum += val;
            cur_size++;
            cur_avg = (double)cur_sum / cur_size;

            return cur_avg;
        }
        else
        {
            cur_sum -= d.front();
            d.pop_front();
            d.push_back(val);
            cur_sum += val;
            cur_avg = (double)cur_sum / k;
        }
        return cur_avg;
    }
};