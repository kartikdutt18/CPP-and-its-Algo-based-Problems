#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

using namespace std;

int longestPeak(vector<int> array)
{
  if (!array.size())
    return 0;
  int i = 1;
  int longestPeak = 0;
  while (i < (array.size() - 1))
  {
    bool isPeak = array[i] > array[i - 1] && array[i] > array[i + 1];
    if (!isPeak)
    {
      i++;
      continue;
    }
    int left = i - 2;
    while (left >= 0 && array[left] < array[left + 1])
      left--;
    int right = i + 2;
    while (right < array.size() && array[right] < array[right - 1])
      right++;
    int curLen = right - left - 1;
    longestPeak = max(longestPeak, curLen);
    i = right;
  }
  return longestPeak;
}


int main()
{
  return 0;
}