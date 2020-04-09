//https://leetcode.com/contest/weekly-contest-170/problems/decrypt-string-from-alphabet-to-integer-mapping/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string freqAlphabets(string s)
{
    string ans = "";
    string alphabets = "abcdefghijklmnopqrstuvwxyz";
    map<string, char> ht;
    for (int i = 0; i < alphabets.length(); i++)
    {
        ht[to_string(i + 1)] = alphabets[i];
    }
    int i = 0;
    while (i < s.length())
    {
        if (i + 2 < s.length() && s[i + 2] == '#')
        {
            ans += ht[s.substr(i, 2)];
            i = i + 3;
        }
        else
        {
            string t = "";
            t += s[i];
            ans += ht[t];
            i++;
        }
    }
    return ans;
}