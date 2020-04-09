//
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Logger
{
    map<string, int> ht;

public:
    /** Initialize your data structure here. */
    Logger()
    {
    }

    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message)
    {
        if (!ht.count(message))
        {
            ht[message] = timestamp;
            return true;
        }
        if (timestamp - ht[message] >= 10)
        {
            ht[message] = timestamp;
            return true;
        }
        return false;
    }
};