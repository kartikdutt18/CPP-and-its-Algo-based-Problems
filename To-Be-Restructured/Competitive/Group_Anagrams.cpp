//https : //leetcode.com/problems/group-anagrams/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    map<vector<int>,vector<string>> ht;
    for(auto i:strs){
        vector<int> v(27,0);
        for(auto j:i){
            v[j-'a']++;
        }
        ht[v].push_back(i);
    }
    vector<vector<string>> ans;
    for (auto i : ht)
    {
        ans.push_back(i.second);
    }
    return ans;
}