//https://leetcode.com/contest/weekly-contest-175/problems/minimum-number-of-steps-to-make-two-strings-anagram/
#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Solution
{
public:
  int minSteps(string s, string t)
  {
    unordered_map<int, int> ht;
    for (auto i : s)
    {
      ht[i] += 1;
    }
    for (auto i : t)
    {
      if (ht.count(i))
      {
        ht[i] -= 1;
        if (ht[i] == 0)
        {
          ht.erase(i);
        }
      }
    }
    int ans = 0;
    for (auto i : ht)
      ans += i.second;

    return ans;
  }
};

int main() {

return 0;
}