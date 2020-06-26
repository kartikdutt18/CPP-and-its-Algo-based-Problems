#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int firstMissingPositive(vector<int> &A)
{
  for (int i = 0; i < A.size();)
  {
    if (A[i] > 0 && A[i] - 1 < A.size() && A[i] != i + 1 && (i > 0 && A[i] != A[i - 1]))
      swap(A[A[i] - 1], A[i]);
    else
      i++;
  }
  for (int i = 0; i < A.size(); i++)
  {
    if (A[i] != i + 1)
      return i + 1;
  }
  return A.size() + 1;
}

int main()
{
  return 0;
}