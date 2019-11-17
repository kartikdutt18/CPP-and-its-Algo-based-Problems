//https://leetcode.com/contest/warm-up-contest/problems/first-unique-character-in-a-string/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        map<char, pair<int, int>> ht;
        int ans = INT_MAX;
        for (int i = 0; i < s.length(); i++)
        {
            if (ht.count(s[i]))
            {
                ht[s[i]] = {ht[s[i]].first, ht[s[i]].second + 1};
            }
            else
            {
                ht[s[i]] = {i, 1};
            }
        }
        for (auto i : ht)
        {
            if (i.second.second == 1)
                ans = min(ans, i.second.first);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};