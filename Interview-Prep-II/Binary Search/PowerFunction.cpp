#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int myPow(long x, long n, long d)

{
  if (n == 0)
  {
    return 1;
  }
  if (n == 1)
  {
    return x % d;
  }
  if (n % 2 == 0)
  {
    return (myPow((x * x) % d, n / 2, d)) % d;
  }
  return (x % d) * (myPow((x * x) % d, n / 2, d)) % d;
}

int pow(int x, int n, int d)
{
  if (myPow(x, n, d) < 0)
  {
    return (myPow(x, n, d) + d) % d;
  }
  return myPow(x, n, d) % d;
}

int main()
{
  return 0;
}