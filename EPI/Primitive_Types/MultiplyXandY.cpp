#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

void multiply(int x, int y)
{
  int sum = 0;
  while (x)
  {
    if (x & 1)
      sum = ((sum ^ y) | (sum & y));
    x = x >> 1;
    y = y << 1;
  }
  cout << sum << endl;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int a, b;
    cin >> a >> b;
    multiply(a, b);
  }
  return 0;
}