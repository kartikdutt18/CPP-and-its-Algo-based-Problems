#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int repeatedNumber(const vector<int> &A)
{
  if (A.size() <= 1)
    return -1;
  int slow = A[0];
  int fast = A[A[0]];
  bool cycle = false;
  while (fast < A.size() && slow < A.size())
  {
    if (fast == slow)
    {
      cycle = true;
      break;
    }
    fast = A[fast];
    if (fast < A.size())
      fast = A[fast];
    else
      break;
    slow = A[slow];
  }
  if (!cycle)
    return -1;
  fast = 0;
  while (fast != slow)
  {
    fast = A[fast];
    slow = A[slow];
  }
  return fast;
}

int main()
{
  return 0;
}