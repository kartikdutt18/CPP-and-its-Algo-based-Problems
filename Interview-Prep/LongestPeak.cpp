#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int longestPeak(vector<int> array)
{
  if (array.size() == 0)
    return 0;
  bool checkIncreasing = true;
  int maxLen = 0;
  int curIncreasingLen = 0;
  int curDecreasingLen = 0;
  for (int i = 1; i < array.size(); i++)
  {
    if (checkIncreasing)
    {
      if (array[i] > array[i - 1])
      {
        curIncreasingLen++;
      }
      else if (array[i] < array[i - 1])
      {
        checkIncreasing = false;
        curDecreasingLen = 1;
        if (curIncreasingLen > 0)
          maxLen = max(maxLen, curDecreasingLen + curIncreasingLen + 1);
      }
      else
      {
        curIncreasingLen = 0;
        curDecreasingLen = 0;
      }
    }
    else
    {
      if (array[i] < array[i - 1])
      {
        curDecreasingLen++;
        if (curIncreasingLen > 0)
          maxLen = max(maxLen, curDecreasingLen + curIncreasingLen + 1);
      }
      else if (array[i] > array[i - 1])
      {
        curIncreasingLen = 1;
        curDecreasingLen = 0;
        checkIncreasing = true;
      }
      else
      {
        curIncreasingLen = 0;
        curDecreasingLen = 0;
      }
    }
  }
  return maxLen;
}

int main()
{
  return 0;
}