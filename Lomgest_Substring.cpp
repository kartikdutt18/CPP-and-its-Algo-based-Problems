//https://leetcode.com/problems/longest-substring-without-repeating-characters/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    if (s.length() == 0)
        return 0;
    map<char, int> ht;
    int left = 0;
    int ans = INT_MIN;
    for (int i = 0; i < s.length(); i++)
    {
        if (ht.count(s[i]) && ht[s[i]] >= left)
        {
            left = ht[s[i]] + 1;
        }
        ht[s[i]] = i;
        ans = max(ans, i - left + 1);
    }
    return ans;
}