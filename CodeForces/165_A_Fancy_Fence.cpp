#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;
    if (360 % (180 - n) == 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}