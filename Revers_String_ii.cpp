//https://leetcode.com/problems/reverse-words-in-a-string-ii/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void reverseWords(vector<char> &s)
    {
        reverse(s.begin(), s.end());
        int prev = 0;
        int i = 0;
        for (; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                reverse(s.begin() + prev, s.begin() + i);
                prev = i + 1;
            }
        }
        reverse(s.begin() + prev, s.begin() + i);
        return;
    }
};