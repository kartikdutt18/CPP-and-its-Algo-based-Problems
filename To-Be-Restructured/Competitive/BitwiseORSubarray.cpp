//https://leetcode.com/problems/bitwise-ors-of-subarrays
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int subarrayBitwiseORs(vector<int> &A)
    {
        set<int> prev;
        set<int> cur;
        prev.insert(0);
        for (auto i : A)
        {
            set<int> curS;
            for (auto j : prev)
            {
                curS.insert(j | i);
            }
            curS.insert(i);
            prev = curS;
            for (auto k : curS)
                cur.insert(k);
        }
        return cur.size();
    }
};