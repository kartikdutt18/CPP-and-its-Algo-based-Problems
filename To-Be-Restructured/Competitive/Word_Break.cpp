//https://leetcode.com/problems/word-break/submissions/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool wordBreak(string s, vector<string> &wordDict)
{
    set<string> ht;
    for (auto i : wordDict)
        ht.insert(i);
    int i = 0;
    int start = 0;
    vector<bool> dp(s.length() + 1, 0);
    dp[0] = true;
    for (int i = 1; i <= s.length(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (ht.count(s.substr(j, i - j)) && dp[j])
            {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[s.length()];
}