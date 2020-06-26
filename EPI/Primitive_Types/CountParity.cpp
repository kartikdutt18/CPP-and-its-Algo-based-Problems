#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int Parity(int x)
{
  int count = 0;
  while (x)
  {
    count++;
    x = x & (x - 1);
  }
  return count&1;
}

int main()
{
  return 0;
}