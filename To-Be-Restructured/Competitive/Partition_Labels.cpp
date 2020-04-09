//https://leetcode.com/problems/partition-labels/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> partitionLabels(string S)
{
    map<char, pair<int, int>> ht;
    for (int i = 0; i < S.length(); i++)
    {
        if (ht.count(S[i]))
            ht[S[i]] = {ht[S[i]].first, i};
        else
            ht[S[i]] = {i, i};
    }

    vector<int> ans;
    int i = 0;
    while (i < S.length())
    {
        int start = i;
        int end = ht[S[start]].second;

        for (int k = start; k < end && k < S.length(); k++)
        {
            end = max(end, ht[S[k]].second);
        }
        ans.push_back(end - start + 1);
        i = end + 1;
    }
    return ans;
}