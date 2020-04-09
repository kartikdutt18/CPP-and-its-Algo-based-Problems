//
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class HitCounter
{
    deque<int> d;

public:
    /** Initialize your data structure here. */
    HitCounter()
    {
    }

    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp)
    {

        d.push_back(timestamp);
    }

    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp)
    {
        while (d.empty() == false && (timestamp - d.front()) >= 300)
        {
            d.pop_front();
        }
        return d.size();
    }
};
