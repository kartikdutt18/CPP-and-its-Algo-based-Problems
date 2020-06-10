#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> maxset(vector<int> &A)
{
  long long maxSum = INT_MIN;
  long long curSum = 0;
  int startIndex = 0;
  int endIndex = 0;
  int curStartIndex = 0;
  int curEndIndex = 0;
  for (int num : A)
  {
    if (num < 0)
    {
      curStartIndex = curEndIndex + 1;
      curSum = 0;
      curEndIndex++;
      continue;
    }
    curSum += num;
    if (curSum == maxSum &&
        (curEndIndex - curStartIndex) > (endIndex - startIndex))
    {
      startIndex = curStartIndex;
      endIndex = curEndIndex;
    }
    else if (curSum > maxSum)
    {
      startIndex = curStartIndex;
      endIndex = curEndIndex;
      maxSum = curSum;
    }
    curEndIndex++;
  }
  if (maxSum < 0)
    return vector<int>();
  vector<int> v;
  for (int i = startIndex; i <= endIndex; i++)
    v.push_back(A[i]);
  return v;
}

int main()
{
  return 0;
}