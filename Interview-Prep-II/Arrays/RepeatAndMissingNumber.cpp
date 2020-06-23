#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> repeatedNumber(const vector<int> &A)
{
  long long sumOfSquares = 0;
  long long diff = 0;
  for (int i = 0; i < A.size(); i++)
  {
    diff = diff + A[i] - (i + 1);
    sumOfSquares = sumOfSquares + (long long)A[i] * A[i] - (long long)(i + 1) * (i + 1);
  }
  long long sum = sumOfSquares / diff;
  long long a = (diff + sum) / 2;
  long long b = sum - a;
  return {a, b};
}


int main()
{
  return 0;
}