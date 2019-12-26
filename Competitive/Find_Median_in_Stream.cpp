//https://leetcode.com/problems/find-median-from-data-stream/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class MedianFinder
{
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, less<int>> minQ;
    priority_queue<int, vector<int>, greater<int>> maxQ;
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (!minQ.empty() && num > minQ.top())
        {
            maxQ.push(num);
        }
        else
        {
            minQ.push(num);
        }
        rebalanceQueues();
    }

    double findMedian()
    {
        if (maxQ.empty() && minQ.empty())
            return 0.0;
        if (minQ.size() > maxQ.size() || maxQ.empty())
            return minQ.top();
        else if (minQ.size() < maxQ.size() || minQ.empty())
            return maxQ.top();

        return (minQ.top() + maxQ.top()) / 2.0;
    }

private:
    void rebalanceQueues()
    {
        if (minQ.size() + 1 < maxQ.size())
        {
            minQ.push(maxQ.top());
            maxQ.pop();
        }
        else if (maxQ.size() + 1 < minQ.size())
        {
            maxQ.push(minQ.top());
            minQ.pop();
        }
    }
};