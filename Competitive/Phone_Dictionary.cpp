//https://leetcode.com/problems/design-phone-directory/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class PhoneDirectory
{
    set<int> used;
    set<int> unused;

public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers)
    {
        for (int i = 0; i < maxNumbers; i++)
            unused.insert(i);
    }

    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get()
    {
        if (unused.size() == 0)
            return -1;
        auto t = *unused.begin();
        unused.erase(t);
        used.insert(t);
        return t;
    }

    /** Check if a number is available or not. */
    bool check(int number)
    {
        return unused.count(number);
    }

    /** Recycle or release a number. */
    void release(int number)
    {
        used.erase(number);
        unused.insert(number);
        return;
    }
};