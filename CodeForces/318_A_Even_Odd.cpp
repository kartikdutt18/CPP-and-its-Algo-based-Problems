#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  ll n, k;
  cin >> n >> k;
  if (k <= (n + 1) / 2)
  {
    cout << k * 2 - 1 << endl;
  }
  else
  {
    cout << (k - (n + 1) / 2) * 2 << endl;
  }
  return 0;
}