//https://leetcode.com/problems/relative-sort-array/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
{
    if (arr2.size() == 0)
    {
        sort(arr1.begin(), arr1.end());
        return arr1;
    }
    map<int, int> ht;
    for (auto i : arr1)
    {
        if (ht.count(i))
        {
            ht[i] = ht[i] + 1;
        }
        else
        {
            ht.insert(make_pair(i, 1));
        }
    }
    vector<int> ans;
    for (auto i : arr2)
    {
        while (ht[i])
        {
            ans.push_back(i);
            ht[i]--;
        }
        ht.erase(i);
    }
    if (!ht.empty())
    {
        for (auto i : ht)
        {
            cout << i.first << " ";
            while (i.second)
            {
                ans.push_back(i.first);
                i.second--;
            }
        }
    }
    return ans;
}