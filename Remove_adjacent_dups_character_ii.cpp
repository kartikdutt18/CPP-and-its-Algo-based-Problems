//https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Cleanest Code
string removeDuplicates(string s, int k)
{
    stack<pair<char, int>> v;
    string ans = "";
    v.emplace(make_pair('0', 0));
    for (auto i : s)
    {
        if (v.top().first == i && v.top().second + 1 >= k)
        {

            while (!v.empty() && v.top().first == i)
            {
                v.pop();
                ans.pop_back();
            }
        }
        else
        {
            v.emplace(make_pair(i, v.top().second * (v.top().first == i) + 1));
            ans += i;
        }
    }

    return ans;
}
// Using 2 Pass -Single Pass at the bottom
string removeDuplicates(string s, int k)
{
    stack<pair<char, int>> v;
    for (auto i : s)
    {
        if (v.empty())
            v.emplace(make_pair(i, 1));
        else if (v.top().first == i)
        {
            if (v.top().second + 1 >= k)
            {
                while (!v.empty() && v.top().first == i)
                    v.pop();
            }
            else
                v.emplace(make_pair(i, v.top().second + 1));
        }
        else
        {
            v.emplace(make_pair(i, 1));
        }
    }
    string ans = "";
    while (!v.empty())
    {
        ans += v.top().first;
        v.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

//In Single Pass

class Solution
{
public:
    string removeDuplicates(string s, int k)
    {
        stack<pair<char, int>> v;
        string ans = "";
        for (auto i : s)
        {
           
            if (v.top().first == i && v.top().second + 1 >= k && !v.empty())
            {
                
                while (!v.empty() && v.top().first == i)
                {
                    v.pop();
                    ans.pop_back();
                }
                
                
            }
            else
            {
                v.emplace(make_pair(i, v.top().second*(!v.empty() && v.top().first==i)+1));
                ans.push_back(i);
            }
        }

        return ans;
    }
};