#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(int num)
{
  const int numBits = sizeof(num) * 8;
  for (int i = 0; i < numBits; i++)
  {
    if (((num >> i)&1) != ((num >>(i + 1))&1))
    {
      num = num ^ (1 << i | 1 << (i + 1));
      cout << num << endl;
      return;
    }
  }
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    solve(n);
  }
  return 0;
}