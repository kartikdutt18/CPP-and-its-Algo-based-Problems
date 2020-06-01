#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
  ll n, m, k;
  cin >> n >> m >> k;
  vector<ll> arr(n, 0), prefixSum(n+1, 0);
  for (int i = 0; i < n; i++, cin>>arr[i]);
  for(int i = 0; i < m; i++)
  {
    ll l, r, d;
    cin >> l >> r >> d;
    prefixSum[l]+=d;
    prefixSum[r+1]-=d;
  }
  vector<ll> queries(n+2);
  
  cout << endl;
  return;
}

int main()
{
  solve();
  return 0;
}