//https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool canThreePartsEqualSum(vector<int> &A)
{
    int ts = 0;
    for (auto i : A)
        ts += i;
    if (ts % 3)
        return false;
    int rs = ts / 3;
    int cs = 0;
    int cnt = 0;
    for (auto i : A)
    {
        cs += i;
        if (cs == rs)
        {
            cs = 0;
            cnt++;
        }
    }
    return cs == 0 && cnt == 3;
}