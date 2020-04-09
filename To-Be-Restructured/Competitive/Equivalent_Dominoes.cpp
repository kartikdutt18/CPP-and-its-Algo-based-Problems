//https://leetcode.com/contest/weekly-contest-146/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int numEquivDominoPairs(vector<vector<int>> &dominoes)
{
    map<pair<int, int>, int> ht;
    for (auto i : dominoes)
    {
        bool q1 = ht.count(pair(i[0], i[1])) || ht.count(pair(i[1], i[0]));
        if (!q1)
            ht.insert(make_pair(make_pair(i[0], i[1]), 1));
        else
        {
            if (ht.count(pair(i[0], i[1])))
                ht[pair(i[0], i[1])] += 1;
            else
                ht[pair(i[1], i[0])] += 1;
        }
    }
    int sum = 0;
    for (auto i : ht)
    {

        if (i.second != 1)
        {
            sum += (i.second) * (i.second - 1) / 2;
        }
    }

    return sum;
}