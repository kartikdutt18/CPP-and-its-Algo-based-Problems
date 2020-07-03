#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int isPower(int A)
{
  if (A == 1)
    return 1;
  for (int i = 2; i <= sqrt(A); i++)
  {
    if (A % i == 0)
    {
      double p = floor(1.0 * log(A) / log(i));

      if (pow(i, p) == A)
        return true;
    }
  }
  return false;
}

int main()
{
  return 0;
}