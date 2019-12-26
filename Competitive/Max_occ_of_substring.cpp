//https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize)
    {
        unordered_map<string, int> ht;
        int ans = 0;
        for (int i = 0; i < s.length(); i++)
        {
            unordered_set<char> ch;

            for (int j = minSize; j <= maxSize && (i + j) <= s.length(); j++)
            {
                string t = s.substr(i, j);

                if (j == minSize)
                {
                    for (auto k : t)
                        ch.insert(k);
                }
                else
                {
                    ch.insert(t.back());
                }
                if (ch.size() > maxLetters)
                    break;

                ht[t] += 1;
                //cout<<ht[t]<<endl;
                ans = max(ans, ht[t]);
            }
        }

        return ans;
    }
};