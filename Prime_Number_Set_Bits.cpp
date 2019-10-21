//https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int count_bits(int n)
    {
        int ans = 0;
        while (n)
        {
            n = n & (n - 1);
            ans++;
        }
        return ans;
    }
    int countPrimeSetBits(int L, int R)
    {
        set<int> ht = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61};
        int ans = 0;
        for (int i = L; i <= R; i++)
        {
            int bits = count_bits(i);
            if (ht.count(bits))
                ans++;
        }
        return ans;
    }
};