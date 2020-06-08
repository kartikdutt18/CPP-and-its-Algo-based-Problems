#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.length() == 0)
            return 0;
        unordered_map<char, int> lastSeen;
        int maxLength = 1;
        int lastStartIndex = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (lastSeen.count(s[i]))
            {
                lastStartIndex = max(lastStartIndex, lastSeen[s[i]] + 1);
            }
            lastSeen[s[i]] = i;
            maxLength = max(maxLength, i - lastStartIndex + 1);
        }
        return maxLength;
    }
};

int main()
{
  return 0;
}