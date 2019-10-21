//https://leetcode.com/problems/binary-number-with-alternating-bits/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool hasAlternatingBits(int n)
{
    int alt = n & 1;
    n = n / 2;
    while (n > 0)
    {
        if (n % 2 == alt)
            return false;
        alt = n & 1;
        n = n >> 1;
    }
    return true;
}