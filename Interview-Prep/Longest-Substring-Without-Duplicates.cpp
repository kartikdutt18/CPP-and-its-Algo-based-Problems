#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

string longestSubstringWithoutDuplication(string str)
{
  unordered_map<char, int> lastSeen;
  int start = 0, maxStart = 0, maxEnd = 0;
  for (int i = 0; i < str.length(); i++)
  {
    if (lastSeen.count(str[i]))
    {
      start = max(lastSeen[str[i]] + 1, start);
    }
    if ((i - start) > (maxEnd - maxStart))
    {
      maxEnd = i;
      maxStart = start;
    }
    lastSeen[str[i]] = i;
  }
  return str.substr(maxStart, maxEnd - maxStart + 1);
}

int main()
{
  return 0;
}