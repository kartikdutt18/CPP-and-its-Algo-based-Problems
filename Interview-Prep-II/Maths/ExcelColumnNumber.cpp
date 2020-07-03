#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int titleToNumber(string A)
{
  int ans = 0;
  for (char ch : A)
  {
    ans = ans * 26 + (ch - 'A' + 1);
  }
  return ans;
}

int main()
{
  return 0;
}