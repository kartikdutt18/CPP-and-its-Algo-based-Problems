//https://leetcode.com/problems/reverse-words-in-a-string/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
    pyhton3 solution:
    
    Simpler
    
    class Solution:
    def reverseWords(self, s: str) -> str:
        s=s.split()
        s.reverse()
        return ' '.join(s)

*/

string cleanstring(string S)
{

    for (int i = 0; i < S.length() - 1; i++)
    {
        if (S[i] == ' ')
        {
            int j = i + 1;
            while (j < S.length() && S[j] == ' ')
                j++;
            S = S.substr(0, i) + ' ' + S.substr(j, S.length() - j);
        }
    }
    return S;
}
string reverseWords(string s)
{
    if (s.length() == 0)
        return s;

    s = cleanstring(s);
    if (s[0] == ' ')
        s.erase(0, 1);
    if (s.back() == ' ')
        s.erase(s.length() - 1, 1);
    reverse(s.begin(), s.end());
    int i = 0;
    int prev = 0;
    while (i != s.length())
    {
        if (s[i] == ' ')
        {
            reverse(s.begin() + prev, s.begin() + i);
            prev = i + 1;
        }
        i++;
    }
    reverse(s.begin() + prev, s.begin() + i);
    return s;
}
