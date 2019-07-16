//https://leetcode.com/problems/letter-case-permutation/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void addLetter(string S, int index, vector<string> &strs)
{
    strs.push_back(S);
    for (int i = index; i < S.size(); ++i)
    {
        int convert = 0;
        if (S[i] >= 'a' && S[i] <= 'z')
        {
            convert = -32;
        }
        else if (S[i] >= 'A' && S[i] <= 'Z')
        {
            convert = 32;
        }

        if (convert != 0)
        {
            S[i] += convert;
            addLetter(S, i + 1, strs);
            S[i] -= convert;
        }
    }
}
vector<string> letterCasePermutation(string S)
{
    vector<string> strs;
    addLetter(S, 0, strs);
    return strs;
}