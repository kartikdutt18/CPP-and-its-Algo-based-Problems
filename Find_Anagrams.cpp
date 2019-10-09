//https://leetcode.com/problems/find-all-anagrams-in-a-string/submissions/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> findAnagrams(string s, string p)
{
    vector<int> anagram_freq(26, 0);
    for (auto i : p)
        anagram_freq[i - 'a']++;
    vector<int> freq(26, 0);
    deque<char> dq;
    vector<int> ans;
    for (int i = 0; i < s.length(); i++)
    {
        if(dq.size()==p.length())
        {
            freq[dq.front() - 'a']--;
            dq.pop_front();
            
        }
        dq.push_back(s[i]);
        freq[s[i] - 'a']++;
        if (freq == anagram_freq && dq.size() == p.length())
        {
            ans.push_back(i - p.length() + 1);
        }
    }
    return ans;
}