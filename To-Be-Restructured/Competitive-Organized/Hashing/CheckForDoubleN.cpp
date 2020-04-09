//https://leetcode.com/contest/weekly-contest-175/problems/check-if-n-and-its-double-exist/
#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Solution
{
public:
  bool checkIfExist(vector<int> &arr)
  {
    map<int, int> ht;
    for (auto i : arr)
    {
      ht[i] += 1;
    }
    for (auto i : ht)
    {

      if (ht.count(2 * i.first))
      {
        if (i.first == 0 && i.second <= 1)
          continue;
        else
          return true;
      }
    }
    return false;
  }
};

int main() {

return 0;
}