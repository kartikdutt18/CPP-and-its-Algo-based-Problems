//https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/submissions/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> Generate_Freq(string chars)
{
    vector<int> freq(26, 0);
    for (auto i : chars)
        freq[i - 'a']++;
    return freq;
}
int countCharacters(vector<string> &words, string chars)
{
    vector<int> base = Generate_Freq(chars);
    int cnt = 0;
    for (auto str : words)
    {
        vector<int> temp = Generate_Freq(str);
        bool flag = true;
        for (auto j : str)
            flag &= (base[j - 'a'] >= temp[j - 'a']);
        if (flag)
        {
            cnt += str.length();
        }
    }
    return cnt;
}
