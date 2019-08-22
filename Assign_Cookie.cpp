//https://leetcode.com/problems/assign-cookies/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int findContentChildren(vector<int> &g, vector<int> &s)
{
    sort(g.begin(), g.end(), greater<int>());
    sort(s.begin(), s.end(), greater<int>());
    int i = 0;
    int j = 0;
    int content = 0;
    while (i < g.size() && j < s.size())
    {
        if (g[i] <= s[j])
        {
            j++;
            content++;
        }
        i++;
    }
    return content;
}