#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int solve(int x, int i, int j)
{
  int xorBits = ((x >> i) & 1) ^ ((x >> j) & 1);
  x = x ^ (xorBits << i);
  x = x ^ (xorBits << j);
  cout << x << endl;
  return x;
}

int AlteranteSolution(int x, int i, int j)
{
  int xorBits = ((x >> i) & 1) ^ ((x >> j) & 1);
  if (xorBits != 0)
  {
    unsigned long bit_mask = (1 << i) | (1 << j);
    x = x ^ bit_mask;
  }
  cout << x << endl;
  return x;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int x, i, j;
    cin >> x >> i >> j;
    cout << "SOLUTION 1: ";
    solve(x, i, j);
    cout << "SOLUTION 2 : ";
    AlteranteSolution(x, i, j);
    cout << "------\n";
  }
  return 0;
}