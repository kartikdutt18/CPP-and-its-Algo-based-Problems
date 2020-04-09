//https://leetcode.com/problems/find-k-length-substrings-with-no-repeated-characters/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int numKLenSubstrNoRepeats(string S, int K)
{
    map<char, int> last_occ;
    deque<char> q;
    int ans = 0;
    for (int i = 0; i < S.length(); i++)
    {

        if (!last_occ.count(S[i]))
        {
            last_occ[S[i]] = i;
        }
        else
        {
            while (q.front() != S[i])
            {
                char temp = q.front();
                q.pop_front();
                last_occ.erase(temp);
            }
            q.pop_front();
        }
        q.push_back(S[i]);
        if (q.size() > K)
        {
            char temp = q.front();
            q.pop_front();
            last_occ.erase(temp);
        }
        if (q.size() == K)
            ans++;
    }
    return ans;
}