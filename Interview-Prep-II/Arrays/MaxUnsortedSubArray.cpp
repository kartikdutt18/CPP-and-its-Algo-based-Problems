#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> subUnsort(vector<int> &A)
{
  if (A.size() == 0)
    return {-1};
  int minUnsortedElement = INT_MAX;
  bool isSorted = true;
  int maxElement = A[0];
  int endIndex = 0;
  for (int i = 1; i < A.size(); i++)
  {

    isSorted = isSorted & (A[i] >= maxElement);
    if (A[i] >= maxElement)
    {
      maxElement = max(maxElement, A[i]);
    }
    else
    {
      endIndex = max(i, endIndex);
      minUnsortedElement = min(minUnsortedElement, A[i]);
    }
  }
  if (isSorted)
    return {-1};
  int startIndex = 0;
  for (int i = 0; i < A.size(); i++)
  {
    if (A[i] > minUnsortedElement)
    {
      startIndex = i;
      break;
    }
  }
  return {startIndex, endIndex};
}

int main()
{
  return 0;
}