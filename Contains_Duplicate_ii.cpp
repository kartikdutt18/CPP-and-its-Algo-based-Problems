//https://leetcode.com/problems/contains-duplicate-ii/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    map<int, vector<int>> ht;
    int j = 0;
    for (auto i : nums)
    {
        if (ht.count(i))
        {
            ht[i].push_back(j);
        }
        else
        {

            ht[i] = {j};
        }
        j++;
    }
    for (auto i : ht)
    {

        if (i.second.size() >= 2)
        {

            for (int j = 1; j < i.second.size(); j++)
            {
                if ((i.second[j] - i.second[j - 1]) <= k)
                    return true;
            }
        }
    }
    return false;
}