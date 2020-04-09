//https://leetcode.com/contest/weekly-contest-100/problems/orderly-queue/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Best Solution
class Solution
{
public:
    string orderlyQueue(string S, int K)
    {
        string ans = S;
        if (K == 1)
        {
            string temp = S + S;

            for (int i = 0; i <= temp.length() - S.length(); i++)
            {
                if (temp.substr(i, S.length()) < ans)
                {
                    ans = temp.substr(i, S.length());
                }
            }
        }

        else
        {
            sort(ans.begin(), ans.end());
        }
        return ans;
    }
};

class Solution
{
public:
    string orderlyQueue(string S, int K)
    {
        string ans = S;
        if (K == 1)
        {
            char curMin = 'z';
            for (int i = 0; i < S.length(); i++)
            {
                curMin = (curMin < S[i]) ? curMin : S[i];
            }
            vector<int> occMinChar;
            for (int i = 0; i < S.length(); i++)
            {
                if (S[i] == curMin)
                    occMinChar.emplace_back(i);
            }
            for (auto i : occMinChar)
            {
                string temp = S.substr(i) + S.substr(0, max(i, 0));
                ans = ans > temp ? temp : ans;
            }
        }

        else
        {
            sort(ans.begin(), ans.end());
        }
        return ans;
    }
};