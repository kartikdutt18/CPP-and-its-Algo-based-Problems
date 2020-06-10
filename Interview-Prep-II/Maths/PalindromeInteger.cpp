#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int Reverse(int A)
{
  if (A < 0)
    return -Reverse(abs(A));
  ll num = 0;
  int temp = A;
  while (temp)
  {
    num = num * 10 + (temp % 10);
    temp = temp / 10;
  }
  if (num > INT_MAX)
    return 0;
  return (int)num;
}

int main()
{
  return 0;
}