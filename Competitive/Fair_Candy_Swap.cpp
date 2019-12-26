//https://leetcode.com/problems/fair-candy-swap/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> fairCandySwap(vector<int> &A, vector<int> &B)
{
    int sum_a = 0, sum_b = 0;
    set<int> s;
    for (auto i : A)
    {
        sum_a += i;
        s.insert(i);
    }
    for (auto i : B)
        sum_b += i;
    float diff = sum_a - sum_b;
    diff = diff / 2;
    vector<int> ans;
    for (auto i : B)
    {
        if (s.count(diff + i))
        {
            ans.push_back(diff + i);
            ans.push_back(i);
            break;
        }
    }

    return ans;
}