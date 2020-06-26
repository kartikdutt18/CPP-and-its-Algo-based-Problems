#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int repeatedNumber(const vector<int> &A)
{

  unordered_map<int, int> ht;
  for (int i = 0; i < A.size(); i++)
  {
    if (ht.count(A[i]))
    {
      ht[A[i]]++;
    }
    else
    {
      if (ht.size() >= 3)
      {
        // ht.erase(A[i - 2]);
        int minFreq = INT_MAX;
        int minElem = 0;
        for (auto pp : ht)
        {
          if (pp.second < minFreq)
          {
            minFreq = pp.second;
            minElem = pp.first;
          }
        }
        ht.erase(minElem);
      }
      ht.insert({A[i], 1});
    }
  }
  for (auto i : ht)
  {
    ht[i.first] = 0;
  }
  for (int i = 0; i < A.size(); i++)
  {
    if (ht.count(A[i]))
      ht[A[i]]++;
  }
  for (auto i : ht)
  {
    if (i.second > (A.size()) / 3)
      return i.first;
  }
  return -1;
}

int main()
{
  return 0;
}