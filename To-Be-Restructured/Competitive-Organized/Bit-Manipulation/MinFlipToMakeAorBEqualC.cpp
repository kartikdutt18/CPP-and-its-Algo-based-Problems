//https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minFlips(int a, int b, int c)
    {
        int getc = (a | b) ^ c;
        bitset<64> as(a);
        bitset<64> bs(b);
        bitset<64> cs(getc);
        bitset<64> cw(c);
        int ans = 0;
        for (int i = 0; i < 64; i++)
        {
            if (cs[i])
            {
                ans += (as[i] + bs[i]) * (1 - cw[i]) + (cw[i]);
            }
        }
        return ans;
    }
};