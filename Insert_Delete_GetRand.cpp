//https://leetcode.com/problems/insert-delete-getrandom-o1/submissions/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class RandomizedSet
{
    unordered_map<int, int> ht;
    vector<pair<bool, int>> v;

public:
    /** Initialize your data structure here. */
    RandomizedSet()
    {
        srand(51);
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        if (ht.count(val))
            return false;
        v.push_back({true, val});
        ht[val] = v.size() - 1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        if (ht.count(val))
        {
            v[ht[val]].first = false;
            ht.erase(val);
            return true;
        }
        return false;
    }

    /** Get a random element from the set. */
    int getRandom()
    {
        if (ht.size() == 0)
            return -1;
        int cnt = rand() % v.size();
        while (!v[cnt].first)
            cnt = rand() % v.size();
        return v[cnt].second;
    }
};