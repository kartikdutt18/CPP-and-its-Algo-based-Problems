#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> v(n, 0);
  for(int i = 0; i < n; i++)
  {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  ll ans = 0;
  for(int i = 0; i < n; i++)
  {
    ans += abs(i + 1 - v[i]);
  }
  cout << ans << endl;
  return 0;
}