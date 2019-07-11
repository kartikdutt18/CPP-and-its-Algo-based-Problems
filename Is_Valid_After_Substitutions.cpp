//https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string removeabc(string s)
{
    if (s.length() <= 2)
        return s;
    if (s.length() == 3 && s == "abc")
        return "";
    string ret = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s.substr(i, 3) == "abc")
        {
            i += 2;
        }
        else
        {
            string g(1, s[i]);
            ret += g;
        }
    }
    cout << ret;
    return ret;
}
bool isValid(string S)
{
    string s1 = removeabc(S);
    if (s1.length() == 0)
        return true;
    string g = removeabc(s1);
     return g.length() == 0 or g == "abc";
}