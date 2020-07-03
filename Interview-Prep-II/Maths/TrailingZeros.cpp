#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int trailingZeroes(int A)
{
  long long fives = 0;
  int num = 5;
  while (A / num)
  {
    fives += A / num;
    num *= 5;
  }
  return fives;
}

int main()
{
  return 0;
}