//https://leetcode.com/problems/arranging-coins/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int arrangeCoins(int n)
{
    return (long long)(sqrt(((double)n * 2 + 0.25)) - 0.5);
}