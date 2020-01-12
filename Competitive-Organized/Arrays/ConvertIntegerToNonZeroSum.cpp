//https://leetcode.com/contest/weekly-contest-171/problems/convert-integer-to-the-sum-of-two-no-zero-integers/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool contains_zero(int n)
    {
        while (n)
        {
            if (n % 10 == 0)
                return true;
            n = n / 10;
        }
        return false;
    }
    vector<int> getNoZeroIntegers(int n)
    {
        vector<int> ans = {1, n - 1};
        while (contains_zero(ans[0]) || contains_zero(ans[1]))
        {
            ans[0] += 1;
            ans[1] -= 1;
        }
        return ans;
    }
};