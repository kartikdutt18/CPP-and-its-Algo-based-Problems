//https://leetcode.com/contest/biweekly-contest-15/problems/iterator-for-combination/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class CombinationIterator
{
    string s;
    set<string> v;
    vector<string> ht;
    int i;

public:
    CombinationIterator(string characters, int combinationLength)
    {
        s = characters;
        create_combination("", combinationLength, 0);
        for (auto i : v)
        {
            ht.push_back(i);
        }
        i = 0;
    }
    void create_combination(string comb, int k, int j)
    {
        if (k == 0)
        {
            v.insert(comb);
            return;
        }
        for (int i = j; i < s.length(); i++)
        {
            comb += s[i];
            create_combination(comb, k - 1, i + 1);
            comb.pop_back();
        }
        return;
    }

    string next()
    {
        if (i < ht.size())
        {
            string t = ht[i];
            i++;
            return t;
        }
        return "";
    }

    bool hasNext()
    {
        return i < ht.size();
    }
};