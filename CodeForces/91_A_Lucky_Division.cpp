#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  ll n;
  cin >> n;
  queue<ll> q;
  q.push(4);
  q.push(7);
  while(!q.empty())
  {
    ll cur = q.front();
    q.pop();
    if (n % cur == 0)
    {
      cout << "YES\n";
      return 0;
    }
    if (cur * 10 + 4 <= n)
      q.push(cur * 10 + 4);
    if (cur * 10 + 7 <= n)
      q.push(cur * 10 + 7);
  }
  cout << "NO\n";
  return 0;
}