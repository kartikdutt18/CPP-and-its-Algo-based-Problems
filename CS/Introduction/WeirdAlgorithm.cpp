#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  ll n;
  cin >> n;
  while (n != 1)
  {
    cout << n << " ";
    if (n&1)
      n = n * 3 + 1;
    else
      n = n / 2;
  }
  cout << n << endl;
  return 0;
}