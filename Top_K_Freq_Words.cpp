//https://leetcode.com/problems/top-k-frequent-words/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;



vector<string> topKFrequent(vector<string> &words, int k)
{
    map<string, int> ht;
    auto compare=[&](string s1,string s2){return ht[s1]<ht[s2];};

    priority_queue<string, vector<string>, decltype(compare)> pq(compare);
    for(auto i:words){
        ht[i]++;
        if(pq.size()<k){
            pq.push(i);
        }
        else if(ht[pq.top()]<ht[i]){
            pq.pop();
            pq.push(i);
        }
    }
    vector<string> ans;
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

//Partial Sort

vector<string> topKFrequent(vector<string> &words, int k)
{
    unordered_map<string_view, int> f;
    for (auto &w : words)
        ++f[w];

    vector<pair<string_view, int>> v(f.begin(), f.end());
    partial_sort(v.begin(), v.begin() + k, v.end(), [](auto &a, auto &b) {
        return a.second > b.second || (a.second == b.second && a.first < b.first);
    });
    vector<string> res(k);
    transform(v.begin(), v.begin() + k, res.begin(), [](auto &p) { return string(p.first); });
    return res;
}