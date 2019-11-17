//https://leetcode.com/problems/smallest-common-region/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string findSmallestRegion(vector<vector<string>> &regions, string region1, string region2)
    {
        if (regions.size() == 0)
            return "";
        map<string, string> ht;
        for (auto i : regions)
        {
            for (int j = i.size() - 1; j > 0; j--)
            {
                ht[i[j]] = i[0];
            }
        }
        set<string> parent;
        while (ht.count(region1))
        {
            parent.insert(region1);
            region1 = ht[region1];
        }
        parent.insert(regions[0][0]);
        while (ht.count(region2))
        {
            if (parent.count(region2))
            {
                return region2;
            }
            region2 = ht[region2];
        }

        return regions[0][0];
    }
};